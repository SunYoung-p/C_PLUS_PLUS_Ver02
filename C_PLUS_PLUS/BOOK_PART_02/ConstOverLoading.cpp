#include <iostream>
using namespace std;

class SoSimple0923_2
{
private:
	int num;
public:
	SoSimple0923_2(int n) : num(n)
	{}
	SoSimple0923_2& AddNum(int n)
	{
		num += n;
		return *this;
	}
	void SimpleFunc()
	{
		cout << "SimpleFunc: " << num << endl;
	}
	void SimpleFunc() const // const도 오버로딩의 조건이 될 수 있음
	{
		cout << "const SimpleFunc: " << num << endl;
	}
};

void YourFunc(const SoSimple0923_2 &obj)	// const 로 객체를 받음
{
	obj.SimpleFunc();	// const SimpleFunc 호출
}
int ConstOverLoading(void)
{
	SoSimple0923_2 obj1(2);
	const SoSimple0923_2 obj2(7);

	obj1.SimpleFunc();
	obj2.SimpleFunc();

	YourFunc(obj1);
	YourFunc(obj2);
	return 0;
}