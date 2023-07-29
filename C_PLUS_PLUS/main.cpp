#include <iostream>

using namespace std;
namespace n230930
{
	void PrintMenu()
	{
		cout << "-----Menu-----" << endl
			<< "1. ���°���" << endl
			<< "2. �� ��" << endl
			<< "3. �� ��" << endl
			<< "4. �������� ��ü ���" << endl
			<< "5. ���α׷� ����" << endl
			<< "����: ";
	}

	class BankInfo
	{
	private:
		int ID;
		char name[30];
		int money;
	public:
		BankInfo()
		{
			SetMoney(0);
			SetID(0);
		}
		const int GetID() { return ID; }
		const char* GetName() { return name; }
		const int Getmoney() { return money; }
		void SetMoney(int m) { money = m; }
		void PlusMoney(int m) { money += m; }
		void SetName(char * str) { strcpy_s(name, strlen(str) + 1, str); }
		void SetID(int id) { ID = id; }
	};

	class BankApp
	{
	private:
		BankInfo Info[10];

	public:
		BankApp()
		{
		}
		int CreatID()
		{
			BankInfo n;
			cout << "[���°���]" << endl;

			cout << "����ID: " << endl;
			int id;
			cin >> id;
			n.SetID(id);

			cout << "�� ��: " << endl;
			char name[30];
			cin >> name;
			n.SetName(name);

			cout << "�Աݾ�: " << endl;
			int money;
			cin >> money;
			n.SetMoney(money);

			for (int i = 0; i < 10; i++)
			{
				if (Info[i].GetID() == 0)
				{
					Info[i] = n;
					return 1;
				}
			}

			return 0;
		}
		int InputMoney(int id, int money)
		{
			for (int i = 0; i < 10; i++)
			{
				if (Info[i].GetID() == id)
				{
					Info[i].PlusMoney(money);

					return Info[i].Getmoney();
				}
			}
		}
	};
}
using namespace n230930;

int main()
{
	BankApp app;
	int sel = 0;

	while (sel != 5)
	{
		PrintMenu();
		cin >> sel;
		cout << "\n";

		switch (sel)
		{
		case 1: app.CreatID();  break;
		case 2: break;
		case 3: break;
		case 4: break;
		default:
			break;
		}
	}

	return 0;
}