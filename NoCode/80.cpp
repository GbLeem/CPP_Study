//				<std::any>


//c++ 17 ����, �߾Ⱦ���.
// �ƹ� Ÿ���̳� ������ �� ���� 
// cf) void*
//void*�� type info�� ������ �ִ� ���

#include<iostream>
#include<any>
#include<vector>

int main()
{
	std::vector<std::any> like_python{ 42,1.33f,"good" };

	return 0;
}
