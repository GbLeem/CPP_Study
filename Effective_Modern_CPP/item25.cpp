//ITEM 25 : Use std::move on rvalue references, std::forward on universal references


//rvalue ref�� �ٸ� �Լ��� �����Ҷ����� std::move�� ����ؾ� �Ѵ�.
//universal ref �� �ٸ� �Լ��� ���� �Ҷ����� std::forward�� ����Ͼ� �Ѵ�.(���Ǻ�)

//return by value �Լ��� rvalue reference�� universal reference�� return �Ҷ� std::move�� std::forward ����
#include<iostream>

Matrix operator+(Matrix&& lhs, const Matrix& rhs) //return by value
{
	lhs += rhs;
	return std::move(lhs); //lhs�� return ������ �̵�
}
//ȿ�� ���


//��ȯ�� ����ȭ�� ����� �� �� �ִ� local ��ü���� ���� std::move�� std::forward �������� �ʴ´�.
Widget makeWidget(void)
{
	Widget w;
	//...
	return w;
}

Widget makeWidget(void)
{
	Widget w;
	//...
	return std::move(w); //���� �ڵ带 ����ȭ �Ѱ� x
}

Widget makeWidget(Widget w)
{
	//...
	return std::move(w); //local ��ü�� ������ ��ȯ�ϴ� ���..
						 //������ ����ȭ x
}