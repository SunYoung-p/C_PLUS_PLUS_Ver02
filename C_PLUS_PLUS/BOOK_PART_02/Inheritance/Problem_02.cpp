#include <iostream>
using namespace std;

class MyFriendInfo3
{
private:
	char* name;
	int age;
public:
	MyFriendInfo3(char* n, int age) : age(age)
	{
		int len = strlen(n) + 1;
		name = new char[len];
		strcpy_s(name, len, n);
	}
	~MyFriendInfo3()
	{
		delete[] name;
	}
	void ShowMyFriendInfo()
	{
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;
	}
};

class MyFriendDetailInfo : public MyFriendInfo3
{
private:
	char * addr;
	char * phone;
public:
	MyFriendDetailInfo(int age, char* name, char* add, char* pho)
		: MyFriendInfo3(name, age)
	{
		int len = strlen(add) + 1;
		addr = new char[len];
		strcpy_s(addr, len, add);

		len = strlen(pho) + 1;
		phone = new char[len];
		strcpy_s(phone, len, pho);
	}

	~MyFriendDetailInfo()
	{
		delete[] addr;
		delete[] phone;
	}

	void ShowMyFriendDetailInfo()
	{
		ShowMyFriendInfo();
		cout << "주소 : " << addr << endl;
		cout << "전화 : " << phone << endl;
	}
};

int Problem02_1021()
{
	MyFriendDetailInfo n(10, "PSY", "Suwon", "010-0000-0000");
	n.ShowMyFriendDetailInfo();

	return 0;
}