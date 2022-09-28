//				std::priority_queue

//abstract한 data type
//일반적인 queue -> FIFO
//priority_queue -> 우선순위를 가짐

//insert/pop -> O(log n)
// max -> O(1)
// min -> O(1) --> tree구조이므로

//부모 노드는 자식 노드보다 큼, 새로운 원소가 들어오면 왼쪽 아래쪽부터 들어온다. (tree구조를 채우면서)
//새로 들어온 값이 더 크면 swap을 통해서 tree구조를 만든다.

//pop()은 top의 위치만 가능
//-> pop으로 top이 사라지면 맨 오르쪽 끝이 top으로 올라오고 swap반복해서 tree구조를 만든다.

//기본 데이터 컨테이너는 vector로 구현되어있다.
//-> tree구조이지만, index가 가지고 있는 것과 같은 구조이기 떄문에 


//parent = (idx-1)/2
//Left child = 2*idx + 1
//Right child = 2*idx +2

#include<iostream>
#include<queue>

int main()
{
	std::priority_queue<int> q;
	q.emplace(1);
	q.emplace(3);
	q.emplace(5);
	q.emplace(7);
	q.emplace(9);

	std::cout << q.top() << std::endl;

	q.emplace(10); // O(log n)

	std::cout << q.top() << std::endl;//O(1)

	q.pop();
	q.pop();
	q.pop();
	std::cout << q.top() << std::endl;
}


//가장 큰 숫자 3개, 가장 작은 숫자 3개 ==> priority_queue로 구하면 좋음