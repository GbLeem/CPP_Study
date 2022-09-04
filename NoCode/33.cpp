//						<Pure Virtual Function>


//pure virtal function : = 0 ���� ǥ�õ� ��
//abstract class : pure virtal function�� �ϳ��� �ִ� Ŭ����

#include<array>
#include<iostream>

class Animal //abstract class --> object ���� �Ұ���!!
{
public:
	virtual void speak() = 0; //pure virtal function
	virtual ~Animal() = default;
private:
	double height;
};

class Cat : public Animal
{
public:
	void speak() override //pure virtal function�� ������ override �ؾ��Ѵ�!
	{
		std::cout << "Cat" << std::endl;
	}
private:
	double weight;
};

int main()
{
	//Animal abs; ����
	Cat kitty;

	return 0;
}

//-----------------------------------------


class Monster				//**interface class** : ���ο� implementation x, member variable x
{
public:
	virtual int attack() = 0;
	void walk()
	{
		///
	}
	virtual ~Monster() = default;
protected:
	int attackDmg;
	float moveSpeed;
};

class Skeleton :public Monster
{
public:
	int attack() override
	{
		//������ ���� ���� Ư���� �ۼ�..
	}
	Skeleton()
	{
		attackDmg = 10;
		moveSpeed = 20.5;
	}
};
//���� �ڵ������ ok.. BUT �Ʒ�ó�� ���ο� Ŭ������ �߰��ȴٸ�..

class Dragon : public Monster //���� Monster���� walk�� �����ξ��µ�... ���ƴٴϴ� ���� ���͹����� BaseŬ������ ������ �ؾ���
{
	//�ٸ� ���� �۾����� �߰��ȴ�.
	//�ʿ���� �Լ���, �����鵵 ������ �ȴ�.
	//-> ���� ���� ���� ����
	//�ذ� : ���ο� implementation x, member variable x
};
