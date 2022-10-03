//				<std::pair, tuple>

//#include<iostream>
//#include<string>
//#include<utility>
//
////-1은 오류를 나타내는 flag
////enum class로 flag 표현해주는 것이 betteer -> ERROR::error, ERROR::no_error
//std::pair<int, int> divide(int a, int b)
//{
//	if (b == 0)
//		return std::make_pair<int, int>(0, -1); //{0, -1} 가능
//	return { a / b, 0 };
//}
//
//int main()
//{
//	//std::pair예시
//	std::pair<int, std::string> numstr{ 1,"good" };
//	std::cout << numstr.first << std::endl;
//	std::cout << numstr.second << std::endl;
//
//	//std::pair 응용
//	std::pair<int, int> answer = divide(10, 0);
//	if (answer.second != 0)
//	{
//		std::cout << "no answer" << std::endl;
//	}
//}

////////////////////////////////////////////////////////////

//pair의 generalized type
//코드의 가독성이 좋다.
//코드의 일부분에서만 쓸 경우에 사용하면 유용하다


#include <tuple>
#include <iostream>
#include <string>

std::tuple<double, char, std::string> get_student()
{
    return std::make_tuple(3.8, 'A', "Leem");
}

int main()
{
    //tuple 이용
    auto student0 = get_student();
    std::cout << "ID: 0, "
        << "GPA: " << std::get<0>(student0) << ", "
        << "grade: " << std::get<1>(student0) << ", "
        << "name: " << std::get<2>(student0) << '\n';

    
    //std::tie 이용
    double gpa1;
    char grade1;
    std::string name1;
    std::tie(gpa1, grade1, name1) = get_student(); //std::tie 이용 -> tuple 없이 가능
    std::cout << "ID: 1, "
        << "GPA: " << gpa1 << ", "
        << "grade: " << grade1 << ", "
        << "name: " << name1 << '\n';


    // C++17 structured binding -> 가독성 good
    auto [gpa2, grade2, name2] = get_student();
    std::cout << "ID: 2, "
        << "GPA: " << gpa2 << ", "
        << "grade: " << grade2 << ", "
        << "name: " << name2 << '\n';

    return 0;
}