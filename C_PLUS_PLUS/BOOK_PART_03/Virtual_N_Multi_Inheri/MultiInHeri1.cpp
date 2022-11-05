#include <iostream>
using namespace std;

class c1103
{
public:
	void SimpleFuncOne() { cout << "BaseOne" << endl; }
};

class s1103
{
public:
	void SimpleFuncTwo() { cout << "BaseTwo" << endl; }
};

class MultiDerived : public c1103, protected s1103
{
public:
	void ComplexFunc()
	{
		SimpleFuncOne();
		SimpleFuncTwo();
	}
};

int MultiInHeri1()
{
	MultiDerived mdr;
	mdr.ComplexFunc();

	return 0;
}