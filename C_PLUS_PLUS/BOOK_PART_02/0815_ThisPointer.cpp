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
	// ��� �̴ϼȶ��������� ���� ������ �������, ���尪�� �Ű������� �ν��ϱ� ������
	�� �����ڷ� ��ü�� �����ϴ�
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
		cout << "��ü����" << endl;
	}
	SelfRef& Adder(int n)		// *�� �ٿ���, ��ü�� �ּҰ��� �ƴ϶� ��ü �ڽ��� ������
	{
		num += n;
		return *this;	// �޴� �ʿ��� &�����ڷ� ������, ��Ī�� �ϳ� �������� �� ��ü ��ü�� ������ �� �ְ� ��
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
	SoSimple * ptr1 = sim1.GetThisPointer();	// sim1 ��ü �ּҰ� ����
	cout << ptr1 << ", ";
	ptr1->ShowSimpleData();

	SoSimple sim2(200);
	SoSimple * ptr2 = sim2.GetThisPointer();
	cout << ptr2 << ", ";
	ptr2->ShowSimpleData();
	/*
	sim1 �� sim2�� �ּҰ� �� ������� num ���� ��µ�
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