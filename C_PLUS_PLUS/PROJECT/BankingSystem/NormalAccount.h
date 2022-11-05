#pragma once
#include "BankingCommonDecl.h"

class NormalAccount : public Account
{
private:
	int ratio;
	int myMoney;
public:
	NormalAccount() {};
	NormalAccount(char *id, char *name, int money, int rat)
		: Account(id, name), myMoney(money), ratio(rat)
	{ }
	NormalAccount(const NormalAccount& n);
	~NormalAccount();

	virtual int GetMoney() const {	return myMoney;}
	virtual void PlusMoney(int money) { myMoney += money + (money * ratio / 100); }
	virtual void MinusMoney(int money) { myMoney -= money; }
};