//ITEM 29 : Assume that move operations are not present, not cheap, and not used

#include<array>
#include<vector>

//move�� ���� ����
//�̵��� O(1)
std::vector<int> vi1;
auto vi2 = std::move(vi1);

//move�� ���� ���� ����
//array�� ��� �̵��� ���簡 ��� o(n) �ð��̴�.
std::array<int, 10000>ai1;
auto ai2 = std::move(ai1);