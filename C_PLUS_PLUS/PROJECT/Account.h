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
	Account(const Account& n);
	~Account();
	void ShowInfo() const;
	
	char* GetID() const { return myID; }
	char* GetName() const { return myName; }
	int GetMoney() const { return myMoney; }
	void PlusMoney(int money) { myMoney += money; }
	void MinusMoney(int money)
	{
		if (myMoney - money >= 0)
			myMoney -= money;
	}
};