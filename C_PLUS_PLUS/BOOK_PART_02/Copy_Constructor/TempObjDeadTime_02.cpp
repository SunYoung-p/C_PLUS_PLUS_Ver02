#include <iostream>

using namespace std;

class SoSimple5
{
private:
	int num;
public:
	SoSimple5(int n) : num(n)
	{
		cout << "New Object: " << this << endl;
	}
	SoSimple5(const SoSimple5& copy) : num(copy.num)
	{
		cout << "New Copy obj : " << this << endl;
	}
	~SoSimple5()
	{
		cout << "Destory obj: " << this << endl;
	}
};

SoSimple5 SimpleFuncOb(SoSimple5 ob)
{
	cout << "Parm ADR: " << &ob << endl;
	return ob;
}

int TempObjDeadTime_02()
{
	SoSimple5 obj(7);
	SimpleFuncOb(obj);		// �Ű����� �ʱ�ȭ�ϸ鼭 1��, ���Ͽ� �Ű����� �ʱ�ȭ�ϸ鼭 1�� �� 2�� ��������� ȣ��

	cout << endl;

	SoSimple5 tempRef = SimpleFuncOb(obj);	// �Ű����� �ʱ�ȭ + ���Ͽ� ���� �ʱ�ȭ�� ��������� 3�� ȣ��
											/* tempRef��� ��ü�� ��������� ���ԵǴ� �� �ƴ϶�, ���Ͽ� ���� �ʱ�ȭ�� �� �ּҸ� �޾Ƽ� �����ϴ� �� ��. */

	cout << "Return Obj " << &tempRef << endl;	 //obj��, tempRef�� ���������� �Ҹ�

	return 0;
}

