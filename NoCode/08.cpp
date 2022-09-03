//				<Heap, Stack, Static>

//Stack
// : stack frame 단위로 
// 위에서 부터 아래로 간격 없이
// allocate, disallocate 빠르다.
// dynamic allocate 불가능
// 큰 메모리 할당시 stack overflow 발생 가능

//Heap
// : 비어있는 공간 확인
// 프로그램 실행 과정 중에 확인
// 메모리 할당 해제 시간이 느리다(stack 보다)
// dynamic allocate 가능!
// 큰 메모리 할당 유리

#include<array>
#include<vector>
#include<iostream>

class Cat
{
public:
private:
	int mAge;
};

void foo(int num)
{
	std::vector<Cat> cats(num);
};

bool bar(int num)
{
	constexpr int maxCats = 1000;

	if (maxCats < num)
	{
		return false;
	}
	std::array<Cat, maxCats> cats; //performance critical 하게 만들기
};

int main()
{
	int i, double d, float f; //stack allocate 
	std::array<int, 300> a1;//1.2kb ->stack allocate

	std::array<int, 500000> a2; //2mb -> heap allocate
	std::vector<int> b(500000); //heap allocate;

	Cat cat; //stack allocate (용량이 n kb 이하 일때)


	//함수 쓸 때
	int count;
	std::cin >> count;
	foo(count); // 이렇게만 하면 slow...

	//performance cirtical 하기 위해서...!
	for (int i = 0; i < 10000; ++i)
	{
		bar(count);
	}
}

//static, global 객체들은 heap 메모리 아래딴에 존재
//

