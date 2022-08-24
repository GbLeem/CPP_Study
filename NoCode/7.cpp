//			<Heap in Process>

#include<iostream>

int main()
{
	//int allocCount = 0;
	//std::cout << "how many?" << std::endl;
	//std::cin >> allocCount;

	//for (int i = 0; i < allocCount; i++)
	//{
	//	int* ip = new int[250];
	//	std::cout << "mem " << std::flush;
	//	delete[]ip; //delete 를 안쓰면... memory leak 발생!!!
	//}

	int sa = 0;
	int sb = 1;

	std::cout << "&sa : " << (long)&sa << std::endl;
	std::cout << "&sb : " << (long)&sb << std::endl;

	int* hap = new int;
	int* hbp = new int;

	std::cout << "&hap : " << (long)&hap << std::endl;
	std::cout << "&hbp : " << (long)&hbp << std::endl;

	std::cout << "&ha : " << (long)hap << std::endl;
	std::cout << "&hb : " << (long)hbp << std::endl;

	delete hap;
	delete hbp;

	return 0;
}

//메모리 구조 stack(위에서 부터 아래로)
//*hbp
//*hap
//sb		//사이에 공간이 없다.
//sa 

//메모리 구조 heap(아래에서 부터 위로)
//hb
// ..... 사이에 공간이 있다.
//ha