#pragma once
#include "Point.h"

class Circle
{
private:
	Point p1;
	int radius;
public:
	Circle(){}
	Circle(Point p, int r);
	bool Init(Point p, int r);
	void ShowCircleInfo();
	int GetRadius() const;
	int GetX() const;
	int GetY() const;
};