#include <iostream>

using namespace std;

class SoSimple5
{
private:
	int num;
public:
	SoSimple5(int n) : num(n)
	{
		cout << "New Object: " << this << endl;
	}
	SoSimple5(const SoSimple5& copy) : num(copy.num)
	{
		cout << "New Copy obj : " << this << endl;
	}
	~SoSimple5()
	{
		cout << "Destory obj: " << this << endl;
	}
};

SoSimple5 SimpleFuncOb(SoSimple5 ob)
{
	cout << "Parm ADR: " << &ob << endl;
	return ob;
}

int TempObjDeadTime_02()
{
	SoSimple5 obj(7);
	SimpleFuncOb(obj);		// 매개변수 초기화하면서 1번, 리턴용 매개변수 초기화하면서 1번 총 2번 복사생성자 호출

	cout << endl;

	SoSimple5 tempRef = SimpleFuncOb(obj);	// 매개변수 초기화 + 리턴용 변수 초기화로 복사생성자 3번 호출
											/* tempRef라는 객체가 만들어져서 대입되는 게 아니라, 리턴용 변수 초기화된 걸 주소를 받아서 참조하는 것 뿐. */

	cout << "Return Obj " << &tempRef << endl;	 //obj랑, tempRef가 마지막으로 소멸

	return 0;
}

