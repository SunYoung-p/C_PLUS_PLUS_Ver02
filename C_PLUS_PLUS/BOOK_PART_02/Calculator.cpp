#include <iostream>
#include "Calculator.h"

using namespace std;

void Class_Calcuator()
{
	Calculator cal;
	cal.Init();
	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
	cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
	cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
	cout << "4.9 * 1.2 = " << cal.Mul(4.9, 1.2) << endl;
	cout << "1.2 / 0.2 = " << cal.Div(1.2, 0.2) << endl;
	cal.ShowOpCount();
}

void Calculator::Init()
{
	add_cnt = 0;
	mul_cnt = 0;
	div_cnt = 0;
	min_cnt = 0;
}

double Calculator::Add(double n, double m)
{
	add_cnt++;

	return n + m;
}

double Calculator::Div(double n, double m)
{
	div_cnt++;

	return n / m;
}

double Calculator::Min(double n, double m)
{
	min_cnt++;

	return n - m;
}

double Calculator::Mul(double n, double m)
{
	mul_cnt++;

	return n*m;
}

void Calculator::ShowOpCount()
{
	cout << "µ¡¼À : " << add_cnt << " »¬¼À: "
		<< min_cnt << " °ö¼À: " << mul_cnt << " ³ª´°¼À: "
		<< div_cnt << endl;
}