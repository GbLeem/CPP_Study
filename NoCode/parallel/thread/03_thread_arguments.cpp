#include<iostream>
#include<thread>
#include<string>

//void fn(int a, std::string s)// copy 연산 하고있다. -> &로 바꿔주기
void fn(int a, std::string &s) //reference의 경우 life cycle을 주의해줘야 한다.
{
	std::cout << a << s << std::endl;
}

void fn2(int& a)
{
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << a << std::endl;
}
void caller()
{
	int num = 100;
	std::string str= "nice";
	fn(num, str);
}

void threadCaller(std::thread& t)
{
	int num = 1000;
	t = std::thread(fn2, std::ref(num)); 
	t.join(); //thread의 join은 같은 scope내에서 해주기
}
//int main()
//{
//	int num = 100;
//	std::string str = "good";
//	std::thread t1(fn, num, std::ref(str)); //reference로 만들어주기
//	t1.join();
//}

int main()
{
	std::thread t1;
	threadCaller(t1);
	//t1.join();
}