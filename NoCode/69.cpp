//				<std::map>

//set�� key value concept�� ����

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
	numPairs.emplace(5, 505); //key�� �ߺ� �ȵǱ� ������ ������ �������ش�.

	numPairs[1] = 1001; //key���� 1�� �Ϳ� value���� �ٲ���

	std::cout << numPairs[6];// �������� ���� key���� ���� ����� �ϸ� �˾Ƽ� key�� 6�� map�� �ʱ�ȭ�ؼ� ���� �ش�
	//-> ��ġ ���� ������ �߻��� �� �����Ƿ� �����ϱ�

	//Ʈ���� ���鶧 key���� �������� ����� �ش� Ű������ value���� ����´�.
	for (const auto &num:numPairs)
	{
		std::cout << num.first/*key*/ << " " << num.second/*value*/ << std::endl;
	}

	//int�� string ¦���ε� ��� ���� -> string�� key�� �ϸ� ���ĺ� ������ �������ش�.
	nameLists.emplace(1, "cat");
	nameLists.emplace(3, "dog");
	nameLists.emplace(2, "person");

	for (const auto& name : nameLists)
	{
		std::cout << name.first << ", " << name.second << std::endl;
	}

	return 0;
}