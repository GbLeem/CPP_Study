//					<std::unordered_map>


//unordered map: key�� value�� ������ ����, hash�� ���� -> find,inset,delete : O(1)

//map: key�� value������ ����, tree���� ->  find,inset,delete : O(logn)

#include<iostream>
#include<unordered_map>
#include<string>

int main()
{
	std::unordered_map<int, std::string> idNames;
	//std::unordered_multimap<int, std::string> idNames; �ߺ� ���
	idNames.emplace(1234, "Leem");
	idNames.emplace(1111, "Kim");
	idNames.emplace(9999, "Park");

	idNames.emplace(1111, "KIMKIM"); //�ߺ� ����
	idNames[1111] = "KIM";

	for (const auto& name : idNames)
	{
		std::cout << name.first << " " << name.second << std::endl;
	}
}

//			<����>

//set : tree, O(logn), ���������� comparision operator ���� �ʿ�, �ڵ� sorted, 
//key�� ���

//map : tree, O(logn), ���������� comparision operator ���� �ʿ�, �ڵ� sorted, 
//key�� value���

//unordered_set : hash, O(1), hash function�� == operator���� �ʿ�, sorted x, ������ Ŀ���� O(n)�� rehasing, 
//key�� ���

//unordered_map : hash, O(1), hash function�� == operator���� �ʿ�, sorted x, ������ Ŀ���� O(n)�� rehasing, 
//key�� value���

//������ : �ߺ� ����
//=> multi-�پ������� �ߺ��� ���ȴ�.

//unordered_map�� ���� ���� ����.