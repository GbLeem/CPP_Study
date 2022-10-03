//				<std::optional>


//������ ������Ʈ�� �������� �ְ� ���� ���� �ִ�..
//pair�� ����ϴ� �� ���� ������ good (C++ 17����)


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
		std::cout << answer.value_or(0) << std::endl; //default value�� �����ϰ� ������ֱ�


	//================class ������Ʈ=======================
	
	//std::optional<Cat> cat; //������Ʈ�� ���� ���� �ƴϴ�!  -> no cat yet ���
	//std::optional<Cat> cat{ Cat() }; //������Ʈ ������� but �ӽ� Cat ���� �� move���� (��ȿ��)
	std::optional<Cat> cat{ std::in_place }; //������Ʈ ���� ȿ���� ���

	if (!cat)
	{
		std::cout << "no cat yet" << std::endl;
	}
	else
	{
		std::cout << "cat is ready" << std::endl;
		cat->print();
	}

	//================�޸� ��=======================
	//�׸� ���� 
	int num1 = 10;
	std::optional<int> num2{ 20 }; 

	
	return 0;
}