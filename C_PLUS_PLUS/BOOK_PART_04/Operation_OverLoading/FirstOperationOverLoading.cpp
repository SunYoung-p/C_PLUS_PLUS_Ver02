#include <iostream>
using namespace std;

class c1105
{
private:
	int xpos, ypos;
public:
	c1105(int x = 0, int y = 0) : xpos(x), ypos(y)
	{

	}
	void ShowPosition() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
	const c1105 operator+(const c1105 &ref)		// operator+라는 이름의 함수
	{
		c1105 pos(xpos + ref.xpos, ypos + ref.ypos);
		return pos;
	}
};

int FirstOperationOverLoading()
{
	c1105 pos1(3, 4);
	c1105 pos2(10, 20);
	//	c1105 pos3 = pos1.operator+(pos2);
	c1105 pos3 = pos1 + pos2;		// 이게 28행에 코드처럼 변환되어 컴파일 된다.
									//	1105 pos4 = pos1 - pos2;	// 컴파일 에러 발생. operator-() 함수 정의 필요
	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();


	return 0;
}