#include<iostream>
#include<string>

class HomeForSale
{
public:
	//...

private:
	//...
	HomeForSale(const HomeForSale&); //private 멤버로 선언되어있고 정의가 되어있지 않다. -> 복사 방지!
	HomeForSale& operator =(const HomeForSale&);
};

class Uncopyable // 공백 클래스
{
protected:
	Uncopyable();
	~Uncopyable();

private:
	Uncopyable(const Uncopyable&);
	Uncopyable& operator=(const Uncopyable&);
};

class HomeForSale2 : private Uncopyable //복사를 방지하는 방법2
{

};