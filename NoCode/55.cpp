//					<vector memeory>


//�� �ڿ� push, pop�ϴ� ��� O(1) �׷��� ��������� ����
//�������� ���� O(n)�� �ȴ�..

#include<iostream>
#include<vector>
#include<string>

//int main()
//{
//	std::vector<int>nums;
//	std::cout << sizeof(nums) << std::endl; //24
//	//�ƹ��͵� ���� �����ε� 24 ����Ʈ�� ���´�
//	//1. heap�����ִ� array�� ������ ����Ű�� ������(8byte)
//	//2. size (8byte) -> ���� ���Ϳ� ����ִ� element�� ����
//	//3. capacity (8byte) -> ���Ͱ� Ȯ���� �޸��� ũ��-> Ȯ���� ��array�� ������ �ǹǷ� o(1)�� complexity!
//	//capacity�� �����صа� ���� �� ���� ���� �����͸� �������� O(n)�� complexity�� �Ǵ°��̴�.
//	//������ �������� ��ü�� ���� �Ǵ� move�� �ؾ��ϹǷ� O(n) -> reserve�� �̸� ������ ����� �δ� ���� ����. 
//
//	//capacity�� ������Ű�� �Լ� : reserve
//	nums.reserve(10000);
//	std::cout << nums.size() << std::endl; //0
//	std::cout << nums.capacity() << std::endl; //10000
//
//	return 0;
//}


class Cat
{
public:
	explicit Cat(std::string name)
		:mName{ std::move(name) }
	{
		std::cout << mName << " cat constructor" << std::endl;
	}
	~Cat()
	{
		std::cout << "cat destructor" << std::endl;
	}
	Cat(const Cat& other)
		:mName(other.mName)
	{
		std::cout << mName << " copy constructor" << std::endl;
	}
	Cat(Cat&& other) noexcept
		:mName(other.mName)
	{
		std::cout << mName << " move constructor" << std::endl;
	}
private:
	std::string mName;
};
int main()
{
	std::vector<Cat>cats;
	cats.reserve(2); // migration ���ֱ�! -> ���� ���� ���
	cats.emplace_back("kitty");
	cats.emplace_back("nabi");
	return 0;
	
	//<���>
	//kitty cat constructor
	//nabi cat constructor
	//kitty copy constructor -> move constructor�� noexcept�� �ϸ� move constructor ����Ѵ�.
	//cat destructor
	//cat destructor
	//cat destructor

	//destructor, move constructor, move assignment�� noexcept�� ���̱�
}