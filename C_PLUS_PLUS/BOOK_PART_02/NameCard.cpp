#include <iostream>
#include "NameCard.h"

using namespace std;

NameCard::NameCard(char* name_, char* com_, char* phone_, int rank_)
{
	int len = 0;

	len = strlen(name_);
	name = new char[len+1];
	strcpy_s(name, len+1, name_);
	name[len] = '\0';

	len = strlen(com_);
	company = new char[len+1];
	strcpy_s(company, len+1, com_);
	company[len] = '\0';

	len = strlen(phone_);
	phone = new char[len + 1];
	strcpy_s(phone, len+1, phone_);
	phone[len] = '\0';

	if (rank_ < RANK_POS::CLERK || rank_ > RANK_POS::MANAGER)
	{
		cout << "rank �ʱ�ȭ ����" << endl;
		rank = RANK_POS::CLERK;
		return;
	}

	rank = rank_;
}

NameCard::NameCard(NameCard &copy) 
	: rank(copy.rank)
{
	int len = 0;

	len = strlen(copy.name)+1;
	name = new char[len];
	strcpy_s(name, len, copy.name);

	len = strlen(copy.company) +1;
	company = new char[len];
	strcpy_s(company, len, copy.company);

	len = strlen(copy.phone) +1;
	phone = new char[len];
	strcpy_s(phone, len, copy.phone);
}

NameCard::~NameCard()
{
	delete[] name;
	delete[] company;
	delete[] phone;

	cout << "�Ҹ��� ���� �Ϸ�" << endl;
}

void NameCard::ShowNameCardInfo()
{
	cout << "�̸�: " << name << endl;
	cout << "ȸ��: " << company << endl;
	cout << "��ȭ��ȣ: " << phone << endl;
	cout << "����: " << rank << endl << endl;
}