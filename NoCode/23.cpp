//				<object Alignment>


//remind) ������ 64����Ʈ ȯ�濡�� 8byte

#include<iostream>
#include<array>

class Cat
{
public:
	void speak();
private:
	//<case1>
	//double d8;
	//int i4a;
	//int i4b;

	//<case2>
	int i4a; //0~4 int, 4~8 padding
	double d8; //8~16 double
	int i4b;//16~20 int, 20~24 padding
};

int main()
{
	Cat stackCat;
	//std::cout << sizeof(stackCat) << std::endl; //case1 : 16 byte
	std::cout << sizeof(stackCat) << std::endl; //case2 : 24 byte ->by memory padding
												//1. �� ����������� �ڽ��� ����Ʈ���� ������� �����ؾ���
												//2. �ش� ������Ʈ�� �޸� ũ��� ���� ū ��� ������ ����� ����

	//<advanced..>
	std::array<Cat, 100> cats; //�߰��� �е��� ����ִ� �迭�� ���..
							   //Cache line�̶�� �ϵ������ ������ �����͸� 64 ����Ʈ�� �߶� �ٸ� �ھ�� ��
							   //Cat�� ��� 64�� �߶����� �߰��� ���� �߶������ �Ǵ� ������ �߻��Ѵ�.(false sharing)
	/*class alignas(32) Cat    ������ ���� �ٲ��־� ���� ������ �ذ��� �� �ִ�.
	{
	};*/
	
	return 0;
}