#include <iostream>
using namespace std;

class Point1012;

class PointOP
{
private:
	int opcnt;
public:
	PointOP() : opcnt(0)
	{	}

	Point1012 PointAdd(const Point1012&, const Point1012&);
	Point1012 PointSub(const Point1012&, const Point1012&);
	~PointOP()
	{
		cout << "Operation times : " << opcnt << endl;
	}
};

class Point1012
{
private:
	int x;
	int y;
public:
	Point1012(const int &xpos, const int &ypos) : x(xpos), y(ypos)
	{

	}
	friend Point1012 PointOP::PointAdd(const Point1012&, const Point1012&);	// friend 의미는 연산자클래스 및 함수에서 x,y에 직접 접근시키기 위한 것
	friend Point1012 PointOP::PointSub(const Point1012&, const Point1012&);
	friend void ShowPointPos(const Point1012&);
};


Point1012 PointOP::PointAdd(const Point1012& pnt1, const Point1012& pnt2)
{
	opcnt++;
	return Point1012(pnt1.x + pnt2.x, pnt1.y + pnt2.y);
}

Point1012 PointOP::PointSub(const Point1012& pnt1, const Point1012& pnt2)
{
	opcnt++;
	return Point1012(pnt1.x - pnt2.x, pnt1.y - pnt2.y);
}

void ShowPointPos(const Point1012& pos)
{
	cout << "x: " << pos.x << ", ";
	cout << "y: " << pos.y << endl;
}


int MyFriendFunction2()
{
	Point1012 pos1(1, 2);
	Point1012 pos2(2, 4);
	PointOP op;

	ShowPointPos(op.PointAdd(pos1, pos2));
	ShowPointPos(op.PointSub(pos2, pos1));
	return 0;
}