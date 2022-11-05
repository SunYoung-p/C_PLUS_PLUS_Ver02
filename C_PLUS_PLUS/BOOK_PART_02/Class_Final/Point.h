#pragma once
class Point
{
private:
	int x;
	int y;
public:
	Point() {};
	Point(const int &xpos, const int &ypos);
	bool InitMembers(int xpos, int ypos);
	int GetX() const;
	int GetY() const;
	bool SetX(int xpos);
	bool SetY(int ypos);
	void ShowPointInfo() const;
};
