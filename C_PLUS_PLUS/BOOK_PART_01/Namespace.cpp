#include <iostream>

using std::cout;
using std::cin;

namespace AA
{
	namespace BB
	{
		namespace CC
		{
			int a = 10;
			int b = 20;
		}
	}
}

int n = 10;

int Namespace()
{
	cout << AA::BB::CC::a << std::endl;
	cout << AA::BB::CC::b << std::endl;

	namespace AAA = AA::BB::CC;		// namespace �� �ڷ������� Ȱ���� ����

	cout << AAA::a << std::endl;
	cout << AAA::b << std::endl;


	int n = 10;
	cout << "n�� �� : " << ::n << std::endl;	// :: �� ���̸� ���������� ���ٵ�
	n += 5;
	cout << "n�� �� : " << ::n << std::endl;
	getchar();
	getchar();
	return 0;
}

