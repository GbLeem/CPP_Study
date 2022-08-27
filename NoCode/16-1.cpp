//			<Static Library>


//Library 종류
//1. Header only
//2. Static library -> .lib 파일
//3. Dynamic library -> .dll 파일
//					-> load time or run time에 불러오기


//Static library
//https://docs.microsoft.com/ko-kr/cpp/build/walkthrough-creating-and-using-a-static-library-cpp?view=msvc-160
//obj파일을 모아둔 것
//link 타임에 binding

#include"16-2.h"

int main()
{
	Cat kitty;
	kitty.speak();

	return 0;
}

