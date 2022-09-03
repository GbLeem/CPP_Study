//							<class Keywords>


//1. const 
//붙일수있는곳 모든 곳에 붙이기
// member fuction 이 member variable 을 바꾸지 않는다면 const


//2. mutable 
//const를 무시해벌임..왠만하면 쓰지 마시죠


//3. explicit
//constuctor 에서 주로 사용
//implicit conversion때문에 사용
//constructor가 argument 하나만 가진다면 explicit 써주는 것이 좋다. -> 더욱 안전함


//static 
//friend : oop의 컨셉 망가짐...조심 
//volatile : variable optimization 막음
//inline : 함수의 내용을 가져다가 함수 caller 부분에 넣어줌
//constexpr : 컴파일 시간에 const값들을 모두 값으로 지정
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
		//mName = "no kitty"; 불가능
		mName2 = "what?"; //가능
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
	nabi.print(); //만약 print가 const아니면 사용 불가능임!!


	//for explicit
	//Dog dog = 3; //explicit 없으면.. 이러한 코드가 허용된다(implicit conversion)
	Dog dog{ 3 }; //ok
	dog.printAge();
	return 0;
}


//						<encapsulation Tip>
//return 값이 큰 경우 return by const reference 방식을 사용합시다!!

class Widget
{
public:
	void setInt(int a)
	{
		i = a;
	}
	//int는 return  해주는 값이 작으니까 그냥 return by value
	int getInt()const 
	{
		return i;
	}
	void setString(std::string a)
	{
		s = std::move(a);
	}
	//string 은 return 하는 값의 크기가 크니까 const reference로 return 한다면 더욱 효과적임
	std::string BadGetString() const		// 1 copy
	{
		return s;
	}
	const std::string& GoodGetString() const // 0 copy
		//앞의 const는 해당 값을 받은 reference가 받은 문자열을 수정할 수 없다는 의미임
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