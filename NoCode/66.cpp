//				std::make_heap

//�Ϲ����� vector�� array�� heap������ ������ش�.

//heap : max�� top�� tree ����

//vector : 1 3 5 7 9 11  -> heap���� �����!!(make_heap)

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

    v.emplace_back(100); //���� �ֱ�
    print("after emplace_back, v", v);

    std::push_heap(v.begin(), v.end()); //�ٽ� heap���� ���� O(log n)
    print("after push_heap, v", v);
    return 0;
}