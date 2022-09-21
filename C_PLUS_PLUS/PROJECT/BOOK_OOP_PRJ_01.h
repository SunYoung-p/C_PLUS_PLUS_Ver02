/*
Bank Manager 프로그램

1. Version : 2.0 (220815)
2. 변경점
 - 구조체 AccountInfo 를 클래스로 변경
 - AccountInfo 에 고객 정보 char 배열은 동적 할당 하는 것으로 변경
 - 객체 배열은 객체 포인터 배열로 변경
*/

#pragma once

/* 클래스 선언 */
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

/* 함수 선언 */
int RunBankManager();
void MakeAccount();
void PrintMenu();
void WithDrawMoney();
void DepositMoney();
void PrintAccount();
void ExitBank();
int GetIdxBank(char *);

/* enum 상수 */
enum KEY
{
	MAKE =1 ,
	DEPOSIT,
	WITHDRAW,
	SHOWINFO,
	EXIT
};

/* 기타 상수 */
#define ACCOUNT_CNT 100