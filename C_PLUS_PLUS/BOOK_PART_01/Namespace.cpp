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

int NameFunc()
{
	cout << AA::BB::CC::a << std::endl;
	cout << AA::BB::CC::b << std::endl;

	namespace AAA = AA::BB::CC;		// namespace 도 자료형으로 활용이 가능

	cout << AAA::a << std::endl;
	cout << AAA::b << std::endl;


	int n = 10;
	cout << "n의 값 : " << ::n << std::endl;	// :: 를 붙이면 전역변수에 접근됨
	n += 5;
	cout << "n의 값 : " << ::n << std::endl;
	getchar();
	getchar();
	return 0;
}

