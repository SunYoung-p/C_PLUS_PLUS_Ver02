#include <iostream>
#include "Ring.h"

using namespace std;


int RunRingMaker()
{
	Ring ring;
	if (ring.Init(1, 1, 4, 2, 2, 9) == false)
	{
		cout << "값이 잘못되었습니다. ring 초기화 실패" << endl;
		return -1;
	}

	ring.ShowRingInfo();

	getchar();
	getchar();
	return 0;
}