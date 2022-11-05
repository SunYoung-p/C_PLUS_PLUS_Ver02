#include <iostream>
using namespace std;

// 클래스 Data를 흉내 낸 영역
typedef struct Data
{
	int data;
	void(*ShowData)(Data*);
	void(*Add)(Data*, int);
}Data;

void ShowData(Data* THIS) { cout << "Data: " << THIS->data << endl; }
void Add(Data * THIS, int num) { THIS->data += num; }

// 적절히 변경된 main 함수
int RealMemberFunction()
{
	Data obj1 = { 15, ShowData, Add };
	Data obj2 = { 7, ShowData, Add };

	obj1.Add(&obj1, 17);		// obj1과 obj2는 data 변수를 각각 갖지만, Add 함수는 실제로는 각각 1개씩 있는 게 아니라 외부 메모리에 있는 함수를 공유하는 형태이다.
	obj2.Add(&obj2, 9);
	obj1.ShowData(&obj1);
	obj2.ShowData(&obj2);
	return 0;
}



/*
class Data
{
private:
int data;
public:
Data(int num) : data(num)
{}
void ShowData() { cout << "Data : " << data << endl; }
void Add(int num) { data += num; }
};

int main()
{
Data obj(15);
obj.Add(17);
obj.ShowData();

return 0;
}
*/