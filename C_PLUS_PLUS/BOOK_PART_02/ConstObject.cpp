#include <iostream>
using namespace std;

class SoSimple0923
{
private:
	int num;
public:
	SoSimple0923(int n) : num(n)
	{

	}
	SoSimple0923& AddNum(int n)
	{
		num += n;
		return *this;
	}
	void ShowData() const	// ������ ���� �� ������ ���� �Լ����� const�� �ٿ���, const ��ü�� ȣ���� �� �ְԲ� �ϱ�
	{
		cout << "num: " << num << endl;
	}
};

int ConstObject(void)
{
	SoSimple0923 obj(7);
	obj.AddNum(20);
	obj.ShowData();
	return 0;
}