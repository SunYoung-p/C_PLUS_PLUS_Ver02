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
		cout << "파일 작업 실패" << endl;
		return;
	}

	char c = 0, c2 = 0;
	bool re = true;
	c = fgetc(fp);
	c2 = fgetc(fp2);

	while (c != EOF && c2 != EOF)		// fgetc 는 파일 끝에 도달 시 EOF, fgets 는 NULL 반환
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
		cout << "두 파일은 완전히 일치합니다. " << endl;
	else
		cout << "두 파일은 서로 다릅니다." << endl;

	fclose(fp);
	fclose(fp2);
}

void CountWordInFile()
{
	FILE* fp;
	fopen_s(&fp, "wordcnt.txt", "rt");

	if (fp == NULL)
	{
		cout << "파일 작업 실패" << endl;
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

	cout << "A로 시작하는 단어의 수 : " << cnt2 << endl
		<< "P로 시작하는 단어의 수: " << cnt1 << endl;

	fclose(fp);
}

void GetComplexNumber()
{
	Cnum n, m;

	cout << "복소수 입력1[실수 허수]: ";
	cin >> n.act >> n.fake;
	cout << "복소수 입력2[실수 허수]: ";
	cin >> m.act >> m.fake;

	cout << "합의 결과] 실수: " << n.act + m.act << " , 허수: "
		<< n.fake + m.fake << endl;
	cout << "곱의 결과] 실수: " << (n.act * m.act) - (n.fake * m.fake)
		<< " , 허수: " << n.fake * m.fake << endl;
}

void RunBookManager()
{
	int cnt = 3;
	Book* book = (Book*)malloc(sizeof(Book) * cnt);

	cout << "도서 정보 입력" << endl;

	for (int i = 0; i < cnt; i++)
		book[i] = GetBookInfo();

	cout << endl << "도서 정보 출력" << endl;

	PrintBookInfo(book, cnt);

	free(book);
}

Book GetBookInfo()
{
	Book n;

	cout << "저자: ";
	cin >> n.writer;

	cout << "제목: ";
	cin >> n.title;

	cout << "페이지 수: ";
	cin >> n.page;

	return n;
}

void PrintBookInfo(Book* n, int cnt)
{
	for (int i = 0; i < cnt; i++)
	{
		cout << "book " << i + 1 << endl;
		cout << "저자: " << n[i].writer << endl;
		cout << "제목: " << n[i].title << endl;
		cout << "페이지 수: " << n[i].page << endl << endl;
	}
}