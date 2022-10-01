//				<std::map>

//set에 key value concept를 넣음

#include<iostream>
#include<map>
#include<string>

int main()
{
	std::map<int, int> numPairs;
	std::map<int, std::string> nameLists;

	numPairs.emplace(1, 101);
	numPairs.emplace(2, 102);
	numPairs.emplace(3, 103);
	numPairs.emplace(4, 104);
	numPairs.emplace(5, 105);
	numPairs.emplace(5, 505); //key값 중복 안되기 때문에 스스로 삭제해준다.

	numPairs[1] = 1001; //key값이 1인 것에 value값을 바꿔줌

	std::cout << numPairs[6];// 지정하지 않은 key값에 대한 사용을 하면 알아서 key가 6인 map을 초기화해서 답을 준다
	//-> 원치 않은 동작이 발생할 수 있으므로 주의하기

	//트리를 만들때 key값을 기준으로 만들고 해당 키값에는 value값이 따라온다.
	for (const auto &num:numPairs)
	{
		std::cout << num.first/*key*/ << " " << num.second/*value*/ << std::endl;
	}

	//int와 string 짝으로도 사용 가능 -> string을 key로 하면 알파벳 순으로 정렬해준다.
	nameLists.emplace(1, "cat");
	nameLists.emplace(3, "dog");
	nameLists.emplace(2, "person");

	for (const auto& name : nameLists)
	{
		std::cout << name.first << ", " << name.second << std::endl;
	}

	return 0;
}