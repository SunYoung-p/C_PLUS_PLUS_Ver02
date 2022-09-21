#include <iostream>
#include <cstring>
using namespace std;

int No3_4344()
{
	int n = 0, m = 0;
	double cnt = 0, re = 0, sum = 0, avg = 0;
	double * arr, *arr2;

	cin >> n;

	arr2 = new double[n];

	for (int i = 0; i < n; i++)
	{
		cin >> m;
		arr = new double[m];

		for (int j = 0; j < m; j++)
			cin >> arr[j];

		for (int j = 0; j < m; j++)
			sum += arr[j];

		avg = sum / m;

		for (int j = 0; j < m; j++)
		{
			if (arr[j] > avg)
				cnt++;
		}

		arr2[i] = cnt / m * 100;

		m = sum = avg = cnt = 0;

		delete[] arr;
	}

	cout << fixed;
	cout.precision(3);

	for (int i = 0; i < n; i++)
	{
		cout << arr2[i] << "%" << endl;
	}

	delete[] arr2;
	return 0;
}

void No1_3052()
{
	int arr[10] = { 0 };
	int cnt[42] = { 0 };
	int sum = 0;

	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < 10; i++)
	{
		arr[i] = arr[i] % 42;
	}

	for (int i = 0; i < 10; i++)
	{
		cnt[arr[i]]++;
	}

	for (int i = 0; i < 42; i++)
	{
		if (cnt[i] > 0)
			sum++;
	}

	cout << sum << endl;
}

void No2_1546()
{
	int cnt = 0;
	double max = 0, sum = 0;
	double *arr;
	double re = 0;

	cin >> cnt;
	arr = new double[cnt];

	for (int i = 0; i < cnt; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < cnt; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}

	for (int i = 0; i < cnt; i++)
	{
		arr[i] = arr[i] / max * 100;
	}

	for (int i = 0; i < cnt; i++)
	{
		sum += arr[i];
	}

	re = sum / cnt;

	cout << re << endl;

	delete[] arr;
}

void No3_8958()
{
	int n = 0, score = 0, len = 0;
	char ** arr;
	int* arr2;
	cin >> n;

	arr = new char*[n];
	arr2 = new int[n];

	for (int i = 0; i < n; i++)
	{
		arr[i] = new char[100];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		len = strnlen(arr[i], 100);

		for (int j = 0; j < len; j++)
		{
			if (arr[i][j] == 'O')
			{
				score++;
				for (int o = j - 1; o >= 0; o--)
				{
					if (arr[i][o] == 'O')
						score++;
					else
						break;
				}
			}
		}

		arr2[i] = score;

		score = len = 0;
	}

	for (int i = 0; i < n; i++)
		cout << arr2[i] << endl;

	for (int i = 0; i < n; i++)
		delete[] arr[i];

	delete[] arr;
	delete[] arr2;
}