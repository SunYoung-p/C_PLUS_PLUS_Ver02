#include <iostream>
#include "CoffeeBuyer.h"
#include "CoffeeSeller.h"
using namespace std;

int CoffeeManager()
{
	CoffeeBuyer buyer(5000, 0);
	CoffeeSeller seller(10, 0, 1000);

	int n = 0, sel = 0, money = 0, cnt = 0;

	while (true)
	{
		cout << "커피를 구매하시겠습니까? (yes 1 / no any keys)  ";
		cin >> sel;

		if (sel != 1)
		{
			cout << "커피 구매 시뮬레이션 종료" << endl;
			break;
		}


		cout << "커피를 살 돈은? (1개 당 가격 : " << seller.GetPrice() << ") ";
		cin >> money;

		cout << "커피 개수는 ? ";
		cin >> cnt;

		buyer.BuyCoffee(money, cnt, seller);

		cout << endl << endl;
	}

	buyer.ShowInfo();
	seller.ShowInfo();

	return 0;
}