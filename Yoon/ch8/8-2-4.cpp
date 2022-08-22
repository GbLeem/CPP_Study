//문제 1.
#include<iostream>
#include<cstring>
using namespace std;

enum RISK_LEVEL
{
	RISK_A,
	RISK_B,
	RISK_C
};

class Employee //추상 클래스 :하나 이상의 멤버함수를 순수 가상함수로 선언한 클래스
{
private:
	char name[100];
public:
	Employee(const char* name)
	{
		strcpy_s(this->name, strlen(name) + 1, name);
	}
	void ShowYourName() const
	{
		cout << "name: " << name << endl;
	}
	virtual int GetPay() const = 0;//pure virtual function

	virtual void ShowSalaryInfo() const = 0;//pure virtual function  -> 순수 가상함수로 잘못된 객체 생성을 막는다.
};

class PermanentWorker :public Employee
{
private:
	int salary;
public:
	PermanentWorker(const char* name, int money)
		:Employee(name)
		, salary(money)
	{
	}
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

class TemporaryWorker :public Employee
{
private:
	int workTime;
	int payPerHour;
public:
	TemporaryWorker(const char* name, int pay)
		:Employee(name)
		, workTime(0)
		, payPerHour(pay)
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
	void ShowSalaryInfo()const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl;
	}
};

class SalesWorker :public PermanentWorker
{
private:
	int saleResult;
	double bonusRatio;
public:
	SalesWorker(const char* name, int money, double ratio)
		:PermanentWorker(name, money)
		, saleResult(0)
		, bonusRatio(ratio)
	{
	}
	void AddSalesResult(int value)
	{
		saleResult += value;
	}
	int GetPay() const
	{
		return PermanentWorker::GetPay() + (int)(saleResult * bonusRatio);
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salay: " << GetPay() << endl << endl;
	}
};

class ForeignSalesWorker : public SalesWorker
{
private:
	const RISK_LEVEL RLevel;
public:
	ForeignSalesWorker(const char* name, int money, double ratio, RISK_LEVEL level)
		:SalesWorker(name, money, ratio)
		,RLevel(level)
	{
	}

	int  GetRiskPay() const
	{
		int risk;

		switch (RLevel)
		{
		case RISK_A:
			risk = (int)(SalesWorker::GetPay() * 0.3);
			break;
		case RISK_B:
			risk = (int)(SalesWorker::GetPay() * 0.2);
			break;
		case RISK_C:
			risk = (int)(SalesWorker::GetPay() * 0.1);
			break;
		}
		return risk;
	}

	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salay: " << GetPay() << endl;
		cout << "risk pay: " << GetRiskPay() << endl;
		cout << "sum : " << GetPay() + GetRiskPay() << endl << endl;
	}
};

class EmployeeHandler
{
private:
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler()
		:empList()
		, empNum(0)
	{
	}
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

int main()
{
	EmployeeHandler handler;

	ForeignSalesWorker* fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	fseller1->AddSalesResult(7000);
	handler.AddEmployee(fseller1);

	ForeignSalesWorker* fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller2->AddSalesResult(7000);
	handler.AddEmployee(fseller2);

	ForeignSalesWorker* fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
	fseller3->AddSalesResult(7000);
	handler.AddEmployee(fseller3);

	handler.ShowAllSalaryInfo();
	return 0;
}