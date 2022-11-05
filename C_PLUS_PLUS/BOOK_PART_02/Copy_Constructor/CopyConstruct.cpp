#include <iostream>

using namespace std;

class SoSimple
{
private:
	int num;
	int num2;
public:
	SoSimple(int n, int m) : num(n), num2(m)
	{
	}

	SoSimple(SoSimple &copy)	// explicit 키워드를 붙여주면 = 가 아니라 () 로만 클래스 생성 가능
		: num(copy.num), num2(copy.num2)
	{
		cout << "Called SoSimple(SoSimple &copy)" << endl;
	}
	void ShowInfo()
	{
		cout << num << endl;
		cout << num2 << endl;
	}
};

int CopyConstruct()
{

	SoSimple s1(10, 20);
	cout << "생성 및 초기화 직전" << endl;
	SoSimple s2 = s1; // SoSimple sim2(s1) 로 변환, 혹시 위 복사 생성자가 없다면, 멤버 이니셜라이즈를 그대로 가져와서 디폴트 자동 생성된다
					  //SoSimple s2(s1); explicit 키워드 사용시, 묵시적 형 변환 = 가 ()로 바뀌는 걸, 허용하지 않기때문에 ()로만 초기화가 가능
	cout << "생성 및 초기화 직후" << endl;
	s2.ShowInfo();

	return 0;
}