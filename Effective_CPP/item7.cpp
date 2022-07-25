//팩토리 함수 : 새로 생성된 파생 클래스 객체에 대한 기본 클래스 포인터를 반환하는 함수
//-> 구체적으로 어떤 객체를 생성해야할지 알 수 없는 경우
//-> 하위 클래스가 객체를 생성하기를 원할 때
//-> 하위 클래스들에게 개별 객체의 생성 책임을 분산시켜 객체의 종류별로 객체 생성과 관련된 부분을 국지화 시킬때

#include<iostream>
#include<string>
#include<map>
using namespace std;

class Monster
{
public:
	virtual void showName() = 0;
};

class Goblin :public Monster
{
	void showName()
	{
		cout << "고블린 생성" << endl;
	}
};

class Ghost :public Monster
{
	void showName()
	{
		cout << "유령 생성" << endl;
	}
};

class MonsterMgr //객체를 생성하기 위한 인터페이스만 제공한다.
{
public:
	void newMonster(const string& name)
	{
		Monster* pMon = createMonster();
		ObjPool_[name] = pMon;
		pMon->showName();
	}
	virtual Monster* createMonster() = 0; //팩토리 함수

private:
	map<string, Monster*> ObjPool_;
};

class GoblinMgr :public MonsterMgr
{
	Monster* createMonster()
	{
		return new Goblin;
	}
};

class GhostMgr :public MonsterMgr
{
	Monster* createMonster()
	{
		return new Ghost;
	}
};
