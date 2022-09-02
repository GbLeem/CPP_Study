//				<L-value vs R-value>


#include<string>
int a/*l value*/ = 0/*rvalue*/;
int b/*l value*/ = a/*l value*/;

//한번 부르고 다시 부를 수 있다면 l value

std::string s/*L value*/ = "abc"/*R value*/;

int c = std::move(a); //move를 통해서 lval 가 rval로 변함

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

void storeByValue(std::string s) //2 copy
{
	std::string b = s;
}

void storeByLRef(std::string& s) //1 copy
{
	std::string b = s;
}

void storeByRRef(std::string&& s) //0 copy
{
	//std::string b = s; //wrong! s는 해당 경우 lvalue이다.
	std::string b = std::move(s);
}
int main()
{
	std::string a = "abc";
	storeByValue(a);
	storeByLRef(a);
	storeByRRef(std::move(a));
}