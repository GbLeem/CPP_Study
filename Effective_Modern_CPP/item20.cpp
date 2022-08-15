//ITEM 20 : Use std::weak_ptr for std::shared_ptr like pointer that can dangle

#include<iostream>
class Widget {};

int main()
{
	auto spw = std::make_shared<Widget>();

	std::weak_ptr<Widget>wpw(spw);

	spw = nullptr; //wpw�� ����� ����

	if (wpw.expired())//wpw�� ����Ű�� ��ü�� ���ٸ�..
	{

	}
}

//weak_ptr�� shared_ptr�� �̿��ؼ� �����ȴ�. �ڽ��� �����ϴµ� ���� shared_ptr�� ����Ű�� �Ͱ� ������ ��ü��
//����Ű���� ���� ī��Ʈ���� ������ ���� �ʴ´�.
//������ ������ ����.