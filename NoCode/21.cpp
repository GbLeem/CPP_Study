//				<RVO-Return Value Optimization>


#include<string>

std::string getString() //RVO 개입
{
	std::string s = "good"; //RVO를 통해 
							//0 copy 
							//0 move 
	return s;
}

std::string getString2(std::string a,bool b) //RVO 개입x
{
	if (b)
	{
		a = "good";
	}
	return a; //RVO 개입 x(복사 할지, 바로 string을 가리키게 할지 모름)
	//그럼에도 불구하고..move constructor에 의해 0 copy
}

int main()
{
	std::string a = getString(); //move constructor 실행

	return 0;
}