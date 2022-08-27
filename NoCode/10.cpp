//		<build process Introduction>


//1. pre process(빌드시 최초로 관여) : #include, #define
//-> translation unit 만들기

//2. 컴파일러가 obj파일로 만든다. 

//3. 링커 개입하여 obj파일을 합쳐서 exe 파일로 만든다.


//컴파일러의 종류 : gcc, clang, visual c++ ...

//컴파일러는 실행 과정중에 오류가 발생할 수 있는 것에 대한 
//warning을 만들어주기도 한다.

#include<iostream>
#include<variant>

int main()
{
	std::variant<int, float> i = 0;
	std::cout << "hi" << std::endl;
}

//다양한 컴파일 옵션 존재..