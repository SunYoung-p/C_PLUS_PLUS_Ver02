#include <iostream>
using namespace std;

int main(void)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 5; j < 10; j++)
		{
			cout << i << " * " << j << " = " << i*j << endl;
		}
		cout << endl;
	}
	return 0;
}