#include <iostream>
using namespace std;

class SoBase
{
private:
	int baseNum;
public:
	SoBase() : baseNum(20)
	{
		cout << "SoBase()" << endl;
	}
	SoBase(int n) : baseNum(n)
	{
		cout << "SoBase(int n)" << endl;
	}
	void ShowBaseData()
	{
		cout << baseNum << endl;
	}
	~SoBase()
	{
		cout << "~SoBase()" << baseNum << endl;
		// 1. 유도 클래스 소멸 시,  먼저 유도 클래스 소멸자 실행 후 기초 클래스 소멸자가 실행된다
		// 2. 스택에 쌓인 순서와 역순으로 객체가 소멸된다 
		// 3. 생성자에서 동적 할당한 공간은 소멸자에서 해제한다.
	}
};

class SoDerived : public SoBase
{
private:
	int derivNum;
public:
	SoDerived() : derivNum(30)
	{
		cout << "SoDerived()" << endl;
	}
	SoDerived(int n) : derivNum(n)
	{
		cout << "SoDerived(int n)" << endl;
	}
	SoDerived(int n1, int n2) : SoBase(n1), derivNum(n2)	// 클래스의 멤버변수 초기화는 해당 클래스 생성자로 해야 한다.  부모 클래스 변수는, 부모 클래스 생성자로 초기화!
	{
		cout << "SoDerived(int n1, int n2)" << endl;
	}
	~SoDerived()
	{
		cout << "~SoDerived() : " << derivNum << endl;
	}
	void ShowDerivData()
	{
		ShowBaseData();
		cout << derivNum << endl;
	}
};

int DeriveDestOrder()
{
	cout << "case1 . . . . ." << endl;
	SoDerived dr1;
	dr1.ShowDerivData();	// SoBase() 생성자 출력이 먼저,  그 다음에 SoDerived() 출력
	cout << "-------------------" << endl;

	cout << "case2 . . . . ." << endl;
	SoDerived dr2(12);
	dr2.ShowDerivData();
	cout << "-------------------" << endl;

	cout << "case3 . . . . ." << endl;
	SoDerived dr3(23, 24);
	dr3.ShowDerivData();
	cout << "-------------------" << endl;

	return 0;
}