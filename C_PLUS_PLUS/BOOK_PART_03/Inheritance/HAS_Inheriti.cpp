
#include <iostream>
using namespace std;

class Gun
{
private:
	int bullet;		// ������ �Ѿ��� ��
public:
	Gun(int bnum) : bullet(bnum)
	{}
	void Shot()
	{
		cout << "BBANG!" << endl;
		bullet--;
	}
};

class Police : public Gun
{
private:
	int handcuffs;		// ������ ������ ��
						// Gun * pistol;		// ���� Gun�� ������� �ʰ� �̷��� ��������� �ִ´ٸ�, pistol�� �ʱ�ȭ, �Ҹ���, Shot �Լ� ���� ������ �ٽ� �����ؾ� �Ѵ�. (����� ���� ����?)
						// �̰͸� ���� �� ���� ��������, ������� �߰��ȴٵ��� �ϴ� ��Ȳ�� ��ó�Ϸ��� �̷��� Gun�� ���������� �ִ� �� ����.
public:
	Police(int bnum, int bcuff)
		: Gun(bnum), handcuffs(bcuff)
	{ }

	void PutHandcuff()
	{
		cout << "SNAP!" << endl;
		handcuffs--;
	}
};

int HAS_Inheriti()
{
	Police pman(5, 3);		// �Ѿ� 5, ���� 3
	pman.Shot();
	pman.PutHandcuff();
	return 0;
}