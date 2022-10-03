//				<std::variant>

// union�� �����ϰ� ���� ���
//�������� union : type traking �����Ͽ� overhead�� �����ϱ�� �ϴ�.

#include<iostream>
#include<variant>
#include<vector>

struct S 
{
	int i;
	double d;
	float f;
};

union  U 
{
	int i; 
	double d; 
	float f;
};

int main()
{
	std::variant<int, double,float> V;
	std::cout << sizeof(S) << std::endl; //24
	std::cout << sizeof(U) << std::endl; //8
	std::cout << sizeof(V) << std::endl; //16

	std::variant<std::string, std::vector<int>> sv;
	sv = std::string("good");

	std::cout << std::get<std::string>(sv) << std::endl; //�����ڳ� �Ҹ��� �����ص� ������ ��������

	sv = std::vector{ 1,2,3 };

	return 0;
}

//�������� tuple �̳� pair�� ���������� variant�� �����ϸ� int�� error_code�� ���� �޸𸮰����� �����ϸ鼭
// �޸� ������ �����ϴ�.
//std::variant<int, error_code> divide(int a, int b)
