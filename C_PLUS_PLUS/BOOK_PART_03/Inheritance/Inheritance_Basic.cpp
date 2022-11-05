#include <iostream>
using namespace std;

class Person
{
private:
	int age;
	char name[50];
public:
	Person(int myage, char * myname) : age(myage)
	{
		strcpy_s(name, strlen(myname) + 1, myname);
	}
	void WhatYourName() const
	{
		cout << "My name is " << name << endl;
	}
	void HowOldAreYou() const
	{
		cout << "I'm " << age << " years old" << endl;
	}
};

class UnivStudent : public Person
{
private:
	char major[50];
public:
	UnivStudent(char * myname, int myage, char * mymajor) : Person(myage, myname)	// 자기 자신의 생성자를 호출한다고 보면 된다. 변수가 없는 이유.. 10행에 Person() 생성자를 갖고 있는 거다.
	{

		strcpy_s(major, strlen(mymajor) + 1, mymajor);
	}
	void WhoAreYou() const
	{
		WhatYourName();
		HowOldAreYou();
		cout << "My major is " << major << endl << endl;
	}
};

int InheritanceBasic()
{
	UnivStudent n("PSY", 28, "Computer");
	n.WhoAreYou();

	UnivStudent n2("YSP", 38, "SW, Computer");
	n2.WhoAreYou();

	return 0;
}