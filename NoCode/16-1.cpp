//			<Static Library>


//Library ����
//1. Header only
//2. Static library -> .lib ����
//3. Dynamic library -> .dll ����
//					-> load time or run time�� �ҷ�����


//Static library
//https://docs.microsoft.com/ko-kr/cpp/build/walkthrough-creating-and-using-a-static-library-cpp?view=msvc-160
//obj������ ��Ƶ� ��
//link Ÿ�ӿ� binding

#include"16-2.h"

int main()
{
	Cat kitty;
	kitty.speak();

	return 0;
}

