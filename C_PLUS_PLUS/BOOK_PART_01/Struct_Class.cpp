#include <iostream>

using namespace std;

namespace POINT_CONST
{
	enum
	{
		LENGTH = 100
	};
}

struct Point
{
	int xpos;
	int ypos;
	int pos_arr[POINT_CONST::LENGTH];

	void MovePos(int x, int y);
	void AddPoint(const Point &pos);
	void ShowPosition();
};

void Point::MovePos(int x, int y)
{
	xpos += x;
	ypos += y;
}

void Point::AddPoint(const Point &pos)
{
	xpos += pos.xpos;
	ypos += pos.ypos;
}

void Point::ShowPosition()
{
	cout << "[" << xpos << ", " << ypos << "]" << endl;
}

int struct_class()
{
	Point pos1 = { 12, 4 };
	Point pos2 = { 20, 30 };

	pos1.MovePos(-7, 10);
	pos1.ShowPosition();

	pos1.AddPoint(pos2);
	pos1.ShowPosition();


	getchar();
	getchar();
	return 0;
}