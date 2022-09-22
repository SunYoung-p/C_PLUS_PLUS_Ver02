#include <iostream>
#include "BOOK_OOP_PRJ_01.h"
using namespace std;

int RunBankManager() 
{ 
	bool exit = false;
	int sel = 0;

	while (exit == false)
	{
		PrintMenu();
		cin >> sel;
		cin.clear();
		cin.ignore(INT_MAX, '\n');

		switch (sel)
		{
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithDrawMoney();
			break;
		case SHOWINFO:
			PrintAccount();
			break;
		case EXIT:
			ExitBank();
			exit = true;
			break;
		default:
			cout << "�߸��� �� �Է� \n";
			break;
		}


		cout << "\n\n";

	}

	return 0;
}

/* ���� ���� */
Account * info[ACCOUNT_CNT];
int idx;

Account::Account(char *id, char *name, int money)
{
	int len = 0;

	len = strlen(id) + 1;
	myID = new char[len];
	strcpy_s(myID, len, id);

	len = strlen(name) + 1;
	myName = new char[len];
	strcpy_s(myName, len, name);

	myMoney = money;
}

Account::Account(const Account& n)
{
	int len = 0;
	len = strlen(n.myID) + 1;
	myID = new char[len];
	strcpy_s(myID, len, n.myID);

	len = strlen(n.myName) + 1;
	myName = new char[len];
	strcpy_s(myName, len, n.myName);

	myMoney = n.myMoney;
}

Account::~Account()
{
	delete[] myName;
	delete[] myID;
}

int GetIdxBank(char *id)
{
	for (int i = 0; i < ACCOUNT_CNT; i++)
	{
		if (info[i] == NULL)
			break;

		if (strcmp(info[i]->GetID(), id) == 0)
		{
			// cout << i << endl;
			return i;
		}
	}

	return -1;
}

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

void MakeAccount()
{
	char id[20] = { 0 }, name[20] = { 0 };
	int money = 0;

	cout << "\n [���� ����] \n";
	cout << "(1) ID �Է� : "; cin >> id;
	cout << "(2) Name �Է� : "; cin >> name;
	cout << "(3) Money �Է� : "; cin >> money;

	for (int i = 0; i < ACCOUNT_CNT; i++)
	{
		if (info[i] == NULL)
			break;

		if (strcmp(info[i]->GetID(), id) == 0)
		{
			cout << "ID �ߺ� ���� \n";
			return;
		}
	}

	info[idx] = new Account(id, name, money);

	idx++;
}

void DepositMoney()
{
	char id[20] = { 0 };
	int money = 0, idx = 0;

	cout << "\n [���� �Ա�] \n";
	cout << "(1) ID �Է� : "; cin >> id;
	cout << "(2) �Ա� �׼� �Է� : "; cin >> money;

	idx = GetIdxBank(id);

	if (idx == -1 )
	{
		cout << "ID�� �������� �ʽ��ϴ� \n";
		return;
	}
	else if (money < 0)
	{
		cout << "�Ա� �׼��� 0�� ���� �۽��ϴ� \n";
		return;
	}
	else
	{
		info[idx]->PlusMoney(money);
	}
}

void WithDrawMoney()
{
	char id[20] = { 0 };
	int money = 0, idx = 0;

	cout << "\n [���� ���] \n";
	cout << "(1) ID �Է� : "; cin >> id;
	cout << "(2) ��� �׼� �Է� : "; cin >> money;

	idx = GetIdxBank(id);

	if (idx == -1)
	{
		cout << "ID�� �������� �ʽ��ϴ� \n";
		return;
	}
	else if (money < 0)
	{
		cout << "��� �׼��� 0�� ���� �۽��ϴ� \n";
		return;
	}
	else if (info[idx]->GetMoney() - money < 0)
	{
		cout << "�ܾ��� �����մϴ� \n";
		return;
	}
	else
	{
		info[idx]->MinusMoney(money);
	}
}

void PrintAccount()
{
	cout << "\n";

	for (int i = 0; i < ACCOUNT_CNT; i++)
	{
		if (info[i] == NULL)
			break;

		cout << "[ " << i + 1 << "�� ���� ���� ] \n";
		info[i]->ShowInfo();
		cout << "\n";
	}
}

void ExitBank()
{
	for (int i = 0; i < ACCOUNT_CNT; i++)
	{
		if (info[i] == NULL)
			break;

		delete info[i];
	}

	cout << "�޸� ���� �Ϸ� \n";
}

void Account::ShowInfo()
{
	cout << "ID : " << GetID() << endl;
	cout << "Name : " << GetName() << endl;
	cout << "Money : " << GetMoney() << endl;
}