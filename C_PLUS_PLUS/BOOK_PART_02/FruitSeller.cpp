#include <iostream>
#include "FruitSeller.h"

using namespace std;
/*
FruitSeller::FruitSeller(int n) : APPLE_PRICE_2(n) // ��� �̴ϼȶ������� const ��� �ʱ�ȭ
{

}
*/

bool FruitSeller::InitSeller(int money, int numFruit, int price)
{
	if (money < 0 || numFruit < 0 || price < 1)
	{
		cout << "�ʱⰪ�� �߸��Ǿ����ϴ�" << endl;
		return false;
	}
	myMoney = money;
	numOfFruit = numFruit;
	APPLE_PRICE = price;

	return true;
}

int FruitSeller::SellFruit(int money, int numFruit)
{
	if (money != numFruit * APPLE_PRICE)
	{
		cout << "������ ��� ������ ���޹��� �׼��� �߸��Ǿ����ϴ�" << endl;
		return -1;
	}

	if(numOfFruit < numFruit)
	{
		cout << "���� ����� �����ϴ�" << endl;
		return -1;
	}

	myMoney += money;
	numOfFruit -= (money / APPLE_PRICE);

	return numFruit;
}

int FruitSeller::GetFruitePrice() const
{
	return APPLE_PRICE;
}

void FruitSeller::ShowInfo()
{
	cout << "=====Seller ����=====" << endl
		<< "���� ��� ���� : " << numOfFruit << endl
		<< "���� �� : " << myMoney << endl;
}