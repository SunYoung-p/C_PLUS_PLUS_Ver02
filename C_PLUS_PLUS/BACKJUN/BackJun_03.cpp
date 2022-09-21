#include <iostream>

using std::cout;
using std::cin;

void Math_01()
{
	int n = 0, m = 0;
	
	cin >> n >> m;

	cout << n + m << std::endl
		<< n - m << std::endl
		<< n*m << std::endl
		<< n / m << std::endl
		<< n%m << std::endl;
}

void Joonas()
{
	char n[51] = { 0 };

	cin >> n;
	cout << n << "??!" << std::endl;
}

void ChangeYear()
{
	int n = 0;

	cin >> n;
	cout << n - 543;
}

void Remainder()
{
	int n = 0, m = 0, o = 0;

	cin >> n >> m >> o;

	cout << (n + m) % o << std::endl
		<< ((n%o) + (m%o)) % o << std::endl
		<< (n*m) % o << std::endl
		<< ((n%o) * (m%o)) % o << std::endl;
}