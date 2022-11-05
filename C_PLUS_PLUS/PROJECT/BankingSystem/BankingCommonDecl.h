/*
Bank Manager ���α׷�

1. Version : 2.0 (220815)
2. ������
 - ����ü AccountInfo �� Ŭ������ ����
 - AccountInfo �� �� ���� char �迭�� ���� �Ҵ� �ϴ� ������ ����
 - ��ü �迭�� ��ü ������ �迭�� ����
*/
#pragma once
#include <iostream>
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "AccountHandler.h"
using namespace std;

/* ���� �Լ� ���� */
int RunBankManager();

enum KEY
{
	MAKE = 1,
	DEPOSIT,
	WITHDRAW,
	SHOWINFO,
	EXIT
};

enum AccountRatio
{
	LEVEL_A = 7,
	LEVEL_B = 4,
	LEVEL_C = 2
};