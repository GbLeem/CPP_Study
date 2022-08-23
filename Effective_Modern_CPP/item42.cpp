//ITEM 42 

#include<vector>
#include<string>
#include<iostream>
#include<list>
int main()
{
	std::vector <std::string> vs;
	vs.push_back("abc"); 
	//-> vs.push_back(std::string("abc")); ���� ���
	//-> �ش� ���� ���� push_back�� �μ��� �޶� �ӽð�ü ������ �Ҹ� ������ �����.

	//���� ���� �Լ�
	vs.emplace_back("abc");// std::vector �ȿ��� std::string�� �����Ѵ�.(�ӽð�ü ����x)

	//�Ϲ� ���� �Լ��� ���� ���Ժ��� ���� ��쵵 �����Ѵ�.

	//     <���� ������ �� ȿ������ ���ǵ�>
	//1. �߰��� ���� �����̳ʿ� �����Ǵ� ���� �ƴ϶� �����̳� �ȿ��� �����ȴ�.
	//2. �߰��� �μ������� �����̳ʰ� ��� ���İ� �ٸ���.
	//3. �����̳ʰ� ���� ������ �ߺ� ������ �� ���� �ź��� ����� ���� ����.
}


class Widget{};
std::list < std::shared_ptr<Widget>>ptrs;
void killWidget(Widget* pWidget);

int main()
{
	ptrs.push_back(std::shared_ptr<Widget>(new Widget, killWidget));
	ptrs.emplace_back(new Widget, killWidget); //�ڿ� ���� ���ɼ�.. 
	//new Widget�� emplace_back�̳� push_back�� ���� �ִ°� ���� �ʴ�.

	//�� ��ĺ��� better
	std::shared_ptr<Widget>spw(new Widget, killWidget); //���� ��ü ����

	ptrs.push_back(std::move(spw)); //rval�� ����
	ptrs.emplace_back(std::move(spw));
}




