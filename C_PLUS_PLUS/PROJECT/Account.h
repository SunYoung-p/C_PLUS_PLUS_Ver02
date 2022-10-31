#pragma once
/* Ŭ���� ���� */
class Account
{
private:
	char* myID;
	char* myName;

public:
	
	Account() {};
	Account(char *id, char *name);
	Account(const Account& n);
	~Account();
	void ShowInfo() const;
	
	char* GetID() const { return myID; }
	char* GetName() const { return myName; }
	virtual int GetMoney() const = 0;
	virtual void PlusMoney(int money) = 0;
	virtual void MinusMoney(int money) = 0;
};

class AccountRatio
{
public:
	static const int LEVEL_A = 7;
	static const int LEVEL_B = 4;
	static const int LEVEL_C = 2;
};