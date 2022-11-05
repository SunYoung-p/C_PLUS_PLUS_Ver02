#include <iostream>
using namespace std;

class c1012
{
private:
	static int simObjCnt;
public:
	c1012()
	{
		simObjCnt++;
		cout << simObjCnt << "번째 c1012 객체" << endl;
	}
};
int c1012::simObjCnt = 0;

class SoComplex
{
private:
	static int cmxObjCnt;
public:
	SoComplex()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
	}
	SoComplex(SoComplex &copy)
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
	}
};
int SoComplex::cmxObjCnt = 0;	// 초기화 안 해주면 없는 걸로 치부하고 에러 남. 그렇다고 위에 =0 넣으면 volatil이 아닌 const 정수 계열 형식 포함해야 한다고 에러 남

int StaticMember(void)
{
	c1012 sim1;
	c1012 sim2;

	SoComplex com1;
	SoComplex com2 = com1;
	SoComplex();

	return 0;
}