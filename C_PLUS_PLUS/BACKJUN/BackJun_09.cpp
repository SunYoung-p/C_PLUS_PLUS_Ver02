#include <iostream>
using namespace std;

void No1_0814()
{
	int arr[6] = { 0 };
	int re = 1;

	for (int i = 0; i < 6; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < 6; i++)
	{
		if (i > 1)
			re = 2;

		if (i > 4)
			re = 8;

		cout << re - arr[i] << " ";
	}
}

void No2_0814()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int sum = 0, cnt = 0;
	int* arr, *arr2;

	cin >> sum >> cnt;

	arr = new int[cnt];
	arr2 = new int[cnt];
	for (int i = 0; i < cnt; i++)
	{
		cin >> arr[i] >> arr2[i];
	}

	int sum2 = 0;
	for (int i = 0; i < cnt; i++)
	{
		sum2 += arr[i] * arr2[i];
	}

	if (sum == sum2)
		cout << "Yes";
	else
		cout << "No";

	delete[] arr;
	delete[] arr2;
}