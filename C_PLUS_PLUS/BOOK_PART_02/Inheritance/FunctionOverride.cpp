#include <iostream>
using namespace std;

class a1029
{
public:
	virtual void MyFunc() { cout << "FirstFunc" << endl; }
};

class b1029 : public a1029
{
public:
	virtual void MyFunc() { cout << "SecondFunc" << endl; }
};

class cc1029 : public b1029
{
public:
	virtual void MyFunc() { cout << "ThirdFunc" << endl; }
};

int FunctionOverride()
{
	cc1029 * tptr = new cc1029();		// cc1029형 포인터 변수가 참조하는 객체에는 총 3개의 MyFunc() 함수가 존재하며, 가장 마지막에 오버라이딩 된 MyFunc를 호출
	b1029* sptr = tptr;		// b1029형 포인터 변수가 참조하는 객체는 총 2개의 MyFunc() 함수가 존재하며,  가장 마지막에 오버라이딩 된 MyFunc를 호출
	a1029* fptr = sptr;		// a1029형 포인터가 참조하는 객체는 반드시 a1029에서 선언한 MyFunc()를 갖고 있기 때문에, a1029 MyFunc() 호출에 문제가 없음
							/*
							가상 함수 (virtual) 처리를 한 오버라이딩 된 (받은) 함수들은, 해당 함수 호출 시
							변수 자료형이 아니라 변수가 가리키는 주소의 자료형에 있는 함수를 호출하게 된다.
							따라서 위에 virtual로 처리됨에 따라 cc1029 자료형에 있는 MyFunc만 3번 호출하게 된다.
							*/

	tptr->MyFunc();
	sptr->MyFunc();
	fptr->MyFunc();


	delete tptr;

	return 0;
}