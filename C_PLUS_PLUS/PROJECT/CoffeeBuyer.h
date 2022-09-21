#pragma once
#include "CoffeeSeller.h"

class CoffeeBuyer
{
private:
	int mymoney;
	int CntCoffee;
public:
	CoffeeBuyer(int money, int cnt);
	void ShowInfo();
	int GetMoney();
	int GetCntCoffee();
	int BuyCoffee(int money, int cnt, CoffeeSeller& seller);
};