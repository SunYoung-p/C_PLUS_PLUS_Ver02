
#include <iostream>
using namespace std;

class ccc1103
{
public:
	ccc1103() { cout << "Base Constructor" << endl; }
	void SimpleFunc() { cout << "BaseOne" << endl; }
};

class MiddleDerivedOne : virtual public ccc1103
{
public:
	MiddleDerivedOne() : ccc1103()
	{
		cout << "MiddleDerivedOne Constructor" << endl;
	}
	void MiddleFuncOne()
	{
		SimpleFunc();
		cout << "MiddleFuncOne" << endl;
	}
};

class MiddleDerivedTwo : virtual public ccc1103
{
public:
	MiddleDerivedTwo() : ccc1103()
	{
		cout << "MiddleDerivedTwo Constructor" << endl;
	}
	void MiddleFuncTwo()
	{
		SimpleFunc();
		cout << "MiddleDerivedTwo" << endl;
	}
};


class LastDerived : public MiddleDerivedOne, public MiddleDerivedTwo
{
public:
	LastDerived() : MiddleDerivedOne(), MiddleDerivedTwo()
	{
		cout << "LastDerived Constructor" << endl;
	}
	void ComplexFunc()
	{
		MiddleDerivedOne();
		MiddleDerivedTwo();
		SimpleFunc();
		// ������ MiddleDerivedOne::SimpleFunc() ���� ��� ������ ����. 
		// ���� ����� 2�� �޾Ƽ� ccc1103 ����� 2�� �̹Ƿ� ��� SimpleFunc()�� ��� �ϴ��� �𸣱� �����̴�.
		// �� �� Middle One, Middle Two Ŭ������ virtual�� �ٿ��� ���� ����� �ް� �Ǹ� �ߺ��Ǵ� ccc1103 ����� 1���� ���� �ǹǷ� ���� ���� ����� �����ϴ�.
	}
};


int Virtual_Inheri()
{
	cout << "��ü ���� ��....." << endl;
	LastDerived ldr;
	cout << "��ü ���� ��....." << endl;
	ldr.ComplexFunc();

	return 0;
}