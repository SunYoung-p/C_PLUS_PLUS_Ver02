
#include <iostream>
using namespace std;

class Gun
{
private:
	int bullet;		// 장전된 총알의 수
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
	int handcuffs;		// 소유한 수갑의 수
						// Gun * pistol;		// 만약 Gun을 상속하지 않고 이렇게 멤버변수로 넣는다면, pistol의 초기화, 소멸자, Shot 함수 등을 별도로 다시 선언해야 한다. (상속을 쓰는 이유?)
						// 이것만 보면 안 좋아 보이지만, 전기봉이 추가된다든지 하는 상황을 대처하려면 이렇게 Gun이 지역변수로 있는 게 낫다.
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
	Police pman(5, 3);		// 총알 5, 수갑 3
	pman.Shot();
	pman.PutHandcuff();
	return 0;
}