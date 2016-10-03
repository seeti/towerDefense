#include "SettingsManager.h"

// Método para convertir T, que debería ser una primitiva (int, float, double...) a std::string
template <typename T>
std::string SettingsManager::convertirPrimitivaToString(T const &val)
{
	std::ostringstream ostr;
	ostr << val;

	return ostr.str();
}

// Método para convertir una std::string a T
template <typename T>
T SettingsManager::convertirStringToPrimitiva(std::string const &val)
{
	std::istringstream istr(val);
	T returnVal;
	if (!(istr >> returnVal)) this->exitWithError("CFG: Not a valid " + (std::string)typeid(T).name() + " received!\n");

	return returnVal;
}

template <> std::string SettingsManager::convertirStringToPrimitiva(std::string const &val)
{
	return val;
}

void SettingsManager::exitWithError(const std::string &error)
{
	std::cout << error;
	std::cin.ignore();
	std::cin.get();

	exit(EXIT_FAILURE);
}

void SettingsManager::removeComment(std::string &line) const
{
	if (line.find(';') != line.npos)
		line.erase(line.find(';'));
}

bool SettingsManager::onlyWhiteSpace(const std::string &line) const
{
	return (line.find_first_not_of(' ') == line.npos);
}

bool SettingsManager::validLine(const std::string &line) const
{
	std::string temp = line;
	temp.erase(0, temp.find_first_not_of("\t "));
	if (temp[0] == '=')
		return false;

	for (size_t i = temp.find('=') + 1; i < temp.length(); i++)
		if (temp[i] == ' ')
			return true;

	return false;
}

void SettingsManager::extractKey(std::string &key, size_t const &sepPos, const std::string &line) const
{
	key = line.substr(0, sepPos);
	if (key.find('\t') != line.npos || key.find(' ') != line.npos)
		key.erase(key.find_first_of("\t "));
}

void SettingsManager::extractValue(std::string &value, size_t const &sepPos, const std::string &line) const
{
	value = line.substr(sepPos + 1);
	value.erase(0, value.find_first_not_of("\t "));
	value.erase(value.find_last_not_of("\t ") + 1);
}

void SettingsManager::extractContents(const std::string &line)
{
	std::string temp = line;
	// Erase leading whitespace from the line.
	temp.erase(0, temp.find_first_not_of("\t "));
	size_t sepPos = temp.find('=');

	std::string key, value;
	this->extractKey(key, sepPos, temp);
	this->extractValue(value, sepPos, temp);

	if (!keyExists(key))
		this->contents.insert(std::pair<std::string, std::string>(key, value));
	else
		this->exitWithError("CFG: Can only have unique key names!\n");
}

// lineNo = the current line number in the file.
// line = the current line, with comments removed.
void SettingsManager::parseLine(const std::string &line, size_t const lineNo)
{
	if (line.find('=') == line.npos)
		this->exitWithError("CFG: Couldn't find separator on line: " + this->convertirPrimitivaToString(lineNo) + "\n");

	if (!validLine(line))
		this->exitWithError("CFG: Bad format for line: " + this->convertirPrimitivaToString(lineNo) + "\n");

	this->extractContents(line);
}

void SettingsManager::extractKeys()
{
	std::ifstream file;
	file.open(this->fileName.c_str());
	if (!file)
		this->exitWithError("CFG: File " + this->fileName + " couldn't be found!\n");

	std::string line;
	size_t lineNo = 0;
	while (std::getline(file, line))
	{
		lineNo++;
		std::string temp = line;

		if (temp.empty())
			continue;

		this->removeComment(temp);
		if (this->onlyWhiteSpace(temp))
			continue;

		this->parseLine(temp, lineNo);
	}

	file.close();
}

bool SettingsManager::keyExists(const std::string &key) const
{
	return this->contents.find(key) != this->contents.end();
}

/* OJO! Este método da errores y tiene que ser revisado
 *
template <typename ValueType>
ValueType SettingsManager::getValueOfKey(const std::string &key, ValueType const &defaultValue) const
{
	if (!this->keyExists(key))
		return defaultValue;

	return this->convertirStringToPrimitiva<ValueType>(this->contents.find(key)->second);
}
*/

int SettingsManager::getIntValueOfKey(const std::string &key, const int &defaultValue)
{
	if (!this->keyExists(key))
		return defaultValue;

	return std::stoi(this->contents.find(key)->second);
}

std::string SettingsManager::getStringValueOfKey(const std::string &key, const std::string &defaultValue)
{
	if (!this->keyExists(key))
		return defaultValue;

	return this->contents.find(key)->second;
}

void SettingsManager::open(const std::string &fileName)
{
	this->fileName = fileName;
	this->extractKeys();
}

SettingsManager::SettingsManager()
{
}

SettingsManager::SettingsManager(const std::string &fileName)
{
	this->open(fileName);
}

SettingsManager::~SettingsManager()
{
}
