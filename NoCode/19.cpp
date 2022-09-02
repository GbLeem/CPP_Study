//				<L-value vs R-value>


#include<string>
int a/*l value*/ = 0/*rvalue*/;
int b/*l value*/ = a/*l value*/;

//�ѹ� �θ��� �ٽ� �θ� �� �ִٸ� l value

std::string s/*L value*/ = "abc"/*R value*/;

int c = std::move(a); //move�� ���ؼ� lval �� rval�� ����

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
	//std::string b = s; //wrong! s�� �ش� ��� lvalue�̴�.
	std::string b = std::move(s);
}
int main()
{
	std::string a = "abc";
	storeByValue(a);
	storeByLRef(a);
	storeByRRef(std::move(a));
}