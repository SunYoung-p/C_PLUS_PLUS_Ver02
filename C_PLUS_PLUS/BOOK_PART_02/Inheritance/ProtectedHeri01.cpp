
#include <iostream>
using namespace std;

class Base1025
{
private:
	int num1;
protected:
	int num2;
public:
	int num3;
	Base1025()
	{ }
	Base1025(int n, int m, int l)
	{
		num1 = n;
		num2 = m;
		num3 = l;
	}

	void ShowData()
	{
		cout << num1 << ", " << num2 << ", " << num3 << endl;
	}
};

class Derived1025 : public Base1025	// private ��� ��, num3 ���� �Ұ� ó���Ǿ� 42�� ������ ���� �߻�
{														// �� private ����ص� 35���� ������ ���� ���� �� �𸣰ڴ� > private ��� ������ �Ǿ�, ���� Ŭ���� �������� ���ٰ����� ����� ��. 
														// ���� private ����� ����Ŭ������ �� 2 ����Ŭ������ �ٽ� ����ϸ�, �� �� ��μ� ���� �Ұ��ϰ� ��
														// private, protected, public  > private ��� ��  ���ٺҰ�1,  private1, private2  > private ��� �� ���ٺҰ�1, ���ٺҰ�2, ���ٺҰ�3
public:
	Derived1025(int n, int m, int l) : Base1025(n, m, l)
	{}
	void ShowData()
	{
		//	cout << num1;  ������ ���� �߻�
		cout << num2 << ", " << num3 << endl;
	}
};
int ProtectedHeri01()
{
	Base1025 n(5, 10, 15);
	Derived1025 m(3, 6, 9);
	m.num3 += 4;
	n.ShowData();
	cout << endl;
	m.ShowData();
	return 0;
}