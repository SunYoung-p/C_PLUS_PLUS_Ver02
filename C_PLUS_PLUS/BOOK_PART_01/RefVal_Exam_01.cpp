#include <iostream>

using namespace std;

int PlusValue(int&);
int ChangeValue(int &);
int SwapPointer(int *(&n), int *(&m));

int refExam_main()
{
	const int num = 12;

	const int* m = &num;

	const int *(&o) = m;

	cout << *m << " " << *o << endl;


	getchar();
	getchar();

	return 0;
}

int PlusValue(int &n)
{
	n++;

	return 1;
}

int ChangeValue(int &n)
{
	n *= -1;

	return 1;
}

int SwapPointer(int *(&n), int *(&m))
{
	int * o;

	o = n;
	n = m;
	m = o;

	return 1;
}

void RefExam_01()
{
	int n = 10;

	cout << n << endl;
	PlusValue(n);
	cout << n << endl;
	ChangeValue(n);
	cout << n << endl;

	int m = 10;
	int *o = &n;
	int *p = &m;

	cout << *o << " " << *p << endl;
	SwapPointer(o, p);
	cout << *o << " " << *p << endl;
}