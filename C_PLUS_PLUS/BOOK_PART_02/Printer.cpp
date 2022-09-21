#include "Printer.h"
#include <iostream>

using namespace std;

void Run_Printer()
{
	Printer pnt;
	pnt.SetString("Hello World!");
	pnt.ShowString();

	pnt.SetString("I love C++");
	pnt.ShowString();
}

void Printer::ShowString()
{
	cout << str << endl;
}

void Printer::SetString(char* n)
{
	strcpy_s(str, "\0");
	strcpy_s(str, n);
}