#include <iostream>
#include "Account.h"
#include "AccountClasses.h"
#include "AccountHandler.h"
using namespace std;

// ������
AccountHandler::AccountHandler()
{
	idx = -1;
	ACCOUNT_CNT = 100;
}

// �Ҹ���
AccountHandler::~AccountHandler()
{
	for (int i = 0; i < ACCOUNT_CNT; i++)
	{
		if (i > idx)
			break;

		delete info[i];
	}

	cout << "�޸� ���� �Ϸ� \n";
}

// ���޹��� ID�� ���� index Ȯ��
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

// ��ü �޴� ���
void AccountHandler::PrintMenu() const
{
	cout << "-----Menu-----" << endl
		<< "1. ���°���" << endl
		<< "2. �� ��" << endl
		<< "3. �� ��" << endl
		<< "4. �������� ��ü ���" << endl
		<< "5. ���α׷� ����" << endl
		<< "����: ";
}

// ���� ����
void AccountHandler::MakeAccount()
{
	int sel = 0;

	cout << "\n[������������]\n";
	cout << "1. ���뿹�ݰ���  2. �ſ�ŷڰ��� \n";
	cout << "����: ";
	cin >> sel;
	cin.clear();
	cin.ignore(INT_MAX, '\n');

	switch (sel)
	{
	case 1:
		info[++idx] = MakeNormalAccount();
		break;
	case 2:
		info[++idx] = MakeCreditAccount();
		break;
	default:
		cout << "�߸��� ���� �Դϴ�" << endl << endl;
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
			cout << "ID �ߺ� ���� \n";
			return;
		}
	}
	*/
}

NormalAccount* AccountHandler::MakeNormalAccount()
{
	char id[20] = { 0 }, name[20] = { 0 };
	int money = 0;
	int ratio = 0;

	cout << "[���뿹�ݰ��� ����] \n";

	cout << "����ID : "; cin >> id;
	/* ���� - ID �ߺ� üũ �ʿ� */
	cout << "��   �� : "; cin >> name;
	cout << "�Աݾ� : "; cin >> money;
	cout << "������ : "; cin >> ratio;
	
	NormalAccount* a = new NormalAccount(id, name, money, ratio);

	return a;
}

HighCreditAccount* AccountHandler::MakeCreditAccount()
{
	char id[20] = { 0 }, name[20] = { 0 };
	int money = 0;
	int ratio = 0;
	int level = 0;

	cout << "[�ſ�ŷڰ��� ����] \n";

	cout << "����ID : "; cin >> id;
	cout << "��   �� : "; cin >> name;
	cout << "�Աݾ� : "; cin >> money;
	cout << "������ : "; cin >> ratio;
	cout << "�ſ���(1toA, 2toB, 3toC) : "; cin >> level;
	/* ���� - ������ ���� �߸��� �Է¿� ���� ó�� �ʿ� */

	HighCreditAccount* a = new HighCreditAccount(id, name, money, ratio, level);

	return a;
}

// �Ա�
void AccountHandler::DepositMoney()
{
	char id[20] = { 0 };
	int money = 0, idx = 0;

	cout << "\n [���� �Ա�] \n";
	cout << "(1) ID �Է� : "; cin >> id;
	cout << "(2) �Ա� �׼� �Է� : "; cin >> money;

	idx = GetIdxBank(id);

	if (idx == -1)
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

// ���
void AccountHandler::WithDrawMoney()
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

// ��ü ���� ���� ���
void AccountHandler::PrintAccount() const
{
	cout << "\n";

	for (int i = 0; i < ACCOUNT_CNT; i++)
	{
		if (i > idx)
			break;

		cout << "[ " << i + 1 << "�� ���� ���� ] \n";
		info[i]->ShowInfo();
		cout << "\n";
	}
}