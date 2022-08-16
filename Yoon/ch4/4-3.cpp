//�����ڿ� �Ҹ���

//��ü�� �Ǳ� ���ؼ��� �ݵ�� �ϳ��� �����ڰ� �ʿ��ϴ�.
//�����ڸ� ������ ������ ����Ʈ �����ڰ� ���������.

//private�� ����� �����ڷε� ��ü ������ �����ϴ�.

//���� 1.
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


//���� 2.
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
			return "���";
		case 1:
			return "����";
		case 2:
			return "�븮";
		case 3:
			return "����";
		default:
			break;
		}
	}

	void ShowNameCardInfo() const
	{
		cout << "�̸� : " << name << endl;
		cout << "ȸ�� : " << company << endl;
		cout << "��ȭ��ȣ : " << phone << endl;
		cout << "���� : " << CheckPos(rank) << endl;
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