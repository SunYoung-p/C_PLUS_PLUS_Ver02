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
	cout << "Class변수 num1 의 값 : " << c1016::num1 << endl;
	cout << "Class변수 num1 의 값 : " << c1016::GetNum1() << endl;
	c1016 obj1;
	cout << "obj1을 통해 num1 값을 5만큼 증가 : " << obj1.Adder(5) << endl;
	cout << "Class변수 num1 의 값 : " << c1016::GetNum1() << endl;

	c1016 obj2(10);
	cout << endl << "mutable 키워드를 넣어서, const 함수이지만 값 변경 시도 : " <<
		obj2.AdderToN(10) << endl;

	return 0;
}