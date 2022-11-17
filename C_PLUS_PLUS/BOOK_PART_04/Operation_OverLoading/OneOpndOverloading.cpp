#include <iostream>
using namespace std;

class c1109
{
private:
	int xpos, ypos;
public:
	c1109(int x = 0, int y = 0) : xpos(x), ypos(y)
	{

	}
	void ShowPosition() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
	c1109& operator++()		// 단항 연산자는 매개변수가 1개뿐인데, 멤버 함수 형식으로 오버로딩 되면 0개가 됨
	{
		xpos += 1;
		ypos += 1;
		return *this;
	}
	c1109& operator-()
	{
		xpos *= -1;
		ypos *= -1;
		return *this;
	}
	friend c1109& operator--(c1109 &ref);
	friend c1109& operator~(c1109 &ref);
};

c1109& operator--(c1109 &ref)
{
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;		// 매개변수로 받은 ref가 주소값이 아니므로, *ref가 아님
}

c1109& operator~(c1109 &ref)
{
	int temp = ref.xpos;
	ref.xpos = ref.ypos;
	ref.ypos = temp;
	return ref;
}

int OneOpndOverloading()
{
	c1109 pos(1, 2);
	++pos;
	pos.ShowPosition();
	--pos;
	pos.ShowPosition();

	++(++pos);		// pos.operator++() 로 해석됨
	pos.ShowPosition();
	--(--pos);			// operator--(pos) 로 해석됨
	pos.ShowPosition();

	c1109 pos2 = -pos;
	pos2.ShowPosition();
	c1109 pos3 = ~pos2;
	pos3.ShowPosition();
	return 0;
}
