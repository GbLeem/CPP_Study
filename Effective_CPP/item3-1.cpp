#include <iostream>

class TextBlock
{
public:
	TextBlock()
	{
	}
	TextBlock(std::string str)
	{
		text = str;
	}
	//앞에 있는 const : 반환 타입이 const
	//뒤에 있는 const : 함수내 멤버변수의 변경 막음 -> const objects
	const char& operator[](std::size_t position) const 
	{
		return text[position];
	}
	char& operator[](std::size_t position)
	{
		return text[position];
	}
	void print(const TextBlock& ctb)
	{
		std::cout << ctb[0];
	}
private:
	std::string text;
};

int main()
{
	//-------------------------------------
	TextBlock tb("Hello");
	std::cout << tb[0] << '\n';
	tb[0] = 'x'; //ok

	const TextBlock ctb("Wolrd");
	std::cout << ctb[0] << '\n';
	//ctb[0] = 'x';//error -> writing a const TextBlock

	tb.print(ctb);
	//-------------------------------------
}
