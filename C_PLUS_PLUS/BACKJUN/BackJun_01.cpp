#include <iostream>

using std::cout;
using std::cin;

void HelloWorld()
{
	cout << "Hello World !" << std::endl;
}

void cats()
{
	cout << "\\    /\\" << std::endl
		<< " )  ( ')" << std::endl
		<< "(  /  )" << std::endl
		<< " \\(__)|" << std::endl;
}

void dogs()
{
	cout << "|\\_/|" << std::endl
		<< "|q p|   /}" << std::endl
		<< "( 0 )\"\"\"\\" << std::endl
		<< "|\"^\"\`    |" << std::endl
		<< "||_/=\\\\__|" << std::endl;
}

int plus()
{
	int n = 0, m = 0;

	cin >> n >> m;

	return n + m;
}