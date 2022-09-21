#pragma once
#include "FruitSeller.h"

class FruitBuyer
{
private:
	int myMoney;
	int numOfFruite;
public:
	bool InitBuyer(int money, int numFruit);
	bool BuyFurit(FruitSeller &seller, int money, int numFruit);
	void ShowInfo();
};