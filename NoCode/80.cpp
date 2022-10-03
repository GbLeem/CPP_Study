//				<std::any>


//c++ 17 도입, 잘안쓴다.
// 아무 타입이나 저장할 수 있음 
// cf) void*
//void*와 type info를 가지고 있는 모습

#include<iostream>
#include<any>
#include<vector>

int main()
{
	std::vector<std::any> like_python{ 42,1.33f,"good" };

	return 0;
}
