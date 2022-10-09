//				<std::unordered_set>


//hash set을 이용한다.
//insertion, deletion, find -> O(1)의 시간 복잡도

//hash function
//특정 키 값(k1, k2)을 넣으면 output이 해당 키값에 따라 unique하게 나오는 자료구조
//만약 다른 키 값을 넣었을때 이전의 다른 키 값을 넣었을때와 같은 output이 나올 수 있는 확률은 매우 희박해야 한다.

#include<iostream>
#include<string>
#include<unordered_set>>

int main()
{
	std::unordered_set<std::string> uordSet; //heap 공간에 저장된다.
	uordSet.reserve(1000);//미리 공간 확보

	uordSet.emplace("abc");
	uordSet.emplace("def");
	uordSet.emplace("gji");
	uordSet.emplace("jkl");

	std::cout << "bucket: " << uordSet.bucket_count() << std::endl; //hash 값들은 큰 값이므로
																	//bucket에 넣어두고 가져와서 쓴다.

	//bucket num까지 출력
	std::cout << "abc: " << std::hash<std::string>{}("abc") << "bucket num: " << uordSet.bucket("abc") << std::endl;
	std::cout << "def: " << std::hash<std::string>{}("def") << "bucket num: " << uordSet.bucket("def") << std::endl;
	std::cout << "gji: " << std::hash<std::string>{}("gji") << "bucket num: " << uordSet.bucket("gji") << std::endl;
	std::cout << "jkl: " << std::hash<std::string>{}("jkl") << "bucket num: " << uordSet.bucket("jkl") << std::endl;

	for (const std::string& str : uordSet)
	{
		std::cout << str << std::endl;
	}
	uordSet.find("abc"); //O(1)
	uordSet.erase("abc"); //O(1)

	return 0;
}

//find : 키값의 hash값을 구함 -> hash 값으로 부터 bucket count 정보 획득 -> 해당 카운트에 키 값이 있는 지 확인
//-> O(1)

//계속해서 값을 넣다보면 bucket count는 알아서 점차 늘어든다.
// -> 버킷 카운트가 늘어나면 버킷 넘버와 키 값이 안맞게 된다. => rehasing(재정렬 해주기) : O(n) 복잡도 
//==> 미리 공간을 확보해두는 것이 좋다. by reserve
//max_load_factor로 최대 공간을 정해둘 수 있다.(저장한 공간 넘어설 때 rehasing)