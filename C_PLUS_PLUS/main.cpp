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

int main()
{
	c1103* aptr = new c1103();
	aptr->Func1();

	s1103* bptr = new s1103();
	bptr->Func1();

	return 0;
}