//ITEM 29 : Assume that move operations are not present, not cheap, and not used

#include<array>
#include<vector>

//move가 좋은 예시
//이동은 O(1)
std::vector<int> vi1;
auto vi2 = std::move(vi1);

//move가 좋지 않은 예시
//array의 경우 이동과 복사가 모두 o(n) 시간이다.
std::array<int, 10000>ai1;
auto ai2 = std::move(ai1);