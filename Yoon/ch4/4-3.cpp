//생성자와 소멸자

//객체가 되기 위해서는 반드시 하나의 생성자가 필요하다.
//생성자를 만들지 않으면 디폴트 생성자가 만들어진다.

//private로 선언된 생성자로도 객체 생성이 가능하다.

//문제 1.
//#include<iostream>
//using namespace std;
//
//class Circle
//{
//private:
//	int centerX, centerY;
//	int radius;
//
//public:
//	Circle(int x, int y, int r)
//		:centerX(x)
//		,centerY(y)
//		,radius(r)
//	{
//	}
//	//...
//};
//
//class Ring
//{
//private:
//	Circle c1, c2;
//
//public:
//	Ring(int x1, int y1, int r1, int x2, int y2, int r2)
//		:c1(x1,y1,r1)
//		,c2(x2,y2,r2)
//	{
//	}
//	//...
//};


//문제 2.
#include<iostream>
using namespace std;

enum COMP_POS
{ 
	CLERK,
	SENIOR,
	ASSIST,
	MANAGER
};

class NameCard
{
private:
	const char* name;
	const char* company;
	const char* phone;
	int rank;

public:
	NameCard(const char* name, const char* company, const char* phone, COMP_POS pos)
		:name(name)
		,company(company)
		,phone(phone)
		,rank(pos)
	{
	}
	
	const char* CheckPos(int rank) const
	{
		switch (rank)
		{
		case 0:
			return "사원";
		case 1:
			return "주임";
		case 2:
			return "대리";
		case 3:
			return "과장";
		default:
			break;
		}
	}

	void ShowNameCardInfo() const
	{
		cout << "이름 : " << name << endl;
		cout << "회사 : " << company << endl;
		cout << "전화번호 : " << phone << endl;
		cout << "직급 : " << CheckPos(rank) << endl;
		cout << endl;
	}

};

int main()
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);

	manClerk.ShowNameCardInfo();
	manSenior.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();
	
	return 0;
}