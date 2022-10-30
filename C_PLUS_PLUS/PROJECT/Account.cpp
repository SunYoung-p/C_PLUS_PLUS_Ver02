#include <iostream>
#include "Account.h"
using namespace std;

Account::Account(char *id, char *name)
{
	int len = 0;

	len = strlen(id) + 1;
	myID = new char[len];
	strcpy_s(myID, len, id);

	len = strlen(name) + 1;
	myName = new char[len];
	strcpy_s(myName, len, name);

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

}

Account::~Account()
{
	delete[] myName;
	delete[] myID;
}


void Account::ShowInfo() const
{
	cout << "ID : " << GetID() << endl;
	cout << "Name : " << GetName() << endl;
	cout << "Money : " << GetMoney() << endl;
}