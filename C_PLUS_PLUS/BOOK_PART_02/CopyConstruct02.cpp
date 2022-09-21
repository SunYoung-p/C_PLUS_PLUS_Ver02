#include <iostream>

using namespace std;

class SoSimple3
{
private:
	int num;

public:
	SoSimple3(int n) : num(n)
	{

	}
	SoSimple3(const SoSimple3& copy) : num(copy.num)
	{
		cout << "Called SoSimple3(const SoSimple3& copy)" << endl;
	}
	SoSimple3& AddNum(int n)
	{
		num += n;
		return *this;
	}
	void ShowData()
	{
		cout << "num : " << num << endl;
	}
};

SoSimple3 SimpleFucObj(SoSimple3 ob)
{
	cout << "return ÀÌÀü" << endl;
	return ob;
}

int CopyConstructor2()
{
	SoSimple3 obj(7);
	SimpleFucObj(obj).AddNum(30).ShowData();
	obj.ShowData();

	return 0;
}