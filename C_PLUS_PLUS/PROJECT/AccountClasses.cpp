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


int HighCreditAccount::GetMoney() const
{
	return myMoney;
}

void HighCreditAccount::PlusMoney(int money)
{
	switch (level)
	{
		case 1: ratio += AccountRatio::LEVEL_A; break;
		case 2: ratio += AccountRatio::LEVEL_B; break;
		case 3: ratio += AccountRatio::LEVEL_C; break;
		default:
			break;
	}

	myMoney += money + (money * ratio / 100);
}

void HighCreditAccount::MinusMoney(int money)
{
	if (myMoney < money)
	{
		cout << "ÀÜ¾× ºÎÁ·" << endl << endl;
		return;
	}

	myMoney -= money;
}



