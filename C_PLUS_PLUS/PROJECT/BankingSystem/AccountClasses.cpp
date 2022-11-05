/*
11/02
1. OOP 단계별 프로젝트로 Account 클래스를 상속하는 2개의 클래스를 만들고, 계좌 입금 시 이자가 붙는 방식이 다르므로
입금 함수를 가상 함수로 만들어서 적용했는데, 가상 함수 구현 부분에서
기초 클래스의 입금 함수를 가져와서 쓰면 편한데,  입금 관련 코드를 그냥 새로 만들었다.
상속 후 가상함수 설정은 잘 되었지만, 상속한 기초 클래스의 멤버 함수를 쓰는 게 아직 익숙하지 않다.
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
		cout << "잔액 부족" << endl << endl;
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
		cout << "잔액 부족" << endl << endl;
		return;
	}

	myMoney -= money;
}



