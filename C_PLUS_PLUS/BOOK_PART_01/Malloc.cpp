#include <iostream>

using namespace std;

void Practice();
void Reverse(char**, int);

int Malloc_main()
{
	int * arr = (int*)calloc(5, sizeof(int));
	int cnt = 0, lang = 5, n = 0;

	while (n != -1)
	{
		cin >> n;
		arr[cnt++] = n;

		if (cnt > lang - 1)
		{
			lang += 3;
			arr = (int*)realloc(arr, sizeof(int)* lang);
		}
	}

	for (int i = 0; i < cnt - 1; i++)
		cout << i << " idx : " << arr[i] << endl;

	getchar();
	getchar();
	return 0;
}

void Practice()
{
	int* ptr = (int*)calloc(4, sizeof(int));

	for (int i = 0; i < 4; i++)
		ptr[i] = i + 1;

	for (int i = 0; i < 4; i++)
		cout << ptr[i] << endl;


	cout << "ptr 의 주소값 : " << ptr << endl;
	ptr = (int*)realloc(ptr, sizeof(int) * 6);
	cout << "ptr 의 주소값 : " << ptr << endl;
	for (int i = 0; i < 6; i++)
		cout << ptr[i] << endl;
}

void Reverse(char** str, int cnt)
{
	char n = 0;

	for (int i = 0; i < cnt / 2; i++)
	{
		n = (*str)[i];
		(*str)[i] = (*str)[cnt - 1 - i];
		(*str)[cnt - 1 - i] = n;
	}
}

void Backwards()
{
	int cnt = 0;
	char* ptr;
	cout << "문자의 개수: ";
	cin >> cnt;
	cin.ignore();

	ptr = (char*)calloc(cnt + 1, sizeof(char));

	for (int i = 0; i < cnt; i++)
	{
		ptr[i] = getchar();
	}

	cout << ptr;

	cout << endl << "거꾸로 바꿔서" << endl;

	for (int i = cnt - 1; i >= 0; i--)
		cout << ptr[i];
}