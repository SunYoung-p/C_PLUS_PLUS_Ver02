#include <iostream>

using namespace std;

class CountryArea
{
public:
	const static int RUSSIA = 1707540;
	const static int CANADA = 998467;
	const static int CHINA = 957290;
	const static int SOUTH_KOREA = 9922;
};

/*
class SoSimple
{
   private: int n;
   public : 
    static int Adder(int m)
	{
	  n+=m;			// static 멤버 함수는 static 멤버 변수와 static 함수만 호출 가능 (이 함수는 객체 내 존재하지 않으므로 컴파일 에러 발생)
	  return n;
	}
};
*/
int main()
{
	cout << "러시아 면적 : " << CountryArea::RUSSIA<< "km2" << endl;
	cout << "캐나다 면적 : " << CountryArea::CANADA<< "km2" << endl;
	cout << "중국 면적 : " << CountryArea::CHINA<< "km2" << endl;
	cout << "한국 면적 : " << CountryArea::SOUTH_KOREA<< "km2" << endl;

	return 0;
}