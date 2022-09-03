//				<Heap Code>

#include<stdlib.h>
#include<iostream>
#include<vector>

class Cat
{
public:
	Cat()
	{
		std::cout << "meow" << std::endl;
	}
	~Cat()
	{
		std::cout << "bye" << std::endl;
	}
private:
	int mAge;
};


int main()
{
	//C style heap int
	/*int* ip = (int*)malloc(sizeof(int));
	*ip = 100;
	free(ip);*/

	//C Style heap array
	/*int* iap = (int*)malloc(sizeof(int) * 5);
	iap[0] = 100;
	free(iap);*/


	//C style heap Cat
	//Cat* catp = (Cat*)malloc(sizeof(int));
	//free(catp);

	//C style heap Cats(Cat array)
	//Cat* catap = (Cat*)malloc(sizeof(Cat) * 5);
	//free(catap);
	
	//생성자와 소멸자가 호출되지 않는다!!
	//객체의 경우 c style heap allocate x
	 
	//C++ style !!
	//Cat* catp = new Cat;
	//delete catp;

	//Cat* catap = new Cat[5];
	//delete[] catap;

	//delete 를 쓰지 않으면 메모리 leak발생!


	//<메모리 leak 방지>
	//smart pointer 사용
	//Cat 객체 하나 생성시..
	//std::unique_ptr<Cat> catup = std::make_unique<Cat>();
	//vector 사용
	//Cat 객체 배열 생성시...
	//std::vector<Cat> cats(5);


	//dynamic allocate example
	std::cout << "how many cats?" << std::endl;
	int catCnt;
	std::cin >> catCnt;

	std::vector<Cat> cats(catCnt);

	return 0;
}