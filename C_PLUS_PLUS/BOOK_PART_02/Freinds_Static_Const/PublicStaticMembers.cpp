#include <iostream>

using namespace std;

class c1014
{
public:
	static int simObjcnt;
public:
	c1014()
	{
		simObjcnt++;
	}
};
int c1014::simObjcnt = 0;

int PublicStaticMembers()
{
	cout << c1014::simObjcnt << " ��° c1014 ��ü" << endl;
	c1014 sim1;
	c1014 sim2;

	cout << c1014::simObjcnt << " ��° c1014 ��ü" << endl;
	cout << sim1.simObjcnt << " ��° c1014 ��ü" << endl;
	cout << sim2.simObjcnt << " ��° c1014 ��ü" << endl;
	return 0;
}