//					<static Members>


#include<iostream>
// ���� ���μ����� static�� �ٸ�

//<Static in Class>
//1. Static member function
//������Ʈ�� ����Ű�� this ������ ����
//������Ʈ�� ������ �Ǿ����� �ʴ�.

//2. Static member variable
//���α׷��� ����Ǳ� ���� �ʱ�ȭ �ʿ�

//3. Static variable in a function
//�ڵ��� �������� ���ؼ�
class Cat
{
public:
	void speak()
	{
		static int safeCount = 0; //Static variable in a function
		count++;
		safeCount++;
		std::cout << "meow" << " count : " << count<<" , safe : "<<safeCount  << std::endl;
	}
	static void staticSpeak() //Static member function
	{
		std::cout << "CAT" << std::endl;
		//std::cout << mAge << std::endl; ��� ������ ���� x
		//speak(); ��� �Լ� ���� x
	}
	static int count; //Static member variable

private:
	int mAge;
};

int Cat::count = 0; //static member variable �ʱ�ȭ

int main()
{
	//Static Member function ���� �ڵ�
	//Cat kitty;
	//kitty.speak();
	//kitty.staticSpeak();// ok
	//
	//Cat::staticSpeak(); //������Ʈ ������ �ʾƵ� ��� ����
	//--------------------------------------------------------
	//Static member variable ���� �ڵ�
	Cat kitty;
	Cat nabi;
	kitty.speak(); //meow 1
	nabi.speak();  //meow 2
	Cat::count = 0; // ��ó�� ���� ��� �ƹ��뼭�� ���� ����..(�ذ� : �� ��� speak�Լ� �ȿ����� ���ϱ� speak�Լ� �ȿ��� 
					// ���� �ع����� ���! -> �ٸ��뼭 ���� ����) => static variable in function
					
	//Cat::safeCount = 0; //�Ұ���! ���� ������ �ذ��� ��

	return 0;
}




