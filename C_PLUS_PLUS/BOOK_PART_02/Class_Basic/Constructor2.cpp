#include <iostream>

using namespace std;

class SimpleClass
{
private:
	int num1;
	int num2;
public:

	SimpleClass(int n1 = 10, int n2 = 20)
	{
		num1 = n1;
		num2 = n2;
	}

	void ShowData() const
	{
		cout << num1 << ' ' << num2 << endl;
	}
};

int Constructor2()
{
	SimpleClass sc1();		// �Լ��� ���� ��������, ������ �������� �� �� �����Ƿ� sc1() �� ���� �������θ� ����� ���
	SimpleClass mysc = sc1();
	mysc.ShowData();

	getchar();
	getchar();
	return 0;
}

SimpleClass sc1()
{
	SimpleClass sc(20, 30);
	return sc;
}