#include <iostream>

using namespace std;

class SoSimple
{
private:
	int num;
	int num2;
public:
	SoSimple(int n, int m) : num(n), num2(m)
	{
	}

	SoSimple(SoSimple &copy)	// explicit Ű���带 �ٿ��ָ� = �� �ƴ϶� () �θ� Ŭ���� ���� ����
		: num(copy.num), num2(copy.num2)
	{
		cout << "Called SoSimple(SoSimple &copy)" << endl;
	}
	void ShowInfo()
	{
		cout << num << endl;
		cout << num2 << endl;
	}
};

int CopyConstruct()
{

	SoSimple s1(10, 20);
	cout << "���� �� �ʱ�ȭ ����" << endl;
	SoSimple s2 = s1; // SoSimple sim2(s1) �� ��ȯ, Ȥ�� �� ���� �����ڰ� ���ٸ�, ��� �̴ϼȶ���� �״�� �����ͼ� ����Ʈ �ڵ� �����ȴ�
					  //SoSimple s2(s1); explicit Ű���� ����, ������ �� ��ȯ = �� ()�� �ٲ�� ��, ������� �ʱ⶧���� ()�θ� �ʱ�ȭ�� ����
	cout << "���� �� �ʱ�ȭ ����" << endl;
	s2.ShowInfo();

	return 0;
}