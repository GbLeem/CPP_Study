//					<static Members>


#include<iostream>
// 빌드 프로세스의 static과 다름

//<Static in Class>
//1. Static member function
//오브젝트를 가리키는 this 정보가 없당
//오브젝트와 연관이 되어있지 않다.

//2. Static member variable
//프로그램이 실행되기 전에 초기화 필요

//3. Static variable in a function
//코드의 안정성을 위해서
class Cat
{
public:
	void speak()
	{
		static int safeCount = 0; //Static variable in a function
		count++;
		safeCount++;
		std::cout << "meow" << " count : " << count<<" , safe : "<<safeCount  << std::endl;
	}
	static void staticSpeak() //Static member function
	{
		std::cout << "CAT" << std::endl;
		//std::cout << mAge << std::endl; 멤버 변수에 접근 x
		//speak(); 멤버 함수 접근 x
	}
	static int count; //Static member variable

private:
	int mAge;
};

int Cat::count = 0; //static member variable 초기화

int main()
{
	//Static Member function 예시 코드
	//Cat kitty;
	//kitty.speak();
	//kitty.staticSpeak();// ok
	//
	//Cat::staticSpeak(); //오브젝트 만들지 않아도 사용 가능
	//--------------------------------------------------------
	//Static member variable 예시 코드
	Cat kitty;
	Cat nabi;
	kitty.speak(); //meow 1
	nabi.speak();  //meow 2
	Cat::count = 0; // 위처럼 만들 경우 아무대서나 접근 가능..(해결 : 위 경우 speak함수 안에서만 쓰니까 speak함수 안에서 
					// 선언 해버리는 방법! -> 다른대서 접근 못함) => static variable in function
					
	//Cat::safeCount = 0; //불가능! 위의 문제를 해결한 것

	return 0;
}




