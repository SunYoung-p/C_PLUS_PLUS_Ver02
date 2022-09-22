#include <iostream>
using namespace std;

class SoSimple0923
{
private:
	int num;
public:
	SoSimple0923(int n) : num(n)
	{

	}
	SoSimple0923& AddNum(int n)
	{
		num += n;
		return *this;
	}
	void ShowData() const	// 가급적 변수 값 변경이 없는 함수에도 const를 붙여서, const 객체가 호출할 수 있게끔 하기
	{
		cout << "num: " << num << endl;
	}
};

int ConstObject(void)
{
	SoSimple0923 obj(7);
	obj.AddNum(20);
	obj.ShowData();
	return 0;
}