//item 7 : Distinguish between () and {} when creating objects

class Widget {};

Widget w1; // �⺻ ������ ȣ��
Widget w2 = w1; //���� ������ ȣ��
w1 = w2; //assignment

//C++11 �� uniform initialization
//�߰�ȣ�� ���
#include<vector>
std::vector<int> v{ 1,3,5 }; //uniform(�߰�ȣ) �ʱ�ȭ

//�ʱ�ȭ ����1
//non-static member
class Widget
{
private:
	int x{ 0 }; //ok
	int y = 0;  //ok
	int z(0);   //no!
};

//�ʱ�ȭ ����2
//������ �� ���� ��ü
std::atominc<int> ai1{ 0 }; //ok
std::atominc<int> ai2(0);   //ok
std::atominc<int> ai3 = 0;  //no!

//�߰�ȣ �ʱ�ȭ�� narrowing conversion ����
double x, y, z;
int sum1{ x + y + z };//����

//�߰�ȣ �ʱ�ȭ�� auto�� ����Ҷ� ������ ������ �����.
class Widget
{
public:
	Widget(int i, bool b);
	Widget(int i, double d);
	Widget(std::initializer_list<long double>il); //�߰�ȣ �ʱ�ȭ�� initializer_list�� �޴� �����ڿ� �����Ϸ��Ѵ�.
};
int main()
{
	Widget w1(10, true);  //ù��° ������
	Widget w2{ 10,true }; //ù��° ������
	Widget w3(10, 5.0);   //�ι�° ������
	Widget w4{ 10,5.0 };  //�ι�° ������

	//initializer_list �߰��� ��
	Widget w1(10, true);  //ù��° ������
	Widget w2{ 10,true }; //����° ������ 10, true�� long double �� ����
	Widget w3(10, 5.0);   //�ι�° ������
	Widget w4{ 10,5.0 };  //����° ������
}

//vector�� ���..
std::vector<int> v1(10, 20);//�� initializer_list ������ �̿�, ���� 20�� ���� 10��¥�� ���� ����
std::vector<int> v2{ 10, 20 }; //initializer_list ������ �̿�, ���� 10, 20�� �ΰ��� ���� ����

//*�ߺ����� : overload