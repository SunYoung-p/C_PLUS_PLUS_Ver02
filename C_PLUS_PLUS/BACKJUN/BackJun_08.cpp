#include <iostream>

using namespace std;

int no3_0805()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0, m = 0, o = 0, p = 1, q = 0, re = 0;
	long arr[10] = { 0 };

	cin >> n >> m >> o;

	re = n*m*o;

	for (int i = 0; i < 10; i++)
	{
		if (re < p)
			break;
		q = (re - (re / (p * 10) * (p * 10))) / p;
		arr[q] += 1;
		p *= 10;
	}

	for (int i = 0; i < 10; i++)
		cout << arr[i] << "\n";

	getchar();
	getchar();
	return 0;
}

void no1_0805()
{
	int n = 0, max = 0, min = 0;
	int* m;

	cin >> n;

	m = new int[n];

	for (int i = 0; i < n; i++)
		cin >> m[i];

	max = min = m[0];
	for (int i = 1; i < n; i++)
	{
		if (max < m[i])
			max = m[i];

		if (min > m[i])
			min = m[i];
	}

	cout << min << " " << max << "\n";

	delete[] m;
}

void no2_0805()
{
	int idx = 1, max = 0;
	int *m;

	m = new int[9];

	for (int i = 1; i <= 9; i++)
		cin >> m[i - 1];

	max = m[0];

	for (int i = 1; i <= 9; i++)
	{
		if (max < m[i - 1])
		{
			max = m[i - 1];
			idx = i;
		}
	}

	cout << max << "\n" << idx;

	delete[] m;
}