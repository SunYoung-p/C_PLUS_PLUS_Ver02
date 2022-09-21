#include <iostream>

using namespace std;

void RoopExam01()
{
	int n = 0, m = 0, o = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> m >> o;
		cout << m + o << endl;
	}
}

void RoopExam02()
{
	int n = 0, sum = 0;

	cin >> n;

	for (int i = 1; i <= n; i++)
		sum += i;

	cout << sum << endl;
}


void RoopExam03_Faseter()
{
	int n = 0, m = 0, o = 0;

	ios::sync_with_stdio(false);		// »©¸é 300ms Áõ°¡
	cin.tie(NULL);		// »©¸é 1s Áõ°¡
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> m >> o;
		cout << m + o << "\n";	// endl·Î ¹Ù²Ù¸é 1s Áõ°¡
	}
}

void RoopExam05()
{
	ios::sync_with_stdio(false);		// »©¸é 300ms Áõ°¡
	cin.tie(NULL);		// »©¸é 1s Áõ°¡

	int n = 0;

	cin >> n;

	for (int i = 1; i <= n; i++)
		cout << i << "\n";
}