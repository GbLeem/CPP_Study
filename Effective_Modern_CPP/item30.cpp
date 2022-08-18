//ITEM 30 : Familiarize yourself with perfect forwarding failure cases

//�Ϻ� ���� 
//1. �Լ��� �ڽ��� �μ����� �ٸ� �Լ��� �����ϴ� ��
//2. ���޹޴� �Լ��� �����ϴ� �Լ��� �޾Ҵ� �Ͱ� ������ ��ü���� �ް� �ϴ� ��
// ��ü���� �ֿ� Ư¡(����, lval or rval, const or volatile����)�� ��� �����ϴ� ��

#include<iostream>

template<typename T>
void fwd(T&& param)
{
	f(std::forward<T>(param));
}

template<typename... Ts>
void fwd(Ts&&... param) //���� �μ� ���ø� -> ex) emplace �Լ� ���� / make_unique, make_shared ...
{
	f(std::forward<T>(params)...);
}

f(/**/);
fwd(/**/); //�� ȣ���� �ϴ� ���� ���ƾ� �Ϻ������� �� ���̴�.

//�Ϻ����� ���� ���
//1. �߰�ȣ �ʱ�ġ
//2. �� �����͸� ���ϴ� 0 �� NULL
//3. ���� �� ���� static, const, constexpr ���
//4. overload�� �Լ� �̸��� ���ø� �̸�
//5. bitfield