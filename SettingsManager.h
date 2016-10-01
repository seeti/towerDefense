#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <fstream>

#pragma once
class SettingsManager
{
private:
	template <typename T> std::string convertirPrimitivaToString(T const &val);
	template <typename T> T convertirStringToPrimitiva(std::string const &val);
	std::string convertirStringToPrimitiva(std::string const &val);
	
	std::string fileName;
	std::map<std::string, std::string> contents;

	void exitWithError(const std::string &error);
	void removeComment(std::string &line) const;
	bool onlyWhiteSpace(const std::string &line) const;
	bool validLine(const std::string &line) const;

	void extractKey(std::string &key, size_t const &sepPos, const std::string &line) const;
	void extractValue(std::string &value, size_t const &sepPos, const std::string &line) const;

	void extractContents(const std::string &line);
	void parseLine(const std::string &line, size_t const lineNo);

	void extractKeys();
	
public:
	bool keyExists(const std::string &key) const;
	template <typename ValueType> ValueType getValueOfKey(const std::string &key, ValueType const &defaultValue = ValueType()) const;

	SettingsManager(const std::string &fileName);
	~SettingsManager();
};

