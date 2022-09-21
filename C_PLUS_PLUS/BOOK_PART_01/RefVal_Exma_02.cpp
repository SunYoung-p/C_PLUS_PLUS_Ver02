#include <iostream>

using namespace std;


typedef struct __Point
{
	int xpos;
	int ypos;
}Point;

Point& PntAdder(const Point &p1, const Point &p2);

int RefVal_Exam_02()
{
	Point * p1 = new Point; // 힙 영역에 메모리 공간이 할당되고, 이름은 없고, 다만 p1이 주소를 가리킴
	Point * p2 = new Point;


	(*p1).xpos = 10;
	(*p1).ypos = 20;
	(*p2).xpos = 5;
	(*p2).ypos = 7;

	Point &re = PntAdder(*p1, *p2);  // *를 붙여서 p1이 가리키는 메모리를 보냄

	cout << "xpos : " << re.xpos << endl		// re에 &를 붙여서 참조형으로 받았으므로,  함수 리턴값인 힙 영역에 메모리 공간에 별칭이 붙음
		<< "ypos : " << re.ypos << endl;

	delete p1;
	delete p2;
	delete &re;		//  p1, p2 는 주소값이므로 delete 가능하고,  re는 point 일반 자료형(별칭) 이므로 & 넣어서 주소값으로 delete 해야 함

	getchar();
	getchar();

	return 0;
}


Point& PntAdder(const Point &p1, const Point &p2)  // 참조형으로 받음으로써, 메모리 공간에 별칭을 붙여줌
{
	Point* n = new Point;

	n->xpos = p1.xpos + p2.xpos;		// 별칭이 붙었으므로 일반 변수 처럼 사용 가능
	n->ypos = p1.ypos + p2.ypos;

	return *n;			// 마찬가지로,  힙에 할당된 메모리를 리턴함 ,  *를 붙임으로써,, 이 메모리의 자료형은 Point 이므로 리턴 Point& 타입 가능
}