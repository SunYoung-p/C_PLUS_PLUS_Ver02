#include <iostream>
#include "Ring.h"

using namespace std;


int RunRingMaker()
{
	Ring ring;
	if (ring.Init(1, 1, 4, 2, 2, 9) == false)
	{
		cout << "���� �߸��Ǿ����ϴ�. ring �ʱ�ȭ ����" << endl;
		return -1;
	}

	ring.ShowRingInfo();

	getchar();
	getchar();
	return 0;
}