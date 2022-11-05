#include <iostream>
#include <cstring>
using namespace std;

class ObjArr_Person
{
private:
	char * name;
	int age;
public:
	ObjArr_Person(char * myname, int myage)		// ������ �迭 ��� ��
	{
		int len = strlen(myname) + 1; // \0 �ձ����� ���� ������ ����
		name = new char[len];
		strcpy_s(name, len, myname); // \0�� �����ؼ� ī�ǰ� �ȴ�.
		age = myage;
	}
	ObjArr_Person()		// �Ϲ� ��ü �迭 ��� ��
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
		cout << "�̸� : " << name << ", ";
		cout << "���� : " << age << endl;
	}
	~ObjArr_Person()
	{
		delete[] name;
		cout << "called destructor!" << endl;
	}
};
int ObjArrRun()
{
	// �Ϲ� ��ü �迭 ��� �� ObjArr_Person parr[3];
	ObjArr_Person * parr[3];
	char namestr[100];
	int age;
	// int len;
	// char strptr[100];
	for (int i = 0; i < 3; i++)
	{
		cout << "�̸� : ";
		cin >> namestr;
		cout << "���� : ";
		cin >> age;
		parr[i] = new ObjArr_Person(namestr, age);
		// �Ϲ� ��ü �迭 ��� �� len = strlen(namestr) + 1;
		// �Ϲ� ��ü �迭 ��� �� strptr = new char[len];
		// �Ϲ� ��ü �迭 ��� �� strcpy_s(strptr, len, namestr);
		// �Ϲ� ��ü �迭 ��� �� parr[i].SetPersonInfo(strptr, age);
	}
	parr[0]->ShowPersonInfo();
	parr[1]->ShowPersonInfo();
	parr[2]->ShowPersonInfo();

	delete parr[0];
	delete parr[1];
	delete parr[2];

	return 0;
}