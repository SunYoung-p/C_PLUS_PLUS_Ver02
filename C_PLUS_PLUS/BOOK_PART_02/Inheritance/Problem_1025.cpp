#include <iostream>
using namespace std;

class Rect1025
{
private:
	int width;
	int height;
public:
	Rect1025(int n, int m) : width(n), height(m)
	{ }
	void ShowAreaInfo()
	{
		cout << "면적 : " << width * height << endl;
	}
};

class Squ1025 : public Rect1025
{
private:
	int width;
public:
	Squ1025(int n) : width(n), Rect1025(0, 0)
	{ }
	Squ1025(int n, int m) : width(-1), Rect1025(n, m)
	{ }
	void ShowAreaInfo()
	{
		if (width != -1)
			cout << "면적 : " << width * width << endl;
		else
			Rect1025::ShowAreaInfo();
	}
};

int No1()
{
	Rect1025 rec(4, 3);
	rec.ShowAreaInfo();

	Squ1025 sqr(7);
	sqr.ShowAreaInfo();

	return 0;
}


#include <iostream>
using namespace std;

class Book
{
private:
	char* title;
	char* isbn;
	int price;
public:
	Book(char* n, char* m, int p) : price(p)
	{
		int len = strlen(n) + 1;
		title = new char[len];
		strcpy_s(title, len, n);

		len = strlen(m) + 1;
		isbn = new char[len];
		strcpy_s(isbn, len, m);
	}
	~Book()
	{
		delete[] title;
		delete[] isbn;
	}
	void ShowBookInfo()
	{
		cout << "제목 : " << title << endl;
		cout << "ISBN : " << isbn << endl;
		cout << "가격 : " << price << endl;
	}
};

class EBook : public Book
{
private:
	char* DRMKey;

public:
	EBook(char* n, char* m, int p, char* d)
		: Book(n, m, p)
	{
		int len = strlen(d) + 1;
		DRMKey = new char[len];
		strcpy_s(DRMKey, len, d);
	}

	~EBook()
	{
		delete[] DRMKey;
	}

	void ShowEBookInfo()
	{
		ShowBookInfo();
		cout << "인증키: " << DRMKey << endl;
	}
};

int No2()
{
	Book book("좋은 C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;
	EBook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();

	return 0;
}