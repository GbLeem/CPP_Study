//item 7 : Distinguish between () and {} when creating objects

class Widget {};

Widget w1; // 기본 생성자 호출
Widget w2 = w1; //복사 생성자 호출
w1 = w2; //assignment

//C++11 의 uniform initialization
//중괄호를 사용
#include<vector>
std::vector<int> v{ 1,3,5 }; //uniform(중괄호) 초기화

//초기화 예시1
//non-static member
class Widget
{
private:
	int x{ 0 }; //ok
	int y = 0;  //ok
	int z(0);   //no!
};

//초기화 예시2
//복사할 수 없는 객체
std::atominc<int> ai1{ 0 }; //ok
std::atominc<int> ai2(0);   //ok
std::atominc<int> ai3 = 0;  //no!

//중괄호 초기화는 narrowing conversion 방지
double x, y, z;
int sum1{ x + y + z };//오류

//중괄호 초기화는 auto를 사용할때 복잡한 문제가 생긴다.
class Widget
{
public:
	Widget(int i, bool b);
	Widget(int i, double d);
	Widget(std::initializer_list<long double>il); //중괄호 초기화는 initializer_list를 받는 생성자에 대응하려한다.
};
int main()
{
	Widget w1(10, true);  //첫번째 생성자
	Widget w2{ 10,true }; //첫번째 생성자
	Widget w3(10, 5.0);   //두번째 생성자
	Widget w4{ 10,5.0 };  //두번째 생성자

	//initializer_list 추가된 후
	Widget w1(10, true);  //첫번째 생성자
	Widget w2{ 10,true }; //세번째 생성자 10, true가 long double 로 변함
	Widget w3(10, 5.0);   //두번째 생성자
	Widget w4{ 10,5.0 };  //세번째 생성자
}

//vector의 경우..
std::vector<int> v1(10, 20);//비 initializer_list 생성자 이용, 값이 20인 길이 10개짜리 벡터 생성
std::vector<int> v2{ 10, 20 }; //initializer_list 생성자 이용, 값이 10, 20인 두개의 벡터 생성

//*중복적재 : overload