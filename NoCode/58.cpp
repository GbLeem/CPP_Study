//						<std::array>


//array : stack������ allocate / compile�ð��� size Ȯ��/ stack frame / ������ �ð��� size�� �˾ƾ� �Ѵ�./ fixes size
//-> fast
//vector : heap������ allocate / runtime�� sizeȮ�� / flexible size
// ->slow (������ �̸� Ȯ���ϰ� ����ϸ� �ӵ� ���� ����)

//������: �������� �޸� ��������, random access����!

#include<iostream>
#include<array>
#include<vector>

void fnArray()
{
	std::array<int, 100>nums;
}

void fnVector()
{
	std::vector<int> nums(100);
	nums.resize(10000); //runtime�� size Ȯ��
}
int main()
{
	//int nums[100];
	//std::array<int, 100>nums; //better

	fnArray();
	fnVector();

	return 0;
}

