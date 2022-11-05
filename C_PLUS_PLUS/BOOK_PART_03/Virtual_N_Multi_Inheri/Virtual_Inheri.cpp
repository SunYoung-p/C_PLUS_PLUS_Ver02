
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
		// 원래는 MiddleDerivedOne::SimpleFunc() 같이 써야 에러가 없다. 
		// 간접 상속을 2번 받아서 ccc1103 멤버가 2개 이므로 어느 SimpleFunc()를 써야 하는지 모르기 때문이다.
		// 이 때 Middle One, Middle Two 클래스를 virtual을 붙여서 가상 상속을 받게 되면 중복되는 ccc1103 멤버가 1개만 남게 되므로 위와 같이 사용이 가능하다.
	}
};


int Virtual_Inheri()
{
	cout << "객체 생성 전....." << endl;
	LastDerived ldr;
	cout << "객체 생성 후....." << endl;
	ldr.ComplexFunc();

	return 0;
}