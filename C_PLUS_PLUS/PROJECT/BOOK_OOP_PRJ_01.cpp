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
			cout << "잘못된 값 입력 \n";
			break;
		}


		cout << "\n\n";

	}

	return 0;
}

/* 전역 변수 */
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
		<< "1. 계좌개설" << endl
		<< "2. 입 금" << endl
		<< "3. 출 금" << endl
		<< "4. 계좌정보 전체 출력" << endl
		<< "5. 프로그램 종료" << endl
		<< "선택: ";
}

void MakeAccount()
{
	char id[20] = { 0 }, name[20] = { 0 };
	int money = 0;

	cout << "\n [계좌 개설] \n";
	cout << "(1) ID 입력 : "; cin >> id;
	cout << "(2) Name 입력 : "; cin >> name;
	cout << "(3) Money 입력 : "; cin >> money;

	for (int i = 0; i < ACCOUNT_CNT; i++)
	{
		if (info[i] == NULL)
			break;

		if (strcmp(info[i]->GetID(), id) == 0)
		{
			cout << "ID 중복 에러 \n";
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

	cout << "\n [현금 입금] \n";
	cout << "(1) ID 입력 : "; cin >> id;
	cout << "(2) 입금 액수 입력 : "; cin >> money;

	idx = GetIdxBank(id);

	if (idx == -1 )
	{
		cout << "ID가 존재하지 않습니다 \n";
		return;
	}
	else if (money < 0)
	{
		cout << "입금 액수가 0원 보다 작습니다 \n";
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

	cout << "\n [현금 출금] \n";
	cout << "(1) ID 입력 : "; cin >> id;
	cout << "(2) 출금 액수 입력 : "; cin >> money;

	idx = GetIdxBank(id);

	if (idx == -1)
	{
		cout << "ID가 존재하지 않습니다 \n";
		return;
	}
	else if (money < 0)
	{
		cout << "출금 액수가 0원 보다 작습니다 \n";
		return;
	}
	else if (info[idx]->GetMoney() - money < 0)
	{
		cout << "잔액이 부족합니다 \n";
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

		cout << "[ " << i + 1 << "번 계좌 정보 ] \n";
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

	cout << "메모리 삭제 완료 \n";
}

void Account::ShowInfo()
{
	cout << "ID : " << GetID() << endl;
	cout << "Name : " << GetName() << endl;
	cout << "Money : " << GetMoney() << endl;
}