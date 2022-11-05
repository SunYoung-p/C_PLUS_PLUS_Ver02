#include <iostream>

using namespace std;

class EasyClass
{
private:
	int num;
public:
	void InitNum(int n)
	{
		num = n;
	}
	int GetNum() const
	{
		return num;
	}
	void ShowNum() const		// const �Լ����� �ٸ� �Լ� ȣ�� ��,  �ش� �Լ��� const���� ��
	{
		cout << GetNum() << endl;
	}

};

class EasyClass2
{
private:
	int num;
public:
	void InitNum(int n)
	{
		num = n;
	}
	int GetNum() const
	{
		return num;
	}
};

class LiveClass
{
private:
	int num;
public:
	void InitNum(const EasyClass2 &easy)		// const Ŭ�������� �Լ� ��� ��, �ش� �Լ��� const���� ��
	{
		num = easy.GetNum();
	}
};

int Const_Error_Example()
{
	EasyClass n;

	n.InitNum(100);

	n.ShowNum();




	getchar();
	getchar();
	return 0;
}