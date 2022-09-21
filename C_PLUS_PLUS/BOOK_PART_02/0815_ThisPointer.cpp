#include <iostream>
#include <cstring>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{
		cout << "num=" << num << ", ";
		cout << "address=" << this << endl;
	}
	void ShowSimpleData()
	{
		cout << num << endl;
	}
	SoSimple* GetThisPointer()
	{
		return this;
	}
};

class TwoNumber
{
private:
	int num1;
	int num2;
public:
	TwoNumber(int num1, int num2)
	{
		this->num1 = num1;
		this->num2 = num2;
	}
	/*
	TwoNumber(int num1, int num2) : num1(num1), num2(num2)
	{
	// 멤버 이니셜라이저에서 저장 변수는 멤버변수, 저장값은 매개변수로 인식하기 때문에
	위 생성자로 대체가 가능하다
	}
	*/
	void ShowTwoNumber()
	{
		cout << this->num1 << endl;
		cout << this->num2 << endl;
	}
};

class SelfRef
{
private:
	int num;
public:
	SelfRef(int n) : num(n)
	{
		cout << "객체생성" << endl;
	}
	SelfRef& Adder(int n)		// *를 붙여서, 객체의 주소값이 아니라 객체 자신을 리턴함
	{
		num += n;
		return *this;	// 받는 쪽에서 &참조자로 받으면, 별칭이 하나 생김으로 이 객체 자체를 참조할 수 있게 됨
	}
	SelfRef& ShowTwoNumber()
	{
		cout << num << endl;
		return *this;
	}
};

int ThisPointer_0815()
{
	SoSimple sim1(100);
	SoSimple * ptr1 = sim1.GetThisPointer();	// sim1 객체 주소값 저장
	cout << ptr1 << ", ";
	ptr1->ShowSimpleData();

	SoSimple sim2(200);
	SoSimple * ptr2 = sim2.GetThisPointer();
	cout << ptr2 << ", ";
	ptr2->ShowSimpleData();
	/*
	sim1 과 sim2의 주소값 및 멤버변수 num 값이 출력됨
	*/

	TwoNumber two(2, 4);
	two.ShowTwoNumber();

	SelfRef obj(3);
	SelfRef &ref = obj.Adder(2);

	obj.ShowTwoNumber();
	ref.ShowTwoNumber();

	ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();

	return 0;
}