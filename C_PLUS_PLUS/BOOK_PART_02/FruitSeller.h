#pragma once
class FruitSeller
{
private:
	int myMoney;
	int numOfFruit;
	int APPLE_PRICE;
	// const int APPLE_PRICE_2;
public:
	// FruitSeller(int n);
	bool InitSeller(int money, int numFruit, int price);
	int SellFruit(int money, int numFruit);
	int GetFruitePrice() const;
	void ShowInfo();
};