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

	virtual int GetMoney() const;
	virtual void PlusMoney(int money);
	virtual void MinusMoney(int money);
};