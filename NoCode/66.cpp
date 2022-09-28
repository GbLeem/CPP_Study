//				std::make_heap

//일반적인 vector나 array를 heap구조로 만들어준다.

//heap : max가 top인 tree 구조

//vector : 1 3 5 7 9 11  -> heap으로 만들기!!(make_heap)

#include <algorithm>
#include <functional>
#include <iostream>
#include <string_view>
#include <vector>

void print(std::string_view text, std::vector<int> const& v = {}) 
{
    std::cout << text << ": ";
    for (const auto& e : v) std::cout << e << ' ';
    std::cout << '\n';
}

int main()
{
    print("Max heap");

    std::vector<int> v{ 3, 2, 4, 1, 5, 9 };
    print("initially, v", v);

    std::make_heap(v.begin(), v.end()); //O(n)
    print("after make_heap, v", v);

    std::pop_heap(v.begin(), v.end()); //O(log n)
    print("after pop_heap, v", v);

    auto top = v.back();
    v.pop_back();
    print("former top element", { top });
    print("after removing the former top element, v", v);

    v.emplace_back(100); //숫자 넣기
    print("after emplace_back, v", v);

    std::push_heap(v.begin(), v.end()); //다시 heap으로 정렬 O(log n)
    print("after push_heap, v", v);
    return 0;
}