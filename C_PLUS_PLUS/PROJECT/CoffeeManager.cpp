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
		cout << "Ŀ�Ǹ� �����Ͻðڽ��ϱ�? (yes 1 / no any keys)  ";
		cin >> sel;

		if (sel != 1)
		{
			cout << "Ŀ�� ���� �ùķ��̼� ����" << endl;
			break;
		}


		cout << "Ŀ�Ǹ� �� ����? (1�� �� ���� : " << seller.GetPrice() << ") ";
		cin >> money;

		cout << "Ŀ�� ������ ? ";
		cin >> cnt;

		buyer.BuyCoffee(money, cnt, seller);

		cout << endl << endl;
	}

	buyer.ShowInfo();
	seller.ShowInfo();

	return 0;
}