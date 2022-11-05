#include <iostream>
using namespace std;

class SoBase
{
private:
	int baseNum;
public:
	SoBase() : baseNum(20)
	{
		cout << "SoBase()" << endl;
	}
	SoBase(int n) : baseNum(n)
	{
		cout << "SoBase(int n)" << endl;
	}
	void ShowBaseData()
	{
		cout << baseNum << endl;
	}
	~SoBase()
	{
		cout << "~SoBase()" << baseNum << endl;
		// 1. ���� Ŭ���� �Ҹ� ��,  ���� ���� Ŭ���� �Ҹ��� ���� �� ���� Ŭ���� �Ҹ��ڰ� ����ȴ�
		// 2. ���ÿ� ���� ������ �������� ��ü�� �Ҹ�ȴ� 
		// 3. �����ڿ��� ���� �Ҵ��� ������ �Ҹ��ڿ��� �����Ѵ�.
	}
};

class SoDerived : public SoBase
{
private:
	int derivNum;
public:
	SoDerived() : derivNum(30)
	{
		cout << "SoDerived()" << endl;
	}
	SoDerived(int n) : derivNum(n)
	{
		cout << "SoDerived(int n)" << endl;
	}
	SoDerived(int n1, int n2) : SoBase(n1), derivNum(n2)	// Ŭ������ ������� �ʱ�ȭ�� �ش� Ŭ���� �����ڷ� �ؾ� �Ѵ�.  �θ� Ŭ���� ������, �θ� Ŭ���� �����ڷ� �ʱ�ȭ!
	{
		cout << "SoDerived(int n1, int n2)" << endl;
	}
	~SoDerived()
	{
		cout << "~SoDerived() : " << derivNum << endl;
	}
	void ShowDerivData()
	{
		ShowBaseData();
		cout << derivNum << endl;
	}
};

int DeriveDestOrder()
{
	cout << "case1 . . . . ." << endl;
	SoDerived dr1;
	dr1.ShowDerivData();	// SoBase() ������ ����� ����,  �� ������ SoDerived() ���
	cout << "-------------------" << endl;

	cout << "case2 . . . . ." << endl;
	SoDerived dr2(12);
	dr2.ShowDerivData();
	cout << "-------------------" << endl;

	cout << "case3 . . . . ." << endl;
	SoDerived dr3(23, 24);
	dr3.ShowDerivData();
	cout << "-------------------" << endl;

	return 0;
}