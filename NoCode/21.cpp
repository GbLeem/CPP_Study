//				<RVO-Return Value Optimization>


#include<string>

std::string getString() //RVO ����
{
	std::string s = "good"; //RVO�� ���� 
							//0 copy 
							//0 move 
	return s;
}

std::string getString2(std::string a,bool b) //RVO ����x
{
	if (b)
	{
		a = "good";
	}
	return a; //RVO ���� x(���� ����, �ٷ� string�� ����Ű�� ���� ��)
	//�׷����� �ұ��ϰ�..move constructor�� ���� 0 copy
}

int main()
{
	std::string a = getString(); //move constructor ����

	return 0;
}