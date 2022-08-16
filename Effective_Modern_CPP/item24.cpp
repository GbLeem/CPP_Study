//ITEM 24 : Distinguish universal references from rvalue references


#include<vector>
class Widget {};

void f(Widget&& param); //rvalue ref

Widget&& var1 = Widget();//rvalue ref

auto&& var2 = var1; //not rvalue ref -> universal ref

template<typename T>
void f(std::vector<T>&& param);//rvalue ref

template<typename T>
void f(T&& param); //not rvalue ref ->universal ref

//T&& �̵��� ������ �� �� �ִ� ��ü�� �����Ѵ�.

//universal ref�� �������� type deduction�� �Ͼ�ٴ� ���̴�.

//����
//�Լ� ���ø��� �Ű����� ������ T&&�̰� T�� deduction�ǰų� / ��ü�� auto&&�� �����Ѵٸ� universal ref�̴�.
//rvalue�� �ʱ�ȭ�Ǵ� universal ref�� rvalue ref�̴�. �ݴ�� lvalue ref