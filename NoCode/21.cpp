//				<RVO-Return Value Optimization>


#include<string>
std::string getString()
{
	std::string s = "good"; //RVO�� ���� 
							//0 copy 
							//0 move 
	return s;
}
std::string getString2(std::string a,bool b)
{
	if (b)
	{
		a = "good";
	}
	return a; //RVO ���� x ->  0 copy....
	//return std::move(a); ���� ���ڰ�~
}

int main()
{
	std::string a = getString();

	return 0;
}