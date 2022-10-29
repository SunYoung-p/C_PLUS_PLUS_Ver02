#include <iostream>
using namespace std;

class c1029
{
public:
	void FirstFunc() { cout << "FirstFunc" << endl; }
};

class s1029 : public c1029
{
public:
	void SecondFunc() { cout << "SecondFunc" << endl; }
};

class d1029 : public s1029
{
public:
	void ThirdFunc() { cout << "ThirdFunc" << endl; }
};

int VertualFunc_01()
{
	d1029 *dptr = new d1029();
	s1029 *sptr = dptr;
	c1029 *cptr = sptr;

	dptr->FirstFunc();  // OK
	dptr->SecondFunc();  // OK
	dptr->ThirdFunc();		// OK

	sptr->FirstFunc();	// OK
	sptr->SecondFunc();		// OK
							// sptr->ThirdFunc();		// Error

	cptr->FirstFunc();		// OK
							// cptr->SecondFunc();	// Error
							// cptr->ThirdFunc();			// Error

	return 0;
}