//¹®Á¦ 1.
#include<iostream>
#include<cstring>
using namespace std;

class Gun
{
private:
	int bullet;
public:
	Gun(int bnum)
		:bullet(bnum)
	{}
	void Shot()
	{
		cout << "bang!" << endl;
		bullet--;
	}
};

class Police
{
private:
	int handcuffs;
	Gun* pistol;
public:
	Police(int bnum, int bcuff)
		:handcuffs(bcuff)
	{
		if (bnum > 0)
			pistol = new Gun(bnum);
		else
			pistol = nullptr;
	}
	void PutHandcuff()
	{
		cout << "Snap!" << endl;
		handcuffs--;
	}
	void Shot()
	{
		if (pistol == nullptr)
			cout << "NO GUN" << endl;
		else
			pistol->Shot();
	}
	~Police()
	{
		if (pistol != nullptr)
			delete pistol;
	}
	Police& operator=(const Police& ref)
	{
		if(pistol!=nullptr)
			delete pistol;
		if (ref.pistol != nullptr)
			pistol = new Gun(*(ref.pistol));//!!
		else
			pistol = nullptr;

		handcuffs = ref.handcuffs;
		return *this;
	}
};

int main()
{
	Police p1(1, 1);
	Police p2(10, 20);
	p2 = p1;

	p2.Shot();
	p2.Shot();
	p2.Shot();

}
