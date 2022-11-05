#include <iostream>

using namespace std;

class Person
{
private:
	char * name;
	int age;
public:
	Person(char * myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy_s(name, len, myname);
		age = myage;
	}
	void ShowPersonInfo() const
	{
		cout << "�̸� : " << name << endl;
		cout << "���� : " << age << endl;
	}
	~Person()
	{
		delete[]name;
		cout << "called destructor!" << endl;
	}
};

int Destructor()
{
	Person man1("Lee dong woo", 29);
	Person man2("Jang dong gun", 41);
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();

	getchar();
	getchar();
	return 0;
}