#include <iostream>
#include "Point.h"
#include "Circle.h"

using namespace std;

Circle::Circle(Point p, int r) : p1(p), radius(r)
{

}

bool Circle::Init(Point p, int r)
{
	p1 = p;

	if (r < 1)
	{
		cout << "반지름 값이 잘못되었습니다" << endl;
		return false;
	}

	radius = r;

	return true;
}

void Circle::ShowCircleInfo()
{
	cout << "radius: " << GetRadius() << endl;
	cout << "[" << p1.GetX() << ", " << p1.GetY() << "]" << endl;
}

int Circle::GetRadius() const
{
	return radius;
}

int Circle::GetX() const
{
	return p1.GetX();
}

int Circle::GetY() const
{
	return p1.GetY();
}