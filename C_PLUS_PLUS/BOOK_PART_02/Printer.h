#pragma once

namespace PRINTER_CONST
{
	enum
	{
		STR_LEN = 100
	};
}

class Printer
{
private:
	int price;
	char str[PRINTER_CONST::STR_LEN];
public:
	void ShowString();
	void SetString(char*);
};