//						<Heap Memory>

//stack 메모리 : 메모리가 쌓일때는 올리고 없앨때는 위에서 부터 없앤다.
//				top 을 기준으로 찾는다.
//heap 메모리 : 그냥 쌓임, 포인터가 메모리를 가리키는 방식

#include<iostream>

int main()
{
	int* ip;
	ip = new int;
	*ip = 100;
	delete ip;

	return 0;
}

//왜 heap 메모리를 활용해야 하는가
//1. life cycle 
// : heap 메모리에 필요한 데이터를 넣어준다 (포인터로)
//   stack 메모리가 끝나면서 사라지지 않도록 함
//2. large size
// : 너무 큰 값일때 매우 큰 메모리를 차지하는 것을 힙 메모리에 넣어두고
//	 Stack 메모리에는 가리키는 포인터만 가지게 한다.
//3. dynamic(runtime)
// : stack 메모리는 컴파일 시간에 결정
//   포인터만 stack 메모리에 가지고 heap 메모리에서 동적인 생성 가능하다.
