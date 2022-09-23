//						<std::array>


//array : stack공간에 allocate / compile시간에 size 확보/ stack frame / 컴파일 시간에 size를 알아야 한다./ fixes size
//-> fast
//vector : heap공간에 allocate / runtime에 size확보 / flexible size
// ->slow (공간을 미리 확보하고 사용하면 속도 보완 가능)

//공통점: 연속적인 메모리 공간차지, random access가능!

#include<iostream>
#include<array>
#include<vector>

void fnArray()
{
	std::array<int, 100>nums;
}

void fnVector()
{
	std::vector<int> nums(100);
	nums.resize(10000); //runtime에 size 확보
}
int main()
{
	//int nums[100];
	//std::array<int, 100>nums; //better

	fnArray();
	fnVector();

	return 0;
}

