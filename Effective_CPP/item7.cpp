//���丮 �Լ� : ���� ������ �Ļ� Ŭ���� ��ü�� ���� �⺻ Ŭ���� �����͸� ��ȯ�ϴ� �Լ�
//-> ��ü������ � ��ü�� �����ؾ����� �� �� ���� ���
//-> ���� Ŭ������ ��ü�� �����ϱ⸦ ���� ��
//-> ���� Ŭ�����鿡�� ���� ��ü�� ���� å���� �л���� ��ü�� �������� ��ü ������ ���õ� �κ��� ����ȭ ��ų��

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
		cout << "��� ����" << endl;
	}
};

class Ghost :public Monster
{
	void showName()
	{
		cout << "���� ����" << endl;
	}
};

class MonsterMgr //��ü�� �����ϱ� ���� �������̽��� �����Ѵ�.
{
public:
	void newMonster(const string& name)
	{
		Monster* pMon = createMonster();
		ObjPool_[name] = pMon;
		pMon->showName();
	}
	virtual Monster* createMonster() = 0; //���丮 �Լ�

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
