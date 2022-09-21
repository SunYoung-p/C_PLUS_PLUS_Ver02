#include <iostream>

using namespace std;

typedef struct BookInfo
{
	char title[30];
	char writer[30];
	int page;
}Book;

typedef struct CNumber
{
	double act;
	double fake;
}Cnum;

Book GetBookInfo();
void PrintBookInfo(Book*, int);
void RunBookManager();
void GetComplexNumber();
void CountWordInFile();


void CheckSameFile()
{
	FILE* fp, *fp2;
	fopen_s(&fp, "test1.txt", "r");
	fopen_s(&fp2, "test2.txt", "r");

	if (fp == NULL || fp2 == NULL)
	{
		cout << "���� �۾� ����" << endl;
		return;
	}

	char c = 0, c2 = 0;
	bool re = true;
	c = fgetc(fp);
	c2 = fgetc(fp2);

	while (c != EOF && c2 != EOF)		// fgetc �� ���� ���� ���� �� EOF, fgets �� NULL ��ȯ
	{
		if (c != c2)
		{
			re = false;
			break;
		}

		cout << c << c2 << endl;
		c = fgetc(fp);
		c2 = fgetc(fp2);
	}

	if (re)
		cout << "�� ������ ������ ��ġ�մϴ�. " << endl;
	else
		cout << "�� ������ ���� �ٸ��ϴ�." << endl;

	fclose(fp);
	fclose(fp2);
}

void CountWordInFile()
{
	FILE* fp;
	fopen_s(&fp, "wordcnt.txt", "rt");

	if (fp == NULL)
	{
		cout << "���� �۾� ����" << endl;
		return;
	}


	char n = 0, m = 0;
	int cnt1 = 0, cnt2 = 0;
	bool IsFirst = true;
	while (1)
	{
		n = fgetc(fp);

		if (n == EOF)
			break;

		if (IsFirst)
		{
			m = n;

			IsFirst = false;
		}

		if (n == ' ' || n == '\n')
		{
			if (m == 'P')
				cnt1++;
			else if (m == 'A')
				cnt2++;

			IsFirst = true;
		}

	}

	cout << "A�� �����ϴ� �ܾ��� �� : " << cnt2 << endl
		<< "P�� �����ϴ� �ܾ��� ��: " << cnt1 << endl;

	fclose(fp);
}

void GetComplexNumber()
{
	Cnum n, m;

	cout << "���Ҽ� �Է�1[�Ǽ� ���]: ";
	cin >> n.act >> n.fake;
	cout << "���Ҽ� �Է�2[�Ǽ� ���]: ";
	cin >> m.act >> m.fake;

	cout << "���� ���] �Ǽ�: " << n.act + m.act << " , ���: "
		<< n.fake + m.fake << endl;
	cout << "���� ���] �Ǽ�: " << (n.act * m.act) - (n.fake * m.fake)
		<< " , ���: " << n.fake * m.fake << endl;
}

void RunBookManager()
{
	int cnt = 3;
	Book* book = (Book*)malloc(sizeof(Book) * cnt);

	cout << "���� ���� �Է�" << endl;

	for (int i = 0; i < cnt; i++)
		book[i] = GetBookInfo();

	cout << endl << "���� ���� ���" << endl;

	PrintBookInfo(book, cnt);

	free(book);
}

Book GetBookInfo()
{
	Book n;

	cout << "����: ";
	cin >> n.writer;

	cout << "����: ";
	cin >> n.title;

	cout << "������ ��: ";
	cin >> n.page;

	return n;
}

void PrintBookInfo(Book* n, int cnt)
{
	for (int i = 0; i < cnt; i++)
	{
		cout << "book " << i + 1 << endl;
		cout << "����: " << n[i].writer << endl;
		cout << "����: " << n[i].title << endl;
		cout << "������ ��: " << n[i].page << endl << endl;
	}
}