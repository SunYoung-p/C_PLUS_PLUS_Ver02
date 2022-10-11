#include <iostream>
using namespace std;

class cl1012
{
private:
	static int simObjCnt;
public :
	cl1012()
	{
		simObjCnt++;
		cout << simObjCnt << "번째 cl1012 객체" << endl;
	}
};
int cl1012::simObjCnt = 0;

class SoComplexs
{
	private:
		static int cmxObjCnt;
public:
	SoComplexs()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "번째 SoComplexs 객체" << endl;
	}
	SoComplexs(SoComplexs &copy)
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "번째 SoComplexs 객체" << endl;
	}
};
int SoComplexs::cmxObjCnt = 0;	// 초기화 안 해주면 없는 걸로 치부하고 에러 남. 그렇다고 위에 =0 넣으면 volatil이 아닌 const 정수 계열 형식 포함해야 한다고 에러 남

int main(void)
{
	cl1012 sim1;
	cl1012 sim2;

	SoComplexs com1;
	SoComplexs com2 = com1;
	SoComplexs();

	return 0;
}