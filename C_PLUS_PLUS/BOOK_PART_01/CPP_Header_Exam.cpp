#include <iostream>

#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

int CPP_Header_Exam()
{
	char str[20] = "Hello World !";
	char * str2 = new char[20];
	char str3[50] = { 0 };

	strcpy_s(str2, 20, str);

	if (strcmp(str, str2) == 0)
		cout << "�� ���ڿ��� �����մϴ�" << endl;

	strcat_s(str3, 20, str2);
	cout << str3 << endl;

	delete[] str2;


	srand(time(NULL));

	for (int i = 0; i < 5; i++)
		cout << i + 1 << " ��° ���� : " << rand() << endl;

	getchar();
	getchar();
	return 0;
}