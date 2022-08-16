//ITEM 22 : When using the Pimpl Idiom, define special member functions in the implementation file


//<Pimpl>
//1. �ҿ��� ����(incomplete type)�� ����Ű�� �����͸� �ϳ��� ����� ����
//2. ������ Ŭ�������� ����ϴ� �ڷ� ������� ��� ��ü�� �������� �Ҵ�, �����ϴ� �ڵ� �߰�

#include<iostream>

//Widget.h
class Widget
{
public:
	Widget();
	~Widget(); // std::unique_ptr<Widget::Impl>�� �ı��ϴ� �ڵ尡 ��������� ������ Widget::Impl�� ������ ������ 
			   // �ǵ��� �����

	Widget(Widget&& rhs);//�̵� ���� ����(���� �ϰ� ���� x)
	Widget& operator=(Widget&& rhs);

	Widget(const Widget& rhs);//���� ���� ����
	Widget& operator=(const Widget& rhs);

private:
	struct Impl;
	std::unique_ptr<Impl> pImpl;
};

//Widget.cpp
#include "widget.h"
#include "gadget.h"
#include<string>
#include<vector>

struct Widget::Impl
{
	std::string name;
	std::vector<double> dat;
	Gadget g1, g2, g3;
};

Widget::Widget()
	:pImpl(std::make_unique<Impl>()) //����Ʈ �����͸� ����ϹǷ� �Ҹ��ڰ� ���� �ʿ� ��������
{}

Widget::~Widget() = default;

Widget::Widget(Widget && rhs) = default; //�̵� ���� ����
Widget& Widget::operator=(Widget&& rhs) = default;

Widget::Widget(const Widget& rhs)
	:pImpl(nullptr)
{
	if (rhs.pImpl)pImpl = std::make_unique<Impl>(*rhs.pImpl);
}

Widget& Widget::operator=(const Widget& rhs)
{
	if (!rhs.pImpl)
		pImpl.reset();
	else if (!pImpl)
		pImpl = std::make_unique<Impl>(*rhs.pImpl);
	else
		*pImpl = *rhs.pImpl;

	return *this;
}


//std::unique_ptr VS std::shared_ptr

//unique_ptr : �������� ������ ����Ʈ ������ ������ �Ϻ�
//�� ���� ��������� �ڵ� ����� ����
//�����Ϸ��� �ۼ��� �Ҹ��ڳ� �̵������� ���̴� �������� �����Ͱ� ����Ű�� Ÿ�Ե��� ������ �����̾�� �Ѵ�.

//shared_ptr : �������� ������ ����Ʈ ������ ������ �Ϻΰ� �ƴϴ�.
//�����ڵ尡 Ŀ���� ���������� 
//�����Ͱ� ����Ű�� Ÿ�Ե��� ���� ������ ��������.
