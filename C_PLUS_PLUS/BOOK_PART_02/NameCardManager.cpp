#include <iostream>
#include "NameCard.h"
using namespace std;

int NameCardManager()
{
	NameCard n("Lee", "ABCEng", "010-1111-2222", 1);
	NameCard m("Gang", "SEng", "010-3333-4444", 2);
	NameCard o("Park", "AEng", "010-5555-6666", 3);

	n.ShowNameCardInfo();
	m.ShowNameCardInfo();
	o.ShowNameCardInfo();

	getchar();
	getchar();
	return 0;
}