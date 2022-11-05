#include <iostream>
using namespace std;

class c1103
{
private:
	int num1;
public:
	virtual void Func1() { cout << "Func1" << endl; }
	virtual void Func2() { cout << "Func2" << endl; }
};

class s1103 : public c1103
{
private:
	int num2;
public:
	virtual void Func1() { cout << "c1103::Func1" << endl; }
	void Func3() { cout << "Func3" << endl; }
};

 // aptr과 bptr은 virtual table의 주소값을 갖고 있다.  해당 테이블을 참조하여 fun1, fun2, fun3을 찾아가는데,  
 //	오버라이딩을 받은 기초 클래스의 주소는 테이블에 없다. 그래서 가장 마지막에 오버라이딩 된 함수를 찾아가게 되는 것이 가상 함수의 원리이다.
int VTable()
{
	c1103* aptr = new c1103();
	aptr->Func1();

	s1103* bptr = new s1103();
	bptr->Func1();

	return 0;
}