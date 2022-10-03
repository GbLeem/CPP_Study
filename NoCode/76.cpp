//				<std::optional>


//변수나 오브젝트가 있을수도 있고 없을 수도 있다..
//pair를 사용하는 것 보다 가독성 good (C++ 17이후)


#include<iostream>
#include<optional>

enum class error_code
{
	Error,
	none
};

std::pair<int,error_code> divide(int a, int b)
{
	if (b == 0)
	{
		return { 0,error_code::Error };
	}
	return { a / b, error_code::none };
}

std::optional<int> divideOptional(int a, int b)
{
	if (b == 0)
	{
		return std::nullopt;
	}
	return a / b;
}

class Cat
{
public:
	void print()
	{
		std::cout << "cat " << n << std::endl;
	}
private:
	int n = 10;
};

int main()
{
	const auto answer = divideOptional(10, 0);

	if (answer)
		std::cout << answer.value() << std::endl;
	else
		//std::cout << "no value" << std::endl;
		std::cout << answer.value_or(0) << std::endl; //default value를 설정하고 출력해주기


	//================class 오브젝트=======================
	
	//std::optional<Cat> cat; //오브젝트를 만든 것은 아니다!  -> no cat yet 출력
	//std::optional<Cat> cat{ Cat() }; //오브젝트 만들어짐 but 임시 Cat 생성 후 move실행 (비효율)
	std::optional<Cat> cat{ std::in_place }; //오브젝트 생성 효율적 방식

	if (!cat)
	{
		std::cout << "no cat yet" << std::endl;
	}
	else
	{
		std::cout << "cat is ready" << std::endl;
		cat->print();
	}

	//================메모리 모델=======================
	//그림 참고 
	int num1 = 10;
	std::optional<int> num2{ 20 }; 

	
	return 0;
}