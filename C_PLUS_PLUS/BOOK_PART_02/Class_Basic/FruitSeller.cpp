#include <iostream>
#include "FruitSeller.h"

using namespace std;
/*
FruitSeller::FruitSeller(int n) : APPLE_PRICE_2(n) // 멤버 이니셜라이저로 const 상수 초기화
{

}
*/

bool FruitSeller::InitSeller(int money, int numFruit, int price)
{
	if (money < 0 || numFruit < 0 || price < 1)
	{
		cout << "초기값이 잘못되었습니다" << endl;
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
		cout << "구매할 사과 개수와 전달받은 액수가 잘못되었습니다" << endl;
		return -1;
	}

	if(numOfFruit < numFruit)
	{
		cout << "남은 사과가 없습니다" << endl;
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
	cout << "=====Seller 정보=====" << endl
		<< "남은 사과 개수 : " << numOfFruit << endl
		<< "남은 돈 : " << myMoney << endl;
}