#include <iostream>
#include "CoffeeSeller.h"
using namespace std;

void CoffeeSeller::ShowInfo()
{
	cout << "Seller�� ���� �ܰ� : " << mymoney << endl;
	cout << "Seller���� ���� Ŀ�� �� �� : " << CntCoffee << endl;
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
		cout << "����� �ϴ� Ŀ�� ���� Ȥ�� ���� �ݾ��� �߸��Ǿ����ϴ�" << endl;
		return -1;
	}

	if (n > CntCoffee)
	{
		cout << "���� Ŀ�ǰ� �����մϴ�" << endl;
		return -1;
	}

	if (n*price != money)
	{
		cout << "���� �ݾ��� ���ڶ�ų� �ʹ� ���� �޾ҽ��ϴ�" << endl;
		return -1;
	}

	mymoney += money;
	CntCoffee -= n;
	//	cout << mymoney << " " << money << " " << CntCoffee << " " << n << endl;
	cout << "Coffee �Ǹ� ����" << endl;
	return n;
}

CoffeeSeller::CoffeeSeller(int cnt, int money, int pri)
{
	CntCoffee = cnt;
	mymoney = money;
	price = pri;

	cout << "CoffeeSeller �ʱ�ȭ ����" << endl;
}