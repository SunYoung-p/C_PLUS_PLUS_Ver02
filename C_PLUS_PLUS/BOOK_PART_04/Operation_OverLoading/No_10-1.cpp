#include <iostream>
using namespace std;

class c1106
{
private:
	int xpos;
	int ypos;
public:
	c1106(int x = 0, int y = 0) : xpos(x), ypos(y)
	{

	}

	void ShowPosInfo()
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}

	c1106& operator+=(const c1106& p)
	{
		xpos += p.xpos;
		ypos += p.ypos;
		return *this;
	}

	c1106& operator-=(const c1106& p)
	{
		xpos -= p.xpos;
		ypos -= p.ypos;
		return *this;
	}
	friend bool operator==(const c1106& p, const c1106& q);
	friend bool operator!=(const c1106& p, const c1106& q);
};

bool operator==(const c1106& p, const c1106& q)
{
	if (p.xpos == q.xpos && p.ypos == q.ypos)
		return true;
	else
		return false;
}

bool operator!=(const c1106& p, const c1106& q)
{
	if (p == q)
		return false;
	else
		return true;
}

int No_10_1_1106()
{
	c1106 pos1(5, 10);
	c1106 pos2(3, 3);
	c1106 pos3(1, 1);
	(pos1 += pos2).ShowPosInfo();
	(pos1 -= pos3).ShowPosInfo();

	c1106 pos4(1, 1);
	c1106 pos5(1, 2);
	c1106 pos6(1, 1);

	cout << endl;
	cout << "pos4 의 값 : "; pos4.ShowPosInfo();
	cout << "pos5 의 값 : "; pos5.ShowPosInfo();
	cout << "pos6 의 값 : "; pos6.ShowPosInfo();
	cout << endl;

	cout << "pos4와 pos5 == 연산 결과 : " << (pos4 == pos5) << endl;
	cout << "pos4와 pos6 == 연산 결과 : " << (pos4 == pos6) << endl;

	cout << "pos4와 pos5 != 연산 결과 : " << (pos4 != pos5) << endl;
	cout << "pos4와 pos6 != 연산 결과 : " << (pos4 != pos6) << endl;
	return 0;
}
