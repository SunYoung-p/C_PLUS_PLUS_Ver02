#include	 <iostream>

using namespace std;

int No8_0731()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0, m = 0, o = 0, cnt = 0;

	cin >> n;
	m = n;

	do
	{
		if (n < 10)
			o = 0;
		else
			o = n / 10;

		n = n % 10 * 10 + (o + n % 10) % 10;

		cnt++;
	} while (n != m);

	cout << cnt << "\n";

	getchar();
	getchar();
	return 0;
}

void No1_0731()
{
	int n = 0;

	cin >> n;
	for (int i = n; i >= 1; i--)
		cout << i << "\n";
}

void No2_0731()
{
	int n = 0, m = 0, o = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> m >> o;
		cout << "Case #" << i + 1 << ": " << m
			<< " + " << o << " = " << m + o << "\n";
	}
}

void No3_0731()
{
	int n = 0;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
			cout << "*";

		cout << "\n";
	}
}

void No4_0731()
{
	int n = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1 - i; j > 0; j--)
			cout << " ";
		for (int j = 0; j < i + 1; j++)
			cout << "*";

		cout << "\n";
	}
}

void No5_0731()
{
	int n = 0, m = 0;
	int* o;


	cin >> n >> m;

	o = new int[n];

	for (int i = 0; i < n; i++)
		cin >> o[i];

	for (int i = 0; i < n; i++)
	{
		if (o[i] < m)
			cout << o[i] << " ";
	}


	delete[] o;
}

void No6_0731()
{
	int n = 0, m = 0;

	while (1)
	{
		cin >> n >> m;

		if (n == 0 && m == 0)
			break;

		cout << n + m << "\n";
	}
}


void No7_0731()
{
	int n = 0, m = 0;

	while (1)
	{
		cin >> n >> m;

		if (cin.eof())
			break;

		cout << n + m << "\n";
	}
}