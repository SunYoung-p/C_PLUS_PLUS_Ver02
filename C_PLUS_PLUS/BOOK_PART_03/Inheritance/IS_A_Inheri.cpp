
#include <iostream>
using namespace std;

class Computer
{
private:
	char owner[50];
public:
	Computer(char* name)
	{
		strcpy_s(owner, strlen(name) + 1, name);
	}
	void Calculate()
	{
		cout << "��û ������ ����մϴ�." << endl;
	}
};

class NoteBookComp : public Computer
{
private:
	int Battery;
public:
	NoteBookComp(char * name, int initChag)
		: Computer(name), Battery(initChag)
	{	}

	void Charging() { Battery += 5; }
	void UseBattery() { Battery -= 1; }
	void MovingCal()
	{
		if (GetBatteryInfo() < 1)
		{
			cout << "������ �ʿ��մϴ�" << endl;
			return;
		}
		cout << "�̵��ϸ鼭 ";
		Calculate();
		UseBattery();
	}
	int GetBatteryInfo() { return Battery; }
};

class TabletNotebook : public NoteBookComp
{
private:
	char regstPenModel[50];
public:
	TabletNotebook(char* name, int initChag, char* pen)
		: NoteBookComp(name, initChag)
	{
		strcpy_s(regstPenModel, strlen(pen) + 1, pen);
	}
	void Write(char * penInfo)
	{
		if (GetBatteryInfo() < 1)
		{
			cout << "������ �ʿ��մϴ�." << endl;
			return;
		}

		if (strcmp(regstPenModel, penInfo) != 0)
		{
			cout << "��ϵ� ���� �ƴմϴ�.";
			return;
		}
		cout << "�ʱ� ������ ó���մϴ�." << endl;
		UseBattery();
	}
};

int IS_A_Inheri()
{
	NoteBookComp nc("�̼���", 5);
	TabletNotebook tn("������", 5, "ISE-241-242");
	nc.MovingCal();
	tn.Write("ISE-241-242");

	return 0;
}