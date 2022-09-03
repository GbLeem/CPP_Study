//							<class Keywords>


//1. const 
//���ϼ��ִ°� ��� ���� ���̱�
// member fuction �� member variable �� �ٲ��� �ʴ´ٸ� const


//2. mutable 
//const�� �����ع���..�ظ��ϸ� ���� ������


//3. explicit
//constuctor ���� �ַ� ���
//implicit conversion������ ���
//constructor�� argument �ϳ��� �����ٸ� explicit ���ִ� ���� ����. -> ���� ������


//static 
//friend : oop�� ���� ������...���� 
//volatile : variable optimization ����
//inline : �Լ��� ������ �����ٰ� �Լ� caller �κп� �־���
//constexpr : ������ �ð��� const������ ��� ������ ����
#include<iostream>
#include<string>

//for const and mutable
class Cat
{
public:
	Cat(std::string name)
		:mName(std::move(name))
	{
	}
	void print() const
	{
		//mName = "no kitty"; �Ұ���
		mName2 = "what?"; //����
		std::cout << mName << std::endl;
	}

private:
	std::string mName;
	mutable std::string mName2;
};


//for explicit
class Dog
{
public:
	explicit Dog(int age)
		:mAge(age)
	{
	}
	void printAge() const
	{
		std::cout << mAge << std::endl;
	}
private:
	int mAge;
};
int main()
{
	//for const and mutable
	Cat kitty{ "kitty" };
	kitty.print();

	const Cat nabi{ "nabi" };
	nabi.print(); //���� print�� const�ƴϸ� ��� �Ұ�����!!


	//for explicit
	//Dog dog = 3; //explicit ������.. �̷��� �ڵ尡 ���ȴ�(implicit conversion)
	Dog dog{ 3 }; //ok
	dog.printAge();
	return 0;
}


//						<encapsulation Tip>
//return ���� ū ��� return by const reference ����� ����սô�!!

class Widget
{
public:
	void setInt(int a)
	{
		i = a;
	}
	//int�� return  ���ִ� ���� �����ϱ� �׳� return by value
	int getInt()const 
	{
		return i;
	}
	void setString(std::string a)
	{
		s = std::move(a);
	}
	//string �� return �ϴ� ���� ũ�Ⱑ ũ�ϱ� const reference�� return �Ѵٸ� ���� ȿ������
	std::string BadGetString() const		// 1 copy
	{
		return s;
	}
	const std::string& GoodGetString() const // 0 copy
		//���� const�� �ش� ���� ���� reference�� ���� ���ڿ��� ������ �� ���ٴ� �ǹ���
	{
		return s;
	}

private:
	int i;
	std::string s;
};

int main()
{
	Widget w;
	w.setString("good");
	std::string str1 = w.BadGetString(); //1 copy
	const std::string& str2 = w.GoodGetString(); //0 copy

	return 0;
}