#include <iostream>
#include "FruitBuyer.h"

using namespace std;

bool FruitBuyer::InitBuyer(int money, int numFruit)
{
	if (money < 0 || numFruit < 0)
	{
		cout << "�ʱⰪ�� �߸� ���޵Ǿ����ϴ�" << endl;
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
		cout << "���� �ݾ��� �߸��Ǿ��ų�, ���� ���� �����ϴ�" << endl;
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
	cout << "=====Buyer ����=====" << endl
		<< "���� ��� ���� : " << numOfFruite << endl
		<< "���� �� : " << myMoney << endl;
}