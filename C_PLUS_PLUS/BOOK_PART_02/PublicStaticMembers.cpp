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
	cout << c1014::simObjcnt << " ¹øÂ° c1014 °´Ã¼" << endl;
	c1014 sim1;
	c1014 sim2;

	cout << c1014::simObjcnt << " ¹øÂ° c1014 °´Ã¼" << endl;
	cout << sim1.simObjcnt << " ¹øÂ° c1014 °´Ã¼" << endl;
	cout << sim2.simObjcnt << " ¹øÂ° c1014 °´Ã¼" << endl;
	return 0;
}