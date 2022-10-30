#include <iostream>
#include "Account.h"
#include "AccountClasses.h"
#include "AccountHandler.h"
using namespace std;

// 생성자
AccountHandler::AccountHandler()
{
	idx = -1;
	ACCOUNT_CNT = 100;
}

// 소멸자
AccountHandler::~AccountHandler()
{
	for (int i = 0; i < ACCOUNT_CNT; i++)
	{
		if (i > idx)
			break;

		delete info[i];
	}

	cout << "메모리 삭제 완료 \n";
}

// 전달받은 ID에 대한 index 확인
int AccountHandler::GetIdxBank(char *id)
{
	for (int i = 0; i < ACCOUNT_CNT; i++)
	{
		if (i > idx)
			break;

		if (strcmp(info[i]->GetID(), id) == 0)
		{
			// cout << i << endl;
			return i;
		}
	}

	return -1;
}

// 전체 메뉴 출력
void AccountHandler::PrintMenu() const
{
	cout << "-----Menu-----" << endl
		<< "1. 계좌개설" << endl
		<< "2. 입 금" << endl
		<< "3. 출 금" << endl
		<< "4. 계좌정보 전체 출력" << endl
		<< "5. 프로그램 종료" << endl
		<< "선택: ";
}

// 계좌 개설
void AccountHandler::MakeAccount()
{
	int sel = 0;

	cout << "\n[계좌종류선택]\n";
	cout << "1. 보통예금계좌  2. 신용신뢰계좌 \n";
	cout << "선택: ";
	cin >> sel;
	cin.ignore(INT_MAX, '\n');

	switch (sel)
	{
	case 1:
		info[++idx] = MakeNormalAccount();
		break;
	case 2:
		//val = MakeCreditAccount();
		break;
	default:
		cout << "잘못된 선택 입니다" << endl << endl;
		return;
		break;
	}

	/*
	for (int i = 0; i < ACCOUNT_CNT; i++)
	{
		if (i > idx)
			break;

		if (strcmp(val->GetID(), id) == 0)
		{
			cout << "ID 중복 에러 \n";
			return;
		}
	}
	*/
}

NormalAccount &MakeNormalAccount()
{
	char id[20] = { 0 }, name[20] = { 0 };
	int money = 0;
	int ratio = 0;

	cout << "[보통예금계좌 개설] \n";



	cout << "계좌ID : "; cin >> id;
	cout << "이   름 : "; cin >> name;
	cout << "입금액 : "; cin >> money;
	cout << "이자율 : "; cin >> ratio;

	return *(new NormalAccount(id, name, money, ratio));
}

// 입금
void AccountHandler::DepositMoney()
{
	char id[20] = { 0 };
	int money = 0, idx = 0;

	cout << "\n [현금 입금] \n";
	cout << "(1) ID 입력 : "; cin >> id;
	cout << "(2) 입금 액수 입력 : "; cin >> money;

	idx = GetIdxBank(id);

	if (idx == -1)
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

// 출금
void AccountHandler::WithDrawMoney()
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

// 전체 계좌 정보 출력
void AccountHandler::PrintAccount() const
{
	cout << "\n";

	for (int i = 0; i < ACCOUNT_CNT; i++)
	{
		if (i > idx)
			break;

		cout << "[ " << i + 1 << "번 계좌 정보 ] \n";
		info[i]->ShowInfo();
		cout << "\n";
	}
}