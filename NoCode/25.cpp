//					<Member init List>


class Cat
{
public:
	/*Cat()
	{
		mAge = 1;
	}*/

	Cat()			//member initialize
		:mAge(1)
	{}

	/*Cat(int age)
	{
		mAge = age;
	}*/

	Cat(int age)	//member initialize
		:mAge(age)
	{}
private:
	int mAge;
};

class Zoo
{
public:
	//Zoo(int kittyage)
	//{
	//	mkitty = Cat(kittyage); //임시 객체 생성 후 kitty에 복사된다음 삭제 -> 필요없는 과정
	//}
	Zoo(int kittyage)
		:mkitty(Cat(kittyage)) //member initialize -> 임시 객체 생성 x 
	{
	}
private:
	Cat mkitty;
};

int main()
{
	Zoo cppZoo(5);
	return 0;
}