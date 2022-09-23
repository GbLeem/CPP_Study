//					std::deque, Vector vs Array

//O(1)의 random access
//deque : double ended queue
//연속적인 데이터 저장은 아니다. by pointer reference

#include <iostream>
#include <deque>

int main()
{
    // Create a deque containing integers
    std::deque<int> d = { 7, 5, 16, 8 };

    // Add an integer to the beginning and end of the deque
    //d.push_front(13);
    //d.push_back(25);

    d.emplace_front(13); //better
    d.emplace_back(25);

    // Iterate and print values of deque
    for (int n : d) {
        std::cout << n << ' ';
    }
}
