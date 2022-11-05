#include <iostream>
#include <cstring>
using namespace std;

class c1020
{
private:
	char* name;
public:
	c1020(char* myname)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy_s(name, len, myname);
	}
	~c1020()
	{
		delete[] name;
	}
	void WhatYourName() const
	{
		cout << "My name is " << name << endl;
	}
};

class UnivStudent2 : public c1020
{
private:
	char* major;
public:
	UnivStudent2(char* myname, char* mymajor) : c1020(myname)
	{
		int len = strlen(mymajor) + 1;
		major = new char[len];
		strcpy_s(major, len, mymajor);
	}
	~UnivStudent2()
	{
		delete[] major;
	}
	void WhoAreYou() const
	{
		WhatYourName();
		cout << "My major is " << major << endl << endl;
	}
};

int DestModel()
{
	UnivStudent2 st1("Kim", "mathematics");
	st1.WhoAreYou();
	UnivStudent2 st2("PSY", "Computer");
	st2.WhoAreYou();

	return 0;
}