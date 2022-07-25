#include<iostream>
#include<vector>

class Window
{
public:
	virtual void blink()
	{
		//�ƹ� ���� ���ϱ�
	}
};

class SpecialWindow :public Window
{
public:
	virtual void blink()
	{
		//... blink�Լ��� ����
	}
};

//������ ���� -> dynamic_cast�� ���ɻ� ���ϰ� ����
//typedef std::vector<std::tr1::shared_ptr<Window>>VPW;
//VPW winPtrs;
//
//int main()
//{
//	for (VPW::iterator iter = winPtrs.begin(); iter != winPtrs.end(); ++iter)
//	{
//		if (SpecialWindow* psw = dynamic_cast<SpecialWindow*>(iter->get()))
//			psw->blink();
//
//	}
//}

typedef std::vector<std::tr1::shared_ptr<Window>>VPW;
VPW winPtrs; //Window���� �Ļ��� ��� Ÿ���� ��ü(�� ���� ������)�� ������ �����̳�

int main()
{
	for (VPW::iterator iter = winPtrs.begin(); iter != winPtrs.end(); ++iter)
	{
		(*iter)->blink();
	}
}
