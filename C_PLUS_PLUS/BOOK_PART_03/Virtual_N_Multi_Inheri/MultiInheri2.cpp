
#include <iostream>
using namespace std;

class cc1103
{
public:
	void SimpleFuncOne() { cout << "BaseOne" << endl; }
};

class ss1103
{
public:
	void SimpleFuncOne() { cout << "BaseTwo" << endl; }
};

class MultiDerived : public cc1103, protected ss1103
{
public:
	void ComplexFunc()
	{
		cc1103::SimpleFuncOne();	// ��ȣ�� ���� �ذ� ���
		ss1103::SimpleFuncOne();
	}
};

int MultiInheri2()
{
	MultiDerived mdr;
	mdr.ComplexFunc();

	return 0;
}