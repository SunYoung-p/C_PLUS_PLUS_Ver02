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
	Point * p1 = new Point; // �� ������ �޸� ������ �Ҵ�ǰ�, �̸��� ����, �ٸ� p1�� �ּҸ� ����Ŵ
	Point * p2 = new Point;


	(*p1).xpos = 10;
	(*p1).ypos = 20;
	(*p2).xpos = 5;
	(*p2).ypos = 7;

	Point &re = PntAdder(*p1, *p2);  // *�� �ٿ��� p1�� ����Ű�� �޸𸮸� ����

	cout << "xpos : " << re.xpos << endl		// re�� &�� �ٿ��� ���������� �޾����Ƿ�,  �Լ� ���ϰ��� �� ������ �޸� ������ ��Ī�� ����
		<< "ypos : " << re.ypos << endl;

	delete p1;
	delete p2;
	delete &re;		//  p1, p2 �� �ּҰ��̹Ƿ� delete �����ϰ�,  re�� point �Ϲ� �ڷ���(��Ī) �̹Ƿ� & �־ �ּҰ����� delete �ؾ� ��

	getchar();
	getchar();

	return 0;
}


Point& PntAdder(const Point &p1, const Point &p2)  // ���������� �������ν�, �޸� ������ ��Ī�� �ٿ���
{
	Point* n = new Point;

	n->xpos = p1.xpos + p2.xpos;		// ��Ī�� �پ����Ƿ� �Ϲ� ���� ó�� ��� ����
	n->ypos = p1.ypos + p2.ypos;

	return *n;			// ����������,  ���� �Ҵ�� �޸𸮸� ������ ,  *�� �������ν�,, �� �޸��� �ڷ����� Point �̹Ƿ� ���� Point& Ÿ�� ����
}