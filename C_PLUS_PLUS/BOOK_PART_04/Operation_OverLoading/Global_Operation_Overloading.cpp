
#include <iostream>
using namespace std;

class cc1105
{
private:
	int xpos, ypos;
public:
	cc1105(int x = 0, int y = 0) : xpos(x), ypos(y)
	{

	}
	void ShowPosition() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
	friend cc1105 operator+(const cc1105 &pos1, const cc1105 &pos2);		// 전역 함수에서 cc1105 객체의 xpos, ypos에 접근 가능하도록 함
	friend cc1105 operator-(const cc1105 &pos1, const cc1105 &pos2);
};


cc1105 operator+(const cc1105 &pos1, const cc1105 &pos2)
{
	cc1105 pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
	return pos;
}

cc1105 operator-(const cc1105 &pos1, const cc1105 &pos2)
{
	cc1105 pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
	return pos;
}

int Global_Operation_Overloading()
{
	cc1105 pos1(3, 4);
	cc1105 pos2(10, 20);
	cc1105 pos3 = pos1 + pos2;
	cc1105 pos4 = pos2 - pos1;
	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	pos4.ShowPosition();
	return 0;
}
