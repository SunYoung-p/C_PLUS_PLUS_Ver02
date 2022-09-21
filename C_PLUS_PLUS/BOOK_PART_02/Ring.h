#pragma once
#include "Circle.h"
class Ring
{
private:
	Circle circle1;
	Circle circle2;

public:
	Ring() {};
	Ring(int, int, int, int, int, int);
	bool Init(int, int, int, int, int, int);
	void ShowRingInfo();
	Circle GetCircle1() const;
	Circle GetCircle2() const;
};