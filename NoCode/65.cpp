//				std::priority_queue

//abstract�� data type
//�Ϲ����� queue -> FIFO
//priority_queue -> �켱������ ����

//insert/pop -> O(log n)
// max -> O(1)
// min -> O(1) --> tree�����̹Ƿ�

//�θ� ���� �ڽ� ��庸�� ŭ, ���ο� ���Ұ� ������ ���� �Ʒ��ʺ��� ���´�. (tree������ ä��鼭)
//���� ���� ���� �� ũ�� swap�� ���ؼ� tree������ �����.

//pop()�� top�� ��ġ�� ����
//-> pop���� top�� ������� �� ������ ���� top���� �ö���� swap�ݺ��ؼ� tree������ �����.

//�⺻ ������ �����̳ʴ� vector�� �����Ǿ��ִ�.
//-> tree����������, index�� ������ �ִ� �Ͱ� ���� �����̱� ������ 


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


//���� ū ���� 3��, ���� ���� ���� 3�� ==> priority_queue�� ���ϸ� ����