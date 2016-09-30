#pragma once

/*
* UniqueID
*/
class UID
{
private:
	unsigned int uid;
protected:
	unsigned int getNextUID();
public:
	UID();
	UID(unsigned int _uid);
	~UID();
	unsigned int toInt();
};

