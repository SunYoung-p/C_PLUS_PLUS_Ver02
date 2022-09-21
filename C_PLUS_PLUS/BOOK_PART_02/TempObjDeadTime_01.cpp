#include <iostream>

using namespace std;

class Temporary
{
private:
	int num;
public:
	Temporary(int n) : num(n)
	{
		cout << "create obj: " << num << endl;
	}
	~Temporary()
	{
		cout << "destroy obj: " << num << endl;
	}
	void ShowTempInfo()
	{
		cout << "My num is " << num << endl;
	}
};
int TempObjDeadTime_01()
{
	Temporary(100);
	cout << "******** after make!" << endl << endl;

	Temporary(200).ShowTempInfo();
	cout << "******** after make!" << endl << endl;

	const Temporary &ref = Temporary(300);	// End of Main 이후에 죽음 = 임시객체에 이름을 붙일 경우
	cout << "******** End of Main!" << endl << endl;
	return 0;
}