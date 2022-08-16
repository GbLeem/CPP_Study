//ITEM 21 : Prefer std::make_unique and std::make_shared to direct use of new

#include<iostream>

//make_unique�� ����
template<typename T,typename... Ts>
std::unique_ptr<T> make_unique(Ts&&...params)
{
	return std::unique_ptr<T>(new T(std::forward<Ts>(params)...));
}


//make ��aaa��
class Widget {};

auto upw1(std::make_unique<Widget>());   //make ���
std::unique_ptr<Widget>upw2(new Widget); //new ���

auto spw1(std::make_shared<Widget>());   //make ���
std::shared_ptr<Widget>spw2(new Widget); //new ��� -> new ����� ��� Widget�� �ι��ݺ�.. bad

//make�� ���� �������� ����
void processWidget(std::shared_ptr<Widget> spw, int priority);

int computerPriority();
processWidget(std::shared_ptr<Widget>(new Widget), computerPriority()); //�ڿ� ���� ����

processWidget(std::make_shared<Widget>(), computerPriority()); //�ڿ� ���� x


//make ����1 : Ŀ���� �����ڸ� �����Ҽ� �ִ� ���� ����.
//make ����2 : ��ȣ�� �߰�ȣ�� ���� -> make�� �ʱ�ȭ ���������� () ����ϵ��� �Ǿ��ִ�.


void processWidget(std::shared_ptr<Widget>spw, int priority);
void cusDel(Widget* ptr); //Ŀ���� ������

processWidget(std::shared_ptr<Widget>(new Widget, cusDel), computerPriority()); //�ڿ� ���� ����

std::shared_ptr<Widget>spw(new Widget, cusDel);
processWidget(spw, computerPriority()); //���ܷ� ���� �����ϱ�� ��

processWidget(std::move(spw), computerPriority());//good