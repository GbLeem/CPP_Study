#include<iostream>
#include<string>

class HomeForSale
{
public:
	//...

private:
	//...
	HomeForSale(const HomeForSale&); //private ����� ����Ǿ��ְ� ���ǰ� �Ǿ����� �ʴ�. -> ���� ����!
	HomeForSale& operator =(const HomeForSale&);
};

class Uncopyable // ���� Ŭ����
{
protected:
	Uncopyable();
	~Uncopyable();

private:
	Uncopyable(const Uncopyable&);
	Uncopyable& operator=(const Uncopyable&);
};

class HomeForSale2 : private Uncopyable //���縦 �����ϴ� ���2
{

};