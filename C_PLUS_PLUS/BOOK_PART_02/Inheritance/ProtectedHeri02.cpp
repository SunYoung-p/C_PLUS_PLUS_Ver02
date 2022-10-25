#include <iostream>
using namespace std;

class c1025
{
private:
	int num1;
protected:
	int num2;
public:
	int num3;

	c1025() : num1(1), num2(2), num3(3)
	{ }
};

class d1025 : protected c1025 	// empty!
{

};

int ProtectedHeri02()
{
	d1025 drv;
	// 컴파일 에러 발생! cout << drv.num3 << endl;
	return 0;
}