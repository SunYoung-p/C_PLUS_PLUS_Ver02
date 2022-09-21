#include <iostream>

using namespace std;

void no1();
void no2();
void no3();
void no4();

void no1()
{
	int n = 0, m = 0;

	cin >> n >> m;

	cout << n * (m % 10) << endl;
	cout << n * (m / 10 % 10) << endl;
	cout << n * (m / 100) << endl;
	cout << n * m << endl;
}

void no2()
{
	cout << "         ,r\'\"7" << endl;
	cout << "r`-_   ,'  ,/" << endl;
	cout << " \\. \". L_r\'" << endl;
	cout << "   `~\\/" << endl;
	cout << "      |" << endl;
	cout << "      |" << endl;
}

void no3()
{
	int n = 0, m = 0;

	cin >> n >> m;

	if (n > m)
		cout << ">" << endl;
	else if (n < m)
		cout << "<" << endl;
	else
		cout << "==" << endl;
}

void no4()
{
	int n = 0;

	cin >> n;

	if (n >= 90)
		cout << "A" << endl;
	else if (n >= 80 && n < 90)
		cout << "B" << endl;
	else if (n >= 70 && n < 80)
		cout << "C" << endl;
	else if (n >= 60 && n < 70)
		cout << "D" << endl;
	else
		cout << "F" << endl;
}