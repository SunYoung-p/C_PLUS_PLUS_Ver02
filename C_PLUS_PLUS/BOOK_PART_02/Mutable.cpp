#include <iostream>

using namespace std;

class c1016
{
private:
	mutable int n;
public:
	c1016(int n) : n(n)
	{	}
	c1016()
	{  }
	static int num1;
public:
	static int GetNum1()
	{
		return num1;
	}

	int Adder(int n)
	{
		return num1 += n;
	}

	int AdderToN(int num) const
	{
		return n += num;
	}
};
int c1016::num1 = 10;

int Mutable()
{
	cout << "Class���� num1 �� �� : " << c1016::num1 << endl;
	cout << "Class���� num1 �� �� : " << c1016::GetNum1() << endl;
	c1016 obj1;
	cout << "obj1�� ���� num1 ���� 5��ŭ ���� : " << obj1.Adder(5) << endl;
	cout << "Class���� num1 �� �� : " << c1016::GetNum1() << endl;

	c1016 obj2(10);
	cout << endl << "mutable Ű���带 �־, const �Լ������� �� ���� �õ� : " <<
		obj2.AdderToN(10) << endl;

	return 0;
}