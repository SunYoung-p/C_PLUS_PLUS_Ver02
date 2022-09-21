#include <iostream>
#include "CoffeeBuyer.h"
#include "CoffeeSeller.h"
using namespace std;

CoffeeBuyer::CoffeeBuyer(int money, int cnt)
{
	mymoney = money;
	CntCoffee = cnt;
	cout << "커피 바이어 초기화 성공" << endl;
}
void CoffeeBuyer::ShowInfo()
{
	cout << "커피 바이어의 남은 돈 : " << mymoney << endl;
	cout << "커피 바이어가 갖고 있는 커피 개수 : " << CntCoffee << endl;
}
int CoffeeBuyer::GetMoney()
{
	return mymoney;
}
int CoffeeBuyer::GetCntCoffee()
{
	return CntCoffee;
}
int CoffeeBuyer::BuyCoffee(int money, int cnt, CoffeeSeller& seller)
{
	if (mymoney < money)
	{
		cout << "현재 갖고 있는 돈이 부족합니다" << endl;
		return -1;
	}

	if (seller.SellCoffee(cnt, money) == -1)
	{
		cout << "커피 바이어가 구매를 실패했습니다" << endl;
		return -1;
	}

	mymoney -= money;
	CntCoffee += cnt;
	cout << "커피 바이어 커피 구매 성공" << endl;

	return cnt;
}