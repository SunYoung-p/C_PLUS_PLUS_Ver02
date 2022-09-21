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
		cout << "가위(1), 바위(2), 보(3) 중 선택 (종료 -1) : ";
		cin >> m;

		n = rand() % 3 + 1;

		if (n == m)
		{
			cout << "비겼습니다 !" << std::endl << std::endl;
			d++;
		}
		else if (
			(n == 1 && m == 3) ||
			(n == 2 && m == 1) ||
			(n == 3 && m == 2)
			)
		{
			w++;
			cout << "이겼습니다!" << std::endl << std::endl;
		}
		else if (
			(n == 1 && m == 2) ||
			(n == 2 && m == 3) ||
			(n == 3 && m == 1)
			)
		{
			l++;
			cout << "졌습니다!" << std::endl << std::endl;
		}
	} while (m != -1);


	cout << std::endl << "승 : " << w << std::endl
		<< "패 : " << l << std::endl
		<< "무 : " << d << std::endl;

	fflush(stdin);
	getchar();
	getchar();

	return 0;
}