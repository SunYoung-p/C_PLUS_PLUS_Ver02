#include <iostream>
#include "BOOK_OOP_PRJ_01.h"
#include "AccountHandler.h"

using namespace std;

int RunBankManager() 
{ 
	bool exit = false;
	int sel = 0;
	AccountHandler handler;

	while (exit == false)
	{
		handler.PrintMenu();
		cin >> sel;
		cin.clear();
		cin.ignore(INT_MAX, '\n');

		switch (sel)
		{
		case AccountHandler::MAKE:
			handler.MakeAccount();
			break;
		case AccountHandler::DEPOSIT:
			handler.DepositMoney();
			break;
		case AccountHandler::WITHDRAW:
			handler.WithDrawMoney();
			break;
		case AccountHandler::SHOWINFO:
			handler.PrintAccount();
			break;
		case AccountHandler::EXIT:
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


