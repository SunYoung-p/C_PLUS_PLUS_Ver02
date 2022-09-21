#include <iostream>
#include <cstring>
#include "NameCard.h"
using namespace std;

class Person
{
private:
	char * name;
	int age;
public:
	Person(char *myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy_s(name, len, myname);
		age = myage;
	}

	Person(Person &p1)
	{
		int len = strlen(p1.name) + 1;
		name = new char[len];
		strcpy_s(name, len, p1.name);
		age = p1.age;
	}

	void ShowPersonInfo() const
	{
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;
	}
	~Person()
	{
		delete[] name;
		cout << "called destructor !" << endl;
	}
};

int DeepCopyStructor()
{
	Person man1("Park Sun Young", 28);
	Person man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();

	return 0;
}

void RunNameCard()
{
	NameCard manClerk("psy", "samsung", "000-0000", RANK_POS::CLERK);
	NameCard copy1 = manClerk;
	NameCard manSENIOR("ysy", "SKHinix", "000-0000", RANK_POS::SENIOR);
	NameCard copy2 = manSENIOR;
	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();
}