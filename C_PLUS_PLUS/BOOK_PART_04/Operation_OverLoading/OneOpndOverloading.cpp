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
	c1109& operator++()		// ���� �����ڴ� �Ű������� 1�����ε�, ��� �Լ� �������� �����ε� �Ǹ� 0���� ��
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
	return ref;		// �Ű������� ���� ref�� �ּҰ��� �ƴϹǷ�, *ref�� �ƴ�
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

	++(++pos);		// pos.operator++() �� �ؼ���
	pos.ShowPosition();
	--(--pos);			// operator--(pos) �� �ؼ���
	pos.ShowPosition();

	c1109 pos2 = -pos;
	pos2.ShowPosition();
	c1109 pos3 = ~pos2;
	pos3.ShowPosition();
	return 0;
}
