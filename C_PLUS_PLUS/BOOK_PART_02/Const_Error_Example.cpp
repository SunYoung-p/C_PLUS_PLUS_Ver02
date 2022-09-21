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
	void ShowNum() const		// const 함수에서 다른 함수 호출 시,  해당 함수도 const여야 함
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
	void InitNum(const EasyClass2 &easy)		// const 클래스에서 함수 사용 시, 해당 함수도 const여야 함
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