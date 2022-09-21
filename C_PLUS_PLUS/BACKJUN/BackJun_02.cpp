#include <iostream>

using std::cout;
using std::cin;

int Subtraction();
int multiply();
int divid();

int Subtraction()
{
	int n = 0, m = 0;

	cin >> n >> m;

	cout << n - m << std::endl;

	return 0;
}

int multiply()
{
	int n = 0, m = 0;

	cin >> n >> m;

	cout << n * m << std::endl;

	getchar();
	getchar();
	return 0;
}

int divid()
{
	double n = 0, m = 0;

	cin >> n >> m;

	printf("%.9f", n / m);


	getchar();
	getchar();
	return 0;
}