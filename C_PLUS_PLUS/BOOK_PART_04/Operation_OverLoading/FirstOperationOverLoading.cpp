#include <iostream>
using namespace std;

class c1105
{
private:
	int xpos, ypos;
public:
	c1105(int x = 0, int y = 0) : xpos(x), ypos(y)
	{

	}
	void ShowPosition() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
	const c1105 operator+(const c1105 &ref)		// operator+��� �̸��� �Լ�
	{
		c1105 pos(xpos + ref.xpos, ypos + ref.ypos);
		return pos;
	}
};

int FirstOperationOverLoading()
{
	c1105 pos1(3, 4);
	c1105 pos2(10, 20);
	//	c1105 pos3 = pos1.operator+(pos2);
	c1105 pos3 = pos1 + pos2;		// �̰� 28�࿡ �ڵ�ó�� ��ȯ�Ǿ� ������ �ȴ�.
									//	1105 pos4 = pos1 - pos2;	// ������ ���� �߻�. operator-() �Լ� ���� �ʿ�
	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();


	return 0;
}