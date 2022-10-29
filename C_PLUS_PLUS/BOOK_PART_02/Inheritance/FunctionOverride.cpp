#include <iostream>
using namespace std;

class a1029
{
public:
	void MyFunc() { cout << "FirstFunc" << endl; }
};

class b1029 : public a1029
{
public:
	void MyFunc() { cout << "SecondFunc" << endl; }
};

class cc1029 : public b1029
{
public:
	void MyFunc() { cout << "ThirdFunc" << endl; }
};

int FunctionOverride()
{
	cc1029 * tptr = new cc1029();		// cc1029�� ������ ������ �����ϴ� ��ü���� �� 3���� MyFunc() �Լ��� �����ϸ�, ���� �������� �������̵� �� MyFunc�� ȣ��
	b1029* sptr = tptr;		// b1029�� ������ ������ �����ϴ� ��ü�� �� 2���� MyFunc() �Լ��� �����ϸ�,  ���� �������� �������̵� �� MyFunc�� ȣ��
	a1029* fptr = sptr;		// a1029�� �����Ͱ� �����ϴ� ��ü�� �ݵ�� a1029���� ������ MyFunc()�� ���� �ֱ� ������, a1029 MyFunc() ȣ�⿡ ������ ����

	tptr->MyFunc();
	sptr->MyFunc();
	fptr->MyFunc();

	delete tptr;

	return 0;
}