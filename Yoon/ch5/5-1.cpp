//복사 생성자

class Widget
{
private:
	int num1;
	int num2;

public:
	Widget(int n1, int n2)
		:num1(n1)
		, num2(n2)
	{

	}
	Widget(const Widget& temp)
		:num1(temp.num1)
		, num2(temp.num2)
	{

	}
};

int main()
{
	Widget num1(10,20);
	Widget num2 = num1;//Widget num2(num1) 이랑 같은 것 : 묵시적 변환 한다.
}


//explicit 키워드
//묵시적 변환 막아준다.
//explicit Widget(const Widget& temp)
//	:num1(temp.num1)
//	, num2(temp.num2)
//{
//
//}
//위처럼 선언하면 대입 연산 실행 x

class A
{
private:
	int num;
public:
	explicit A(int n)
		:num(n)
	{

	}
};

int main()
{
	//A a = 3; explicit 으로 만들면 사용 불가 / explicit 없다면 복사 연산자로 변환
	A aa(3); //복사 생성자 호출
}