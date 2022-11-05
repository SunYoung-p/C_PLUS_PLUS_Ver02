#include "BankingCommonDecl.h"

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
		case MAKE:
			handler.MakeAccount();
			break;
		case  DEPOSIT:
			handler.DepositMoney();
			break;
		case  WITHDRAW:
			handler.WithDrawMoney();
			break;
		case  SHOWINFO:
			handler.PrintAccount();
			break;
		case  EXIT:
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


