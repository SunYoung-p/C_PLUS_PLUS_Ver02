#pragma once
#include "AccountClasses.h"
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
	bool IsEmptyID(char*) const;

	NormalAccount * MakeNormalAccount();
	HighCreditAccount * MakeCreditAccount();
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

