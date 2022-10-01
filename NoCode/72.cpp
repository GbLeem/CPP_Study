//					<std::unordered_map>


//unordered map: key와 value의 쌍으로 구성, hash로 구성 -> find,inset,delete : O(1)

//map: key와 value쌍으로 구성, tree구조 ->  find,inset,delete : O(logn)

#include<iostream>
#include<unordered_map>
#include<string>

int main()
{
	std::unordered_map<int, std::string> idNames;
	//std::unordered_multimap<int, std::string> idNames; 중복 허용
	idNames.emplace(1234, "Leem");
	idNames.emplace(1111, "Kim");
	idNames.emplace(9999, "Park");

	idNames.emplace(1111, "KIMKIM"); //중복 제거
	idNames[1111] = "KIM";

	for (const auto& name : idNames)
	{
		std::cout << name.first << " " << name.second << std::endl;
	}
}

//			<정리>

//set : tree, O(logn), 내부적으로 comparision operator 정의 필요, 자동 sorted, 
//key만 고려

//map : tree, O(logn), 내부적으로 comparision operator 정의 필요, 자동 sorted, 
//key와 value고려

//unordered_set : hash, O(1), hash function과 == operator정의 필요, sorted x, 사이즈 커지면 O(n)의 rehasing, 
//key만 고려

//unordered_map : hash, O(1), hash function과 == operator정의 필요, sorted x, 사이즈 커지면 O(n)의 rehasing, 
//key와 value고려

//공통점 : 중복 제거
//=> multi-붙어있으면 중복이 허용된다.

//unordered_map이 가장 많이 쓴다.