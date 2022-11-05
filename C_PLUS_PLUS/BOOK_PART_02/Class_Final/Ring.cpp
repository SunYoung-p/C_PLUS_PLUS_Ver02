#include <iostream>
#include "Circle.h"
#include "Point.h"
#include "Ring.h"

using namespace std;

Ring::Ring(int x1, int y1, int r1, int x2, int y2, int r2)
	: circle1(Point(x1, y1), r1), circle2(Point(x2, y2), r2)
{
}


bool Ring::Init(int x1, int y1, int r1, int x2, int y2, int r2)
{
	Point p1(x1, y1), p2(x2, y2);
	
	if (p1.InitMembers(x1, y1) == false)
	{
		cout << "값이 잘못되었습니다. p1 초기화 실패" << endl;
		return false;
	}

	if (p2.InitMembers(x2, y2) == false)
	{
		cout << "값이 잘못되었습니다. p2 초기화 실패" << endl;
		return false;
	}

	if (circle1.Init(p1, r1) == false)
	{
		cout << "반지름 값이 잘못되었습니다. circle1 초기화 실패" << endl;
		return false;
	}

	if (circle2.Init(p2, r2) == false)
	{
		cout << "반지름 값이 잘못되었습니다. circle2 초기화 실패" << endl;
		return false;
	}

	return true;
}

void Ring::ShowRingInfo()
{
	char str[25] = { 0 };

	if (circle1.GetRadius() == circle2.GetRadius())
	{
		strcpy_s(str, 25, "Same Circle Info...");
	}
	else
	{
		strcpy_s(str, 25, "Inner Circle Info...");
	}

	cout << str << endl;
	cout << "radius: " << circle1.GetRadius() << endl;
	cout << "[" << circle1.GetX() << ", " << circle1.GetY() << "]" << endl;

	cout << str << endl;
	cout << "radius: " << circle2.GetRadius() << endl;
	cout << "[" << circle2.GetX() << ", " << circle2.GetY() << "]" << endl;
}

Circle Ring::GetCircle1() const
{
	return circle1;
}

Circle Ring::GetCircle2() const
{
	return circle2;
}