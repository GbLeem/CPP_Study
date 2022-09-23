//						<algorithms>

//sort, find, min, max, reduce

//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//int main()
//{
//	std::vector<int>nums{ 1,3,4,5,100,2,66 };
//	std::sort(nums.begin(), nums.end()/*, callable object : sorting�ϴ� ��� ���� ����*/);
//
//	for (auto num : nums)
//	{
//		std::cout << num << " ";
//	}
//	std::cout << std::endl;
//
//	//==================================================
//	
//	return 0;
//}


//stable sort ���� : ���ش�� sorting ���� + ���� �̿��� ���� stable�ϰ�
//#include <algorithm>
//#include <iostream>
//#include <string>
//#include <vector>
//
//struct Employee
//{
//    int age;
//    std::string name;  // Does not participate in comparisons
//};
//
//bool operator<(const Employee& lhs, const Employee& rhs)
//{
//    return lhs.age < rhs.age;
//}
//
//int main()
//{
//    std::vector<Employee> v =
//    {
//        {108, "Zaphod"},
//        {32, "Arthur"},
//        {108, "Ford"},
//    };
//
//    std::stable_sort(v.begin(), v.end());
//
//    for (const Employee& e : v)
//        std::cout << e.age << ", " << e.name << '\n';
//}


//partial_sort
//sorting�� �� �� ���� top n�� �̴� sorting
//nlogn complexity���ٴ� ȿ�����̴�.

//#include <algorithm>
//#include <array>
//#include <functional>
//#include <iostream>
//
//auto print = [](auto const& s, int middle) {
//    for (int a : s) { std::cout << a << ' '; }
//    std::cout << '\n';
//    if (middle > 0) {
//        while (middle-- > 0) { std::cout << "����"; }
//        std::cout << '^';
//    }
//    else if (middle < 0) {
//        for (auto i = s.size() + middle; --i; std::cout << "  ");
//        for (std::cout << '^'; middle++ < 0; std::cout << "����");
//    }
//    std::cout << '\n';
//};
//
//int main()
//{
//    std::array<int, 10> s{ 5, 7, 4, 2, 8, 6, 1, 9, 0, 3 };
//
//    print(s, 0);
//    std::partial_sort(s.begin(), s.begin() + 3, s.end());
//    print(s, 3);
//    std::partial_sort(s.rbegin(), s.rbegin() + 4, s.rend());
//    print(s, -4);
//    std::partial_sort(s.rbegin(), s.rbegin() + 5, s.rend(), std::greater{});
//    print(s, -5);
//}


//nth_element -> ���� ��ü�� ������ ���ϴ°�
//#include <algorithm>
//#include <array>
//#include <functional>
//#include <iostream>
//
//int main()
//{
//	std::vector<int> v{ 5,6,4,3,2,6,7,9,3 };
//
//	std::nth_element(v.begin(), v.begin() + v.size() / 2, v.end());
//	std::cout << "the median is " << v[v.size() / 2] << "\n";
//
//	for (int i : v)
//		std::cout << i << " "; //2 3 3 4 5 6 6 7 9 
//}


//min element
//#include <algorithm>
//#include <iostream>
//#include <vector>
//
//int main()
//{
//    std::vector<int> v{ 3, 1, 4, 1, 5, 9 };
//
//    std::vector<int>::iterator result = std::min_element(v.begin(), v.end());
//    std::cout << "min element at: " << std::distance(v.begin(), result);
//}

//min_max_element -> max�� min�� o(n) complexity�� ã����


//std::find
//#include<functional>
//#include<vector>
//#include<algorithm>
//#include<iostream>
//
//int main()
//{
//    const std::vector<int>nums{ 0,1,2,3,4 };
//
//    const auto resultIter = std::find(nums.begin(), nums.end(), 2); //ó��, ��, ã������ ����
//
//    if (resultIter != nums.end())
//    {
//        std::cout << "idx: " << std::distance(nums.begin(), resultIter) << std::endl; 
//        //distance : ã�� ���� �󸶳� ���������� �˷���
//    }
//    else
//    {
//        std::cout << "no elem found" << std::endl;
//    }
//}


//std::binary_search : sorting�� �Ϳ��� ����


//reduce
//execution policy (execution par : parallel policy ) -> accumulate���� ����



//std::accumulate -> single thread
//���� ���� �ϳ��϶� ��� -> sum and product ���� ���Ҷ�

//#include <iostream>
//#include <vector>
//#include <numeric>
//#include <string>
//#include <functional>
//
//int main()
//{
//    std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//
//    int sum = std::accumulate(v.begin(), v.end(), 0);
//
//    int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
//
//    std::cout << "sum: " << sum << '\n'
//        << "product: " << product << '\n';
//}