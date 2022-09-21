#pragma once
class CoffeeSeller
{
private:
	int mymoney;
	int price;
	int CntCoffee;
public:
	CoffeeSeller(int cnt, int money, int pri);
	void ShowInfo();
	int GetPrice();
	int GetMyMoney();
	int GetCntCoffee();
	int SellCoffee(int n, int money);
};