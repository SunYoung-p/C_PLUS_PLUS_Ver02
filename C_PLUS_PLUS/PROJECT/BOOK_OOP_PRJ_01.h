/*
Bank Manager ���α׷�

1. Version : 2.0 (220815)
2. ������
 - ����ü AccountInfo �� Ŭ������ ����
 - AccountInfo �� �� ���� char �迭�� ���� �Ҵ� �ϴ� ������ ����
 - ��ü �迭�� ��ü ������ �迭�� ����
*/

#pragma once

/* Ŭ���� ���� */
class Account
{
private:
	char* myID;
	char* myName;
	int myMoney;

public:
	Account(char *id, char *name, int money);
	~Account();
	char* GetID() { return myID; }
	char* GetName() { return myName; }
	int GetMoney() { return myMoney; }
	void PlusMoney(int money) { myMoney += money; }
	void MinusMoney(int money)
	{ 
		if(myMoney-money >=0) 
			myMoney -= money; 
	}
	void ShowInfo();
};

/* �Լ� ���� */
int RunBankManager();
void MakeAccount();
void PrintMenu();
void WithDrawMoney();
void DepositMoney();
void PrintAccount();
void ExitBank();
int GetIdxBank(char *);

/* enum ��� */
enum KEY
{
	MAKE =1 ,
	DEPOSIT,
	WITHDRAW,
	SHOWINFO,
	EXIT
};

/* ��Ÿ ��� */
#define ACCOUNT_CNT 100