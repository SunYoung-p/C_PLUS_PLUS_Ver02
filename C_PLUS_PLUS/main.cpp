#include <iostream>
using namespace std;

class cl1012
{
private:
	static int simObjCnt;
public :
	cl1012()
	{
		simObjCnt++;
		cout << simObjCnt << "��° cl1012 ��ü" << endl;
	}
};
int cl1012::simObjCnt = 0;

class SoComplexs
{
	private:
		static int cmxObjCnt;
public:
	SoComplexs()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "��° SoComplexs ��ü" << endl;
	}
	SoComplexs(SoComplexs &copy)
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "��° SoComplexs ��ü" << endl;
	}
};
int SoComplexs::cmxObjCnt = 0;	// �ʱ�ȭ �� ���ָ� ���� �ɷ� ġ���ϰ� ���� ��. �׷��ٰ� ���� =0 ������ volatil�� �ƴ� const ���� �迭 ���� �����ؾ� �Ѵٰ� ���� ��

int main(void)
{
	cl1012 sim1;
	cl1012 sim2;

	SoComplexs com1;
	SoComplexs com2 = com1;
	SoComplexs();

	return 0;
}