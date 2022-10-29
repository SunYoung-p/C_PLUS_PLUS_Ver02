#include <iostream>
using namespace std;

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
	virtual int GetPay()	 const
	{
		return 0;
	}

	virtual void ShowSalaryInfo() const
	{ }
};

class PermanentWorker : public Employee
{
private:
	int salary;
public:
	PermanentWorker(char* name, int money)
		: Employee(name), salary(money)
	{ }

	int GetPay() const
	{
		return salary;
	}

	void ShowSalaryInfo() const
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
	int GetPay() const
	{
		return workTime * payPerHour;
	}
	void ShowSalaryInfo() const
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

	int GetPay() const	// 상속 관계에 한해서, 매개변수와 리턴값이 똑같은 함수를 선언하면 함수오버라이딩,  매개변수 자료형과 개수가 다르면 함수 오버로딩이 된다.
	{
		return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
	}

	void ShowSalaryInfo() const	// 오버라이딩 하지 않으면, 기초 클래스의 GetPay() 가 호출되어 버린다.
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
			empList[i]->ShowSalaryInfo();		// 기초 클래스 Employee 내부에 가상함수로 선언됨으로, 변수 자료형이 아닌 가리키는 주소값의 자료형(클래스)에 맞는 함수를 실행하게 됨

	}
	void ShowTotalSalary() const
	{
		int sum = 0;

		for (int i = 0; i < empNum; i++)
			sum += empList[i]->GetPay();		// 기초 클래스 Employee 내부에 가상함수로 선언됨으로, 변수 자료형이 아닌 가리키는 주소값의 자료형(클래스)에 맞는 함수를 실행하게 됨

		cout << "salary sum: " << sum << endl;
	}
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}

};

/*
상속을 하는 이유는 연관된 영업직, 정규직, 임시직 클래스에 공통 규약인 직원이라는 클래스를 정의하기 위함이다.
직원 클래스에 모두에게 똑같이 해당되는 규약 및 동작을 설정하여
이걸 상속함으로써,  어떤 종류의 직업이든 간에 직원 객체로 바라보고 관리할 수 있다.

오렌지미디어 급여 관리 확장성 문제 해결의 포인트
1. 상속을 받은 유도 클래스의 객체 주소값은 기초 클래스의 포인터 변수에 저장이 가능하다.
- emplyee 포인터 배열에 PermentWorker 객체 주소 넣는 게 가능
- handler 클래스에 PermentWorker 변수,  이를 다루는 함수를 추가할 필요가 없어짐
2. 가상함수와 함수 오버라이딩으로,  변수의 자료형이 아니라 가리키는 주소의 자료형 기준의 함수 실행이 가능하다.
- emplyee 포인터 배열에 여러 종류의 객체 주소를 집어넣고,  오버라이딩만 되어있다는 조건이면,  각 종류에 맞는 함수를 찾아가서 실행이 가능함
*/
int Inheritance_01()
{
	// 직원 관리를 목적으로 설계된 컨트롤 클래스의 객체 생성
	EmployeeHandler handler;

	// 정규직 등록
	handler.AddEmployee(new PermanentWorker("Kim", 1000));		// Employee 포인터 객체 배열에,  PermanentWorker 객체를 집어넣어서 관리가 가능함.  상속되었으므로
	handler.AddEmployee(new PermanentWorker("LEE", 1500));

	// 임시직 등록
	TemporaryWorker * alba = new TemporaryWorker("Jung", 700);
	alba->AddWorkTime(5); // 5시간 일한 결과 등록
	handler.AddEmployee(alba);

	// 영업직 등록
	SalesWorker * seller = new SalesWorker("Hong", 1000, 0.1);
	seller->AddSalesResult(7000); // 영업 실적 7000
	handler.AddEmployee(seller);

	// 이번 달에 지불해야 할 급여의 정보
	handler.ShowAllSalaryInfo();

	// 이번 달에 지불해야 할 급여의 총합
	handler.ShowTotalSalary();
	return 0;
}