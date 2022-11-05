/*
11/02
1. OOP �ܰ躰 ������Ʈ�� Account Ŭ������ ����ϴ� 2���� Ŭ������ �����, ���� �Ա� �� ���ڰ� �ٴ� ����� �ٸ��Ƿ�
�Ա� �Լ��� ���� �Լ��� ���� �����ߴµ�, ���� �Լ� ���� �κп���
���� Ŭ������ �Ա� �Լ��� �����ͼ� ���� ���ѵ�,  �Ա� ���� �ڵ带 �׳� ���� �������.
��� �� �����Լ� ������ �� �Ǿ�����, ����� ���� Ŭ������ ��� �Լ��� ���� �� ���� �ͼ����� �ʴ�.
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