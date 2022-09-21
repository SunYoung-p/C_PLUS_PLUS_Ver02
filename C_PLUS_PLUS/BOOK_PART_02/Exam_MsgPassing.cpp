#include <iostream>

using namespace std;

class FruitSeller
{
	int numOfApples;
	int myMoney;
	int APPLE_PRICE;

public:
	void InitMembers(int price, int num, int money)
	{
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}

	int SaleApples(int money)
	{
		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;
		return num; // �Ǹ��� ������ ���� ��ȯ
	}
	void ShowSalesResult()
	{
		cout << "���� ���: " << numOfApples << endl;
		cout << "�Ǹ� ����: " << myMoney << endl;
	}

};

class FruitBuyer
{
	int myMoney; // private
	int numOfApples; // private

public:
	void InitMembers(int money)
	{
		myMoney = money;
		numOfApples = 0;
	}
	void BuyApples(FruitSeller &seller, int money)
	{
		numOfApples += seller.SaleApples(money);
		myMoney -= money;
	}
	void ShowBuyResult()
	{
		cout << "���� �ܾ�: " << myMoney << endl;
		cout << "��� ����: " << numOfApples << endl;
	}
};


int Exam_MsgPassing()
{
	FruitSeller seller;
	seller.InitMembers(2000, 10, 10000);
	seller.ShowSalesResult();


	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.ShowBuyResult();

	cout << "��� 2�� ���� ��" << endl;
	buyer.BuyApples(seller, 4000);
	buyer.ShowBuyResult();
	seller.ShowSalesResult();

	getchar();
	getchar();
	return 0;
}