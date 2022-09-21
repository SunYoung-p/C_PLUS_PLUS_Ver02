#include <iostream>
#include "FruitBuyer.h"
#include "FruitSeller.h"

using namespace std;

int RunFruitBuyer()
{
	FruitBuyer buyer;
	if (!buyer.InitBuyer(-1, -1))
		cout << "buyer �ʱ�ȭ ����" << endl;

	if (!buyer.InitBuyer(5000, 0))
		cout << "buyer �ʱ�ȭ ����" << endl;

	FruitSeller seller;
	if (!seller.InitSeller(10000, -1, 1000))
		cout << "seller �ʱ�ȭ ����" << endl;

	if (!seller.InitSeller(10000, 10, 1000))
		cout << "seller �ʱ�ȭ ����" << endl;


	int n = 0, m = 0;
	bool re;

	while (1)
	{
		cout << "��� ���� ���, ���� �Է� (���� -1 -1)  :  ";
		cin >> n >> m;

		if (n == -1 && m == -1)
			break;

		re = buyer.BuyFurit(seller, n, m);
		if (re)
		{
			cout << "���� �Ϸ�" << endl;
		}
		else
		{
			cout << "���� ����! �ٽ� �Է��ϼ���" << endl;
		}

		cout << endl;
	}

	cout << endl << endl;
	seller.ShowInfo();
	buyer.ShowInfo();

	getchar();
	getchar();
	return 0;
}