#include <iostream>
#include <time.h>

using std::cout;
using std::cin;

int Game()
{
	int n = 0, m = 0;
	int w = 0, l = 0, d = 0;

	srand((unsigned int)time(NULL));

	do
	{
		cout << "����(1), ����(2), ��(3) �� ���� (���� -1) : ";
		cin >> m;

		n = rand() % 3 + 1;

		if (n == m)
		{
			cout << "�����ϴ� !" << std::endl << std::endl;
			d++;
		}
		else if (
			(n == 1 && m == 3) ||
			(n == 2 && m == 1) ||
			(n == 3 && m == 2)
			)
		{
			w++;
			cout << "�̰���ϴ�!" << std::endl << std::endl;
		}
		else if (
			(n == 1 && m == 2) ||
			(n == 2 && m == 3) ||
			(n == 3 && m == 1)
			)
		{
			l++;
			cout << "�����ϴ�!" << std::endl << std::endl;
		}
	} while (m != -1);


	cout << std::endl << "�� : " << w << std::endl
		<< "�� : " << l << std::endl
		<< "�� : " << d << std::endl;

	fflush(stdin);
	getchar();
	getchar();

	return 0;
}