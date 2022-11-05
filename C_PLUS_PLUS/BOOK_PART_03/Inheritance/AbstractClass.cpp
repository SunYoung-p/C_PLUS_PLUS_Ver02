
#include <iostream>
using namespace std;
/*
class Employee
{
private:
	char name[100];
public:
	Employee(char* name)
	{
		strcpy_s(this->name, strlen(name) + 1, name);
	}
	void ShowYourName() const
	{
		cout << "name : " << name << endl;
	}
	virtual int GetPay()	 const = 0;		// 순수 가상함수를 포함하고 있으므로, Employee는 추상 클래스가 되어 객체 생성 불가
	virtual void ShowSalaryInfo() const = 0;
};

class PermanentWorker : public Employee
{
private:
	int salary;
public:
	PermanentWorker(char* name, int money)
		: Employee(name), salary(money)
	{ }

	virtual int GetPay() const
	{
		return salary;
	}

	virtual void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class TemporaryWorker : public Employee
{
private:
	int workTime;
	int payPerHour;
public:
	TemporaryWorker(char * name, int pay)
		: Employee(name), workTime(0), payPerHour(pay)
	{

	}
	void AddWorkTime(int time)
	{
		workTime += time;
	}
	virtual int GetPay() const
	{
		return workTime * payPerHour;
	}
	virtual void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class SalesWorker : public PermanentWorker
{
private:
	int salesResult;
	double bonusRatio;
public:
	SalesWorker(char * name, int money, double ratio)
		: PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
	{

	}

	void AddSalesResult(int value)
	{
		salesResult += value;
	}

	virtual int GetPay() const
	{
		return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
	}

	virtual void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "Salary : " << GetPay() << endl << endl;
	}
};

class EmployeeHandler
{
private:
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{ }
	void AddEmployee(Employee* emp)
	{
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const
	{

		for (int i = 0; i < empNum; i++)
			empList[i]->ShowSalaryInfo();

	}
	void ShowTotalSalary() const
	{
		int sum = 0;

		for (int i = 0; i < empNum; i++)
			sum += empList[i]->GetPay();

		cout << "salary sum: " << sum << endl;
	}
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}

};

class ForeignSalesWorker : public SalesWorker
{
private:
	const int risk;
public:
	ForeignSalesWorker(char * na, int mo, double ra, int level)
		: SalesWorker(na, mo, ra), risk(level)
	{

	}

	virtual int GetPay() const
	{
		return SalesWorker::GetPay() + (int)(SalesWorker::GetPay() * risk / 10);
	}

	virtual void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "Salary : " << SalesWorker::GetPay() << endl;
		cout << "risk pay : " << (int)(SalesWorker::GetPay() * risk / 10) << endl;
		cout << "sum : " << GetPay() << endl << endl;
	}
};

class RISK_LEVEL
{
public:
	const static int RISK_A = 3;
	const static int RISK_B = 2;
	const static int RISK_C = 1;
};

int AbstractClass()
{
	// 직원 관리를 목적으로 설계된 컨트롤 클래스의 객체 생성
	EmployeeHandler handler;

	// 해외 영업직 등록
	ForeignSalesWorker * fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	fseller1->AddSalesResult(7000);		// 영업 실적 7000
	handler.AddEmployee(fseller1);

	ForeignSalesWorker * fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller2->AddSalesResult(7000);		// 영업 실적 7000
	handler.AddEmployee(fseller2);

	ForeignSalesWorker * fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
	fseller3->AddSalesResult(7000);		// 영업 실적 7000
	handler.AddEmployee(fseller3);

	// 이번 달에 지불해야 할 급여의 총합
	handler.ShowAllSalaryInfo();

	return 0;
}

*/