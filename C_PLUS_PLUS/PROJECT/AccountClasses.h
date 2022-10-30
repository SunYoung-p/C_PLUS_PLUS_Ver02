#pragma once
#include "Account.h"
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

	virtual int GetMoney() const;
	virtual void PlusMoney(int money);
	virtual void MinusMoney(int money);
};