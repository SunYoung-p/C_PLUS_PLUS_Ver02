#include <iostream>
#include <cstring>
using namespace std;

class ObjArr_Person
{
private:
	char * name;
	int age;
public:
	ObjArr_Person(char * myname, int myage)		// 포인터 배열 사용 시
	{
		int len = strlen(myname) + 1; // \0 앞까지의 문자 개수만 센다
		name = new char[len];
		strcpy_s(name, len, myname); // \0을 포함해서 카피가 된다.
		age = myage;
	}
	ObjArr_Person()		// 일반 객체 배열 사용 시
	{
		name = NULL;
		age = 0;
		cout << "called Person()" << endl;
	}
	void SetPersonInfo(char * myname, int myage)
	{
		name = myname;
		age = myage;
	}
	void ShowPersonInfo() const
	{
		cout << "이름 : " << name << ", ";
		cout << "나이 : " << age << endl;
	}
	~ObjArr_Person()
	{
		delete[] name;
		cout << "called destructor!" << endl;
	}
};
int ObjArrRun()
{
	// 일반 객체 배열 사용 시 ObjArr_Person parr[3];
	ObjArr_Person * parr[3];
	char namestr[100];
	int age;
	// int len;
	// char strptr[100];
	for (int i = 0; i < 3; i++)
	{
		cout << "이름 : ";
		cin >> namestr;
		cout << "나이 : ";
		cin >> age;
		parr[i] = new ObjArr_Person(namestr, age);
		// 일반 객체 배열 사용 시 len = strlen(namestr) + 1;
		// 일반 객체 배열 사용 시 strptr = new char[len];
		// 일반 객체 배열 사용 시 strcpy_s(strptr, len, namestr);
		// 일반 객체 배열 사용 시 parr[i].SetPersonInfo(strptr, age);
	}
	parr[0]->ShowPersonInfo();
	parr[1]->ShowPersonInfo();
	parr[2]->ShowPersonInfo();

	delete parr[0];
	delete parr[1];
	delete parr[2];

	return 0;
}