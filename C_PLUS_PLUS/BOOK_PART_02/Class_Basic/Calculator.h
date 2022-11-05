#pragma once

class Calculator
{
private:
	int add_cnt;
	int min_cnt;
	int mul_cnt;
	int div_cnt;
public:
	void Init();
	double Add(double, double);
	double Div(double, double);
	double Min(double, double);
	double Mul(double, double);
	void ShowOpCount();
};