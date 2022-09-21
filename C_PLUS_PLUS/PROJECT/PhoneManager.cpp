#include <iostream>

using namespace std;

typedef struct PhoneBook
{
	char name[20];
	char number[20];
	bool IsDeleted = false;
}PB;

void Menu();
PB GetPBData();
int InserPBData(PB**, PB, int);
void Print_All(PB**, int);
int DeletePBData(PB**, int);
int SearchPBData(PB**, int);
int SaveFile(PB**, int);
int FileLoad(PB**, int*);

int run_main()
{
	int n = 0, cnt = 0;
	PB m;
	PB* data;

	if (FileLoad(&data, &cnt) == -1)
	{
		cout << "Data Load Failure" << endl << endl;
	}
	else
	{
		cout << "Data Load Success" << endl << endl;
	}

	while (n != 5)
	{
		Menu();
		cin >> n;

		switch (n)
		{
		case 1:
			cout << "[ INSERT ]" << endl;
			m = GetPBData();
			if (InserPBData(&data, m, cnt) == -1)
			{
				cout << "이미 존재하는 이름이거나, 입력이 잘못됬습니다" << endl;
			}
			else
			{
				cout << "입력 완료" << endl;
				cnt++;
			}
			break;
		case 2:
			cout << "[ DELETE ]" << endl;
			if (DeletePBData(&data, cnt) == -1)
			{
				cout << "존재하지 않는 이름이거나, 입력이 잘못됬습니다" << endl;
			}
			else
			{
				cout << "삭제 완료" << endl;
			}
			break;
		case 3:
			cout << "[ SERACH ]" << endl;
			if (SearchPBData(&data, cnt) == -1)
			{
				cout << "검색할 수 없습니다." << endl;
			}
			break;
		case 4:
			cout << "[ Print All Data ]" << endl;
			Print_All(&data, cnt);
			break;
		case 5:
			cout << "프로그램 종료" << endl;
			break;
		default:
			cout << "입력이 잘못되었습니다" << endl << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			break;
		}

		cout << endl;
	}

	if (SaveFile(&data, cnt) == -1)
	{
		cout << "파일 저장 실패 " << endl;
	}
	else
	{
		cout << "파일 저장 완료 " << endl;
	}

	free(data);

	getchar();
	getchar();
	return 0;
}

void Menu()
{
	cout << "***** MENU *****" << endl;
	cout << "1. Insert" << endl;
	cout << "2. Delete" << endl;
	cout << "3. Search" << endl;
	cout << "4. Print All" << endl;
	cout << "5. Exit" << endl;
	cout << "Choose the item: ";
}

PB GetPBData()
{
	PB n;

	cout << "Input Name: ";
	cin >> n.name;

	cout << "Input Tel Number: ";
	cin >> n.number;

	n.IsDeleted = false;

	return n;
}

int InserPBData(PB** data, PB n, int cnt)
{
	for (int i = 0; i < cnt; i++)
	{
		if (strcmp((*data)[i].name, n.name) == 0 && (*data)[i].IsDeleted == false)
			return -1;
	}

	if (cnt < 1)
		*data = (PB*)calloc(cnt + 1, sizeof(PB));
	else
		*data = (PB*)realloc(*data, sizeof(PB) * (cnt + 1));

	strcpy_s((*data)[cnt].name, n.name);
	strcpy_s((*data)[cnt].number, n.number);
	(*data)[cnt].IsDeleted = false;

	return 1;
}

void Print_All(PB** data, int cnt)
{
	for (int i = 0; i < cnt; i++)
	{
		if ((*data)[i].IsDeleted != true)
		{
			cout << "Name: ";
			cout.width(7);
			cout << std::right << (*data)[i].name << endl;
			cout << "Tel: ";
			cout.width(7);
			cout << std::right << (*data)[i].number << endl << endl;
		}
	}
}


int DeletePBData(PB** data, int cnt)
{
	char str[20] = { 0 };

	cout << "삭제할 이름 입력: ";
	cin >> str;

	for (int i = 0; i < cnt; i++)
	{
		if (strcmp((*data)[i].name, str) == 0 && (*data)[i].IsDeleted == false)
		{
			(*data)[i].IsDeleted = true;

			return 1;
		}
	}

	return -1;
}


int SearchPBData(PB** data, int cnt)
{
	char str[20] = { 0 };

	cout << "검색할 이름 입력: ";
	cin >> str;

	for (int i = 0; i < cnt; i++)
	{
		if (strcmp((*data)[i].name, str) == 0 && (*data)[i].IsDeleted == false)
		{
			cout << "검색 완료" << endl;
			cout << "Name: ";
			cout.width(7);
			cout << std::right << (*data)[i].name << endl;
			cout << "Tel: ";
			cout.width(7);
			cout << std::right << (*data)[i].number << endl;


			return 1;
		}
	}

	return -1;
}


int SaveFile(PB** data, int cnt)
{
	FILE* fp;
	int n = 0;
	fopen_s(&fp, "Phone_Data.txt", "w");

	if (fp == NULL)
	{
		return -1;
	}

	for (int i = 0; i < cnt; i++)
	{
		if ((*data)[i].IsDeleted == false)
		{
			n++;
		}
	}

	fprintf(fp, "Count:%d\n", n);
	for (int i = 0; i < cnt; i++)
	{
		if ((*data)[i].IsDeleted == false)
		{
			fprintf(fp, "Name:%s\n", (*data)[i].name);
			fprintf(fp, "Phone:%s\n", (*data)[i].number);
		}
	}

	fclose(fp);

	return 1;
}


int FileLoad(PB** data, int *cnt)
{
	FILE* fp;
	PB n;

	char str[20] = { 0 };
	char *str2 = NULL;

	fopen_s(&fp, "Phone_Data.txt", "r");
	if (fp == NULL)
	{
		return -1;
	}

	fgets(str, sizeof(str) - 1, fp);
	strtok_s(str, ":", &str2);
	*cnt = atoi(str2);

	for (int i = 0; i < *cnt; i++)
	{
		fgets(str, sizeof(str) - 1, fp);
		strtok_s(str, ":", &str2);
		strcpy_s(n.name, str2);
		n.name[strlen(n.name) - 1] = '\0';

		fgets(str, sizeof(str) - 1, fp);
		strtok_s(str, ":", &str2);
		strcpy_s(n.number, str2);
		n.number[strlen(n.name) - 1] = '\0';

		n.IsDeleted = false;

		if (i < 1)
			*data = (PB*)calloc(i + 1, sizeof(PB));
		else
			*data = (PB*)realloc(*data, sizeof(PB) * (i + 1));

		strcpy_s((*data)[i].name, n.name);
		strcpy_s((*data)[i].number, n.number);
		(*data)[i].IsDeleted = false;
	}

	fclose(fp);

	return 1;
}