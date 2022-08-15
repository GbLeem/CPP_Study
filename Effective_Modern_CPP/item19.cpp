//ITEM 19 : Use std::shared_ptr for shared-ownership resource management

//shared_ptr�� raw �������� ũ���� �ι��̴�.
//���� Ƚ���� ���� �޸𸮸� �ݵ�� �������� �Ҵ��ؾ� �Ѵ�.
//���� Ƚ���� ������ ���Ұ� atomic �����̾�� �Ѵ�.


//unique_ptr�� shared_ptr�� ������ 
#include<iostream>

class Widget {};

auto logginDel = [](Widget* pw)
{
	makeLogEntry(pw);
	delete pw;
};

std::unique_ptr<Widget, decltype(logginDel)> upw(new Widget, logginDel);//������ ������ �Ϻ�

std::shared_ptr<Widget> spw(new Widget, logginDel); // ������ ������ �Ϻ� �ƴ�


//shared_ptr �����ڿ� raw������ �ѱ��� ���� -> make_shared���
//shared_ptr�����ڸ� raw�����ͷ� ������ �� �ۿ� ���� ��� new�� ����� ���� �����ϱ�

//<bad code>
auto pw = new Widget;

std::shared_ptr<Widget> spw1(pw, logginDel);

std::shared_ptr<Widget> spw2(pw, logginDel);

//<better>
std::shared_ptr<Widget> Nspw1(new Widget, logginDel);

std::shared_ptr<Widget> Nspw2(Nspw1);