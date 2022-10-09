//				<std::unordered_set>


//hash set�� �̿��Ѵ�.
//insertion, deletion, find -> O(1)�� �ð� ���⵵

//hash function
//Ư�� Ű ��(k1, k2)�� ������ output�� �ش� Ű���� ���� unique�ϰ� ������ �ڷᱸ��
//���� �ٸ� Ű ���� �־����� ������ �ٸ� Ű ���� �־������� ���� output�� ���� �� �ִ� Ȯ���� �ſ� ����ؾ� �Ѵ�.

#include<iostream>
#include<string>
#include<unordered_set>>

int main()
{
	std::unordered_set<std::string> uordSet; //heap ������ ����ȴ�.
	uordSet.reserve(1000);//�̸� ���� Ȯ��

	uordSet.emplace("abc");
	uordSet.emplace("def");
	uordSet.emplace("gji");
	uordSet.emplace("jkl");

	std::cout << "bucket: " << uordSet.bucket_count() << std::endl; //hash ������ ū ���̹Ƿ�
																	//bucket�� �־�ΰ� �����ͼ� ����.

	//bucket num���� ���
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

//find : Ű���� hash���� ���� -> hash ������ ���� bucket count ���� ȹ�� -> �ش� ī��Ʈ�� Ű ���� �ִ� �� Ȯ��
//-> O(1)

//����ؼ� ���� �ִٺ��� bucket count�� �˾Ƽ� ���� �þ���.
// -> ��Ŷ ī��Ʈ�� �þ�� ��Ŷ �ѹ��� Ű ���� �ȸ°� �ȴ�. => rehasing(������ ���ֱ�) : O(n) ���⵵ 
//==> �̸� ������ Ȯ���صδ� ���� ����. by reserve
//max_load_factor�� �ִ� ������ ���ص� �� �ִ�.(������ ���� �Ѿ �� rehasing)