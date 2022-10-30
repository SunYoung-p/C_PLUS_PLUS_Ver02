#pragma once
#include "Account.h"

class AccountHandler
{
private:
	Account * info[100];
	int idx;
	int ACCOUNT_CNT;

public:
	AccountHandler();
	~AccountHandler();
	int GetIdxBank(char *id);
	void PrintMenu() const;
	void MakeAccount();
	void DepositMoney();
	void WithDrawMoney();
	void PrintAccount() const;
	NormalAccount & MakeNormalAccount();
	/* enum »ó¼ö */
	enum KEY
	{
		MAKE = 1,
		DEPOSIT,
		WITHDRAW,
		SHOWINFO,
		EXIT
	};

};

class AccountRatio
{
public:
	static const int LEVEL_A = 7;
	static const int LEVEL_B = 4;
	static const int LEVEL_C = 2;
};