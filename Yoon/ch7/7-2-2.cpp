//문제 1.

#include<iostream>
using namespace std;

//class Car
//{
//private:
//	int gasolineGauge;
//public:
//	Car(int n)
//		:gasolineGauge(n)
//	{
//		cout << "Car()" << endl;
//	}
//	int GetGasGauge()
//	{
//		return gasolineGauge;
//	}
//};
//
//class HybridCar :public Car
//{
//private:
//	int electricGauge;
//public:
//	HybridCar(int n1,int n2)
//		:Car(n1)
//		,electricGauge(n2)
//	{
//		cout << "Hybrid()" << endl;
//	}
//
//	int GetElecGauge()
//	{
//		return electricGauge;
//	}
//};
//
//class HybridWaterCar :public HybridCar
//{
//private:
//	int waterGauge;
//public:
//	HybridWaterCar(int n1,int n2,int n3)
//		:HybridCar(n1,n2)
//		,waterGauge(n3)
//	{
//
//	}
//	void showCurrentGauge()
//	{
//		cout << "gasoline : " << GetGasGauge() << endl;
//		cout << "electric : " << GetElecGauge() << endl;
//		cout << "water : " << waterGauge << endl;
//	}
//};
//
//int main()
//{
//	Car c(100);
//	HybridCar h(200, 300);
//	HybridWaterCar hw(400, 500, 600);
//	hw.showCurrentGauge();
//	return 0;
//}


//문제 2.
class MyFriendInfo
{
private:
	char* name;
	int age;
public:
	MyFriendInfo(const char* n, int a)
		:age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	~MyFriendInfo()
	{
		delete []name;
	}
	void showMyFriendInfo() const
	{
		cout << "name : " << name << endl;
		cout << "age : " << age << endl;
	}
};

class MyFriendDetailInfo :public MyFriendInfo
{
private:
	char* addr;
	char* phone;
public:
	MyFriendDetailInfo(const char* n, int ag, const char* a, const char* p)
		:MyFriendInfo(n, ag)
	{
		addr = new char[strlen(a) + 1];
		phone = new char[strlen(p) + 1];
		strcpy_s(addr, strlen(a) + 1, a);
		strcpy_s(phone, strlen(p) + 1, p);
	}
	~MyFriendDetailInfo()
	{
		delete[]addr;
		delete[]phone;
	}
	void showMyFriendDetailInfo() const
	{
		showMyFriendInfo();
		cout << "address : " << addr << endl;
		cout << "phone : " << phone << endl;
	}
};

int main()
{
	MyFriendDetailInfo mf1("leem", 25, "seoul", "010-8888-9999");
	MyFriendDetailInfo mf2("kim", 35, "suwon", "010-1111-2222");
	mf1.showMyFriendDetailInfo();
	mf2.showMyFriendDetailInfo();
	return 0;

}