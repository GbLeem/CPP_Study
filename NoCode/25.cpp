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
	//	mkitty = Cat(kittyage); //�ӽ� ��ü ���� �� kitty�� ����ȴ��� ���� -> �ʿ���� ����
	//}
	Zoo(int kittyage)
		:mkitty(Cat(kittyage)) //member initialize -> �ӽ� ��ü ���� x 
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