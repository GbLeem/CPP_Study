//const�� ������ �̾߱�

//const�� ���� ��ü�� ��� ��ü�� const ��� �Լ��� ȣ�� �����ϴ�.
#include<iostream>
using namespace std;

class Widget
{
private:
	int num;
public:
	Widget(int n)
		:num(n)
	{}
	Widget& AddNum(int n)
	{
		num += n;
		return *this;
	}
	void showData() const
	{
		cout << "num : " << num << endl;
	}
};

int main()
{
	const Widget obj(10);
	//obj.AddNum(20); �Ұ���
	obj.showData(); //����
	return 0;
}

//const ���η� �����ε� ����