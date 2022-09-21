#include <iostream>

using namespace std;

int run_main2()
{
	int n = 0, m = 0, o = 0;

	cin >> n >> m >> o;

	if (n == m && n == o)
	{
		cout << 10000 + n * 1000 << endl;
	}
	else if (n == m || n == o)
	{
		cout << 1000 + n * 100 << endl;
	}
	else if (m == o)
	{
		cout << 1000 + m * 100 << endl;
	}
	else
	{
		if (n > m && n > o)
			cout << n * 100 << endl;
		else if (m > n && m > o)
			cout << m * 100 << endl;
		else
			cout << o * 100 << endl;
	}

	getchar();
	getchar();
	return 0;
}

void YunYear()
{
	int n = 0;

	cin >> n;

	if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0)
	{
		cout << "1" << endl;
	}
	else
	{
		cout << "0" << endl;
	}
}

void GetQuadrant()
{
	int n = 0, m = 0;

	cin >> n;
	cin >> m;

	if (n > 0 && m > 0)
		cout << "1" << endl;
	else if (n > 0 && m < 0)
		cout << "4" << endl;
	else if (n < 0 && m > 0)
		cout << "2" << endl;
	else
		cout << "3" << endl;
}

void GetAlramTime()
{
	int n = 0, m = 0, o = 0;

	cin >> n >> m;

	o = (n * 60 + m) - 45;

	if (o > 59)
	{
		cout << o / 60 << " " << o % 60 << endl;
	}
	else if (o < 0)
	{
		cout << "23 " << 60 + o << endl;
	}
	else
	{
		cout << "0 " << o << endl;
	}
}

void GetOvenTime()
{
	int n = 0, m = 0, o = 0, p = 0;

	cin >> n >> m;
	cin >> o;

	p = (n * 60 + m) + o;

	if (p / 60 > 23) // 조건 중복  (p/60 > 23)
	{
		cout << (p / 60) - 24 << " " << p % 60 << endl;
	}
	else if (p > 59)
	{
		cout << p / 60 << " " << p % 60 << endl;
	}
	else
	{
		cout << "0 " << p << endl;
	}
}