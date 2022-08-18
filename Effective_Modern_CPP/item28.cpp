//ITEM 28 : Understand reference collapsing

class Widget {};

template<typename T>
void func(T&& param);

int main()
{
	Widget widgetFactory(); //rval�� return �ϴ� �Լ�
	Widget w;

	func(w); //func�� lval�� ȣ�� T�� Widget&�� deduce
	func(widgetFactory()); //func�� rval�� ȣ�� T�� Widget���� deduce
}

//reference collapse
//������ ���� ������ ���(���ø� �ν��Ͻ�ȭ)
//�� ������ ��� �ϳ��� lval ������� ����� lval ����, �������� rval ����

//reference collapse ���
//1. ���ø��� �ν��Ͻ�ȭ
//2. auto ������ deduce
auto&& w1 = w; //w1 �� lval�� �ʱ�ȭ
Widget& && w1 = w; //Widget& �������� deduce -> ������ ����
Widget& w1 = w; //refernce collapse

auto&& w2 = widgetFactory(); //w2 rval�� �ʱ�ȭ
Widget&& w2 = widgetFactory(); //Widget �������� deduce


//3. typedef�� alias ����
//4. decltype���