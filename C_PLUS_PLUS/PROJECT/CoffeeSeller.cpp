#include <iostream>
#include "CoffeeSeller.h"
using namespace std;

void CoffeeSeller::ShowInfo()
{
	cout << "Seller의 현재 잔고 : " << mymoney << endl;
	cout << "Seller에게 남은 커피 잔 수 : " << CntCoffee << endl;
}

int CoffeeSeller::GetPrice()
{
	return price;
}
int CoffeeSeller::GetMyMoney()
{
	return mymoney;
}
int CoffeeSeller::GetCntCoffee()
{
	return CntCoffee;
}

int CoffeeSeller::SellCoffee(int n, int money)
{
	if (n < 1 || money < price)
	{
		cout << "사려고 하는 커피 개수 혹은 구매 금액이 잘못되었습니다" << endl;
		return -1;
	}

	if (n > CntCoffee)
	{
		cout << "남은 커피가 부족합니다" << endl;
		return -1;
	}

	if (n*price != money)
	{
		cout << "구매 금액이 모자라거나 너무 많이 받았습니다" << endl;
		return -1;
	}

	mymoney += money;
	CntCoffee -= n;
	//	cout << mymoney << " " << money << " " << CntCoffee << " " << n << endl;
	cout << "Coffee 판매 성공" << endl;
	return n;
}

CoffeeSeller::CoffeeSeller(int cnt, int money, int pri)
{
	CntCoffee = cnt;
	mymoney = money;
	price = pri;

	cout << "CoffeeSeller 초기화 성공" << endl;
}