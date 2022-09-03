//				<object Alignment>


//remind) 포인터 64바이트 환경에서 8byte

#include<iostream>
#include<array>

class Cat
{
public:
	void speak();
private:
	//<case1>
	//double d8;
	//int i4a;
	//int i4b;

	//<case2>
	int i4a; //0~4 int, 4~8 padding
	double d8; //8~16 double
	int i4b;//16~20 int, 20~24 padding
};

int main()
{
	Cat stackCat;
	//std::cout << sizeof(stackCat) << std::endl; //case1 : 16 byte
	std::cout << sizeof(stackCat) << std::endl; //case2 : 24 byte ->by memory padding
												//1. 각 멤버변수들은 자신의 바이트값의 배수에서 시작해야함
												//2. 해당 오브젝트의 메모리 크기는 가장 큰 멤버 변수의 배수로 끝남

	//<advanced..>
	std::array<Cat, 100> cats; //중간에 패딩이 들어있는 배열의 경우..
							   //Cache line이라는 하드웨어적 구조로 데이터를 64 바이트로 잘라 다른 코어로 들어감
							   //Cat의 경우 64로 잘랐을때 중간의 값을 잘라버리게 되는 문제가 발생한다.(false sharing)
	/*class alignas(32) Cat    다음과 같이 바꿔주어 위의 문제를 해결할 수 있다.
	{
	};*/
	
	return 0;
}