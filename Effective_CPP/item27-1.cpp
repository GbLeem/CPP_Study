#include<iostream>

class Window //�⺻ Ŭ����
{
public:
	virtual void onResize()
	{

	}
};

class SpecialWindow :public Window //�Ļ� Ŭ����
{
public:
	virtual void onResize()
	{
		//static_cast<Window>(*this).onResize(); //����� �ӽ� ��ü�� onResize() �� ȣ���� -> ���ϴ� ����� �ƴϴ�
		Window::onResize();
	}
};