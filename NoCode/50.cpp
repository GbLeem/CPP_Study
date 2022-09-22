//			Lambda This

#include<iostream>

class Cat
{
public:
	explicit Cat(int age)
		:mAge{age}
	{}
	void speak() const
	{
		std::cout << "CAT" << std::endl;
	}
	void test() const
	{
		//auto lambda = []()
		//{
		//	std::cout << "lambdaFunction" << std::endl;
		//	std::cout << mAge << std::endl; //������ ����
		//	speak(); //������ ����
		//	lambda expression function �ٵ� �ȿ��� �ٱ� �������� ���� �Ұ���
		//	->auto lambda = [&]() ����ϸ� ���� ������ ���� �Ȼ���
		//};
		//lambda();

		auto lambda = [this]()  //�����̶� ���� �ǹ� -> auto lambda = [&]() 
		{
			std::cout << "lambdaFunction" << std::endl;
			std::cout << this->mAge << std::endl;
			this->speak();
		};
		lambda();
	}
private:
	int mAge;
};

int main()
{
	Cat kitty{ 1 };
	kitty.test();

	return 0;
}


//Lambda expression + STL

#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
	std::vector<int>nums{ 1,2,3,4,5,6,7,8,9,10 };

	/*auto lambdaAdd10 = [](int& n)
	{
		n += 10;
	};*/
	
	//int n = 10;
	//lambdaAdd10(n);
	//std::cout << n << std::endl; //20 ���
	
	//for_each!!
	//std::for_each(nums.begin(), nums.end(), lambdaAdd10);

	//better
	std::for_each(nums.begin(), nums.end(), [](int& n)
	{
		n += 10;
	});

	for (int num : nums)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;

	return 0;
}
