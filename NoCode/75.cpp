//				<std::pair, tuple>

//#include<iostream>
//#include<string>
//#include<utility>
//
////-1�� ������ ��Ÿ���� flag
////enum class�� flag ǥ�����ִ� ���� betteer -> ERROR::error, ERROR::no_error
//std::pair<int, int> divide(int a, int b)
//{
//	if (b == 0)
//		return std::make_pair<int, int>(0, -1); //{0, -1} ����
//	return { a / b, 0 };
//}
//
//int main()
//{
//	//std::pair����
//	std::pair<int, std::string> numstr{ 1,"good" };
//	std::cout << numstr.first << std::endl;
//	std::cout << numstr.second << std::endl;
//
//	//std::pair ����
//	std::pair<int, int> answer = divide(10, 0);
//	if (answer.second != 0)
//	{
//		std::cout << "no answer" << std::endl;
//	}
//}

////////////////////////////////////////////////////////////

//pair�� generalized type
//�ڵ��� �������� ����.
//�ڵ��� �Ϻκп����� �� ��쿡 ����ϸ� �����ϴ�


#include <tuple>
#include <iostream>
#include <string>

std::tuple<double, char, std::string> get_student()
{
    return std::make_tuple(3.8, 'A', "Leem");
}

int main()
{
    //tuple �̿�
    auto student0 = get_student();
    std::cout << "ID: 0, "
        << "GPA: " << std::get<0>(student0) << ", "
        << "grade: " << std::get<1>(student0) << ", "
        << "name: " << std::get<2>(student0) << '\n';

    
    //std::tie �̿�
    double gpa1;
    char grade1;
    std::string name1;
    std::tie(gpa1, grade1, name1) = get_student(); //std::tie �̿� -> tuple ���� ����
    std::cout << "ID: 1, "
        << "GPA: " << gpa1 << ", "
        << "grade: " << grade1 << ", "
        << "name: " << name1 << '\n';


    // C++17 structured binding -> ������ good
    auto [gpa2, grade2, name2] = get_student();
    std::cout << "ID: 2, "
        << "GPA: " << gpa2 << ", "
        << "grade: " << grade2 << ", "
        << "name: " << name2 << '\n';

    return 0;
}