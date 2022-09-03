//				<Heap, Stack, Static>

//Stack
// : stack frame ������ 
// ������ ���� �Ʒ��� ���� ����
// allocate, disallocate ������.
// dynamic allocate �Ұ���
// ū �޸� �Ҵ�� stack overflow �߻� ����

//Heap
// : ����ִ� ���� Ȯ��
// ���α׷� ���� ���� �߿� Ȯ��
// �޸� �Ҵ� ���� �ð��� ������(stack ����)
// dynamic allocate ����!
// ū �޸� �Ҵ� ����

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
	std::array<Cat, maxCats> cats; //performance critical �ϰ� �����
};

int main()
{
	int i, double d, float f; //stack allocate 
	std::array<int, 300> a1;//1.2kb ->stack allocate

	std::array<int, 500000> a2; //2mb -> heap allocate
	std::vector<int> b(500000); //heap allocate;

	Cat cat; //stack allocate (�뷮�� n kb ���� �϶�)


	//�Լ� �� ��
	int count;
	std::cin >> count;
	foo(count); // �̷��Ը� �ϸ� slow...

	//performance cirtical �ϱ� ���ؼ�...!
	for (int i = 0; i < 10000; ++i)
	{
		bar(count);
	}
}

//static, global ��ü���� heap �޸� �Ʒ����� ����
//

