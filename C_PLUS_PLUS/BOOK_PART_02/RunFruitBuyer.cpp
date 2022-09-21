#include <iostream>
#include "FruitBuyer.h"
#include "FruitSeller.h"

using namespace std;

int RunFruitBuyer()
{
	FruitBuyer buyer;
	if (!buyer.InitBuyer(-1, -1))
		cout << "buyer 초기화 실패" << endl;

	if (!buyer.InitBuyer(5000, 0))
		cout << "buyer 초기화 실패" << endl;

	FruitSeller seller;
	if (!seller.InitSeller(10000, -1, 1000))
		cout << "seller 초기화 실패" << endl;

	if (!seller.InitSeller(10000, 10, 1000))
		cout << "seller 초기화 실패" << endl;


	int n = 0, m = 0;
	bool re;

	while (1)
	{
		cout << "사과 구매 비용, 개수 입력 (종료 -1 -1)  :  ";
		cin >> n >> m;

		if (n == -1 && m == -1)
			break;

		re = buyer.BuyFurit(seller, n, m);
		if (re)
		{
			cout << "구매 완료" << endl;
		}
		else
		{
			cout << "구매 실패! 다시 입력하세요" << endl;
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