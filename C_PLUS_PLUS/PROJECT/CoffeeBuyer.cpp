#include <iostream>
#include "CoffeeBuyer.h"
#include "CoffeeSeller.h"
using namespace std;

CoffeeBuyer::CoffeeBuyer(int money, int cnt)
{
	mymoney = money;
	CntCoffee = cnt;
	cout << "Ŀ�� ���̾� �ʱ�ȭ ����" << endl;
}
void CoffeeBuyer::ShowInfo()
{
	cout << "Ŀ�� ���̾��� ���� �� : " << mymoney << endl;
	cout << "Ŀ�� ���̾ ���� �ִ� Ŀ�� ���� : " << CntCoffee << endl;
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
		cout << "���� ���� �ִ� ���� �����մϴ�" << endl;
		return -1;
	}

	if (seller.SellCoffee(cnt, money) == -1)
	{
		cout << "Ŀ�� ���̾ ���Ÿ� �����߽��ϴ�" << endl;
		return -1;
	}

	mymoney -= money;
	CntCoffee += cnt;
	cout << "Ŀ�� ���̾� Ŀ�� ���� ����" << endl;

	return cnt;
}