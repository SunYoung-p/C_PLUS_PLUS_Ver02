#include <iostream>
using namespace std;

class c1012
{
private:
	static int simObjCnt;
public:
	c1012()
	{
		simObjCnt++;
		cout << simObjCnt << "��° c1012 ��ü" << endl;
	}
};
int c1012::simObjCnt = 0;

class SoComplex
{
private:
	static int cmxObjCnt;
public:
	SoComplex()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "��° SoComplex ��ü" << endl;
	}
	SoComplex(SoComplex &copy)
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "��° SoComplex ��ü" << endl;
	}
};
int SoComplex::cmxObjCnt = 0;	// �ʱ�ȭ �� ���ָ� ���� �ɷ� ġ���ϰ� ���� ��. �׷��ٰ� ���� =0 ������ volatil�� �ƴ� const ���� �迭 ���� �����ؾ� �Ѵٰ� ���� ��

int StaticMember(void)
{
	c1012 sim1;
	c1012 sim2;

	SoComplex com1;
	SoComplex com2 = com1;
	SoComplex();

	return 0;
}