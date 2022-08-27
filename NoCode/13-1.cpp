//			<Extern, Static>

//linking process와 관련
//extern : 바깥쪽에서 링크 찾기
//static : 안쪽에서 링크 찾기

#include<iostream>

//int a = 0;

extern void foo(); // 함수는 기본적으로 extern 키워드 붙어있다.
				   // extern 안써도 잘 실행된다.
int main()
{
	foo();
	//bar(); static 이라 사용 불가능
	//std::cout << a << std::endl;
	return 0;
}

//클래스의 함수가 해당 클래스의 오브젝트와 관련이 없는 함수일 경우
//private 함수로 만들지 말고 static을 붙인 free function으로 만드는
//것이 좋다. 


//extern "C"
//function overloading 을 할때 name mangling 으로 진행
//C언어에는 overloading없기 때문에 extern "C"로 선언하면
//name mangling 없애준다. -> C interface 처리