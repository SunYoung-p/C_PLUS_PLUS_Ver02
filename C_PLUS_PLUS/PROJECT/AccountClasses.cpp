#include <iostream>
#include "AccountClasses.h"
using namespace std;

NormalAccount::NormalAccount(const NormalAccount& n)
{
	//
}

NormalAccount::~NormalAccount()
{
	//
}

int NormalAccount::GetMoney() const
{
	return myMoney;
}

void NormalAccount::PlusMoney(int money)
{
	myMoney += money + (money * ratio / 100);
}

void NormalAccount::MinusMoney(int money)
{
	if (myMoney < money)
	{
		cout << "ÀÜ¾× ºÎÁ·" << endl << endl;
		return;
	}

	myMoney -= money;
}