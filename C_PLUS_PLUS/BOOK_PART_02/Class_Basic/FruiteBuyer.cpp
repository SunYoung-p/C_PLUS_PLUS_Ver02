#include <iostream>
#include "FruitBuyer.h"

using namespace std;

bool FruitBuyer::InitBuyer(int money, int numFruit)
{
	if (money < 0 || numFruit < 0)
	{
		cout << "초기값이 잘못 전달되었습니다" << endl;
		return false;
	}

	myMoney = money;
	numOfFruite = numFruit;

	return true;
}

bool FruitBuyer::BuyFurit(FruitSeller &seller, int money, int numFruit)
{
	if (money < 0 || myMoney < money)
	{
		cout << "전달 금액이 잘못되었거나, 남은 돈이 없습니다" << endl;
		return false;
	}

	int numFruiteReuslt = seller.SellFruit(money, numFruit);
	
	if (numFruiteReuslt == -1)
		return false;

	numOfFruite += numFruiteReuslt;
	myMoney -= money;

	return true;
}


void FruitBuyer::ShowInfo()
{
	cout << "=====Buyer 정보=====" << endl
		<< "남은 사과 개수 : " << numOfFruite << endl
		<< "남은 돈 : " << myMoney << endl;
}