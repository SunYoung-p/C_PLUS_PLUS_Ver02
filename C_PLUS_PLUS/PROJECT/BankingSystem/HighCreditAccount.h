/*
11/02
1. OOP 단계별 프로젝트로 Account 클래스를 상속하는 2개의 클래스를 만들고, 계좌 입금 시 이자가 붙는 방식이 다르므로
입금 함수를 가상 함수로 만들어서 적용했는데, 가상 함수 구현 부분에서
기초 클래스의 입금 함수를 가져와서 쓰면 편한데,  입금 관련 코드를 그냥 새로 만들었다.
상속 후 가상함수 설정은 잘 되었지만, 상속한 기초 클래스의 멤버 함수를 쓰는 게 아직 익숙하지 않다.
*/
#include "BankingCommonDecl.h"

class HighCreditAccount : public Account
{
private:
	int ratio;
	int myMoney;
	int level;
public:
	HighCreditAccount() {};
	HighCreditAccount(char *id, char *name, int money, int rat, int level)
		: Account(id, name), myMoney(money), ratio(rat), level(level)
	{ }
	HighCreditAccount(const HighCreditAccount& n);
	~HighCreditAccount();

	virtual int GetMoney() const { return myMoney; }
	virtual void PlusMoney(int money)
	{
		myMoney += money + (money * ratio / 100);
	}
	virtual void MinusMoney(int money) { myMoney -= money; }
};