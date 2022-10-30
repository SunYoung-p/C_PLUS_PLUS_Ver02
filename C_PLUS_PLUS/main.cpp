#include <iostream>
using namespace std;

class cc1030
{
public:
	void FirstFunc() { cout << "FirstFunc()" << endl; }
	virtual void SimpleFunc() { cout << "First's SimpleFunc()" << endl; }
};

class ss1030 : public cc1030
{
public:
	void SecondFunc() { cout << "SecondFunc()" << endl; }
	virtual void SimpleFunc() { cout << "Second's SimpleFunc()" << endl; }
};

class dd1030 : public ss1030
{
public:
	void ThirdFunc() { cout << "ThirdFunc()" << endl; }
	virtual void SimpleFunc() { cout << "Third's SimpleFunc()" << endl;}
};

int main()
{
	dd1030 obj;
	obj.FirstFunc();
	obj.SecondFunc();
	obj.ThirdFunc();
	obj.SimpleFunc();

	cout << endl << endl;

	ss1030 & sref = obj;
	sref.FirstFunc();
	sref.SecondFunc();
	sref.SimpleFunc();

	cout << endl << endl;

	cc1030 & fref = obj;
	fref.FirstFunc();
	fref.SimpleFunc();

	return 0;
}