
#include <iostream>
using namespace std;

class c1030
{
private:
	char* strOne;
public:
	c1030(char * str)
	{
		strOne = new char[strlen(str) + 1];
	}
	virtual ~c1030()
	{
		cout << "~First()" << endl;
		delete[] strOne;
	}
};

class s1030 : public c1030
{
private:
	char * strTwo;
public:
	s1030(char* str1, char* str2) : c1030(str1)
	{
		strTwo = new char[strlen(str2) + 1];
	}
	~s1030()
	{
		cout << "~Second()" << endl;
		delete[] strTwo;
	}
};

int VirtualDestructor()
{
	c1030* ptr = new s1030("simple", "complex");
	delete ptr;

	return 0;
}