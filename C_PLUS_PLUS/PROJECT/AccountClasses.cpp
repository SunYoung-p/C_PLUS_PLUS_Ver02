/*
11/02
1. OOP �ܰ躰 ������Ʈ�� Account Ŭ������ ����ϴ� 2���� Ŭ������ �����, ���� �Ա� �� ���ڰ� �ٴ� ����� �ٸ��Ƿ�
�Ա� �Լ��� ���� �Լ��� ���� �����ߴµ�, ���� �Լ� ���� �κп���
���� Ŭ������ �Ա� �Լ��� �����ͼ� ���� ���ѵ�,  �Ա� ���� �ڵ带 �׳� ���� �������.
��� �� �����Լ� ������ �� �Ǿ�����, ����� ���� Ŭ������ ��� �Լ��� ���� �� ���� �ͼ����� �ʴ�.
*/
#include <iostream>
#include "AccountClasses.h"
using namespace std;

NormalAccount::NormalAccount(const NormalAccount& n)
{
	//
}

NormalAccount::~NormalAccount()
{
	//
}

int NormalAccount::GetMoney() const
{
	return myMoney;
}

void NormalAccount::PlusMoney(int money)
{
	myMoney += money + (money * ratio / 100);
}

void NormalAccount::MinusMoney(int money)
{
	if (myMoney < money)
	{
		cout << "�ܾ� ����" << endl << endl;
		return;
	}

	myMoney -= money;
}


int HighCreditAccount::GetMoney() const
{
	return myMoney;
}

void HighCreditAccount::PlusMoney(int money)
{
	
	switch (level)
	{
		case 1: ratio += AccountRatio::LEVEL_A; break;
		case 2: ratio += AccountRatio::LEVEL_B; break;
		case 3: ratio += AccountRatio::LEVEL_C; break;
		default:
			break;
	}

	myMoney += money + (money * ratio / 100);
}

void HighCreditAccount::MinusMoney(int money)
{
	if (myMoney < money)
	{
		cout << "�ܾ� ����" << endl << endl;
		return;
	}

	myMoney -= money;
}



