//		<build process Introduction>


//1. pre process(����� ���ʷ� ����) : #include, #define
//-> translation unit �����

//2. �����Ϸ��� obj���Ϸ� �����. 

//3. ��Ŀ �����Ͽ� obj������ ���ļ� exe ���Ϸ� �����.


//�����Ϸ��� ���� : gcc, clang, visual c++ ...

//�����Ϸ��� ���� �����߿� ������ �߻��� �� �ִ� �Ϳ� ���� 
//warning�� ������ֱ⵵ �Ѵ�.

#include<iostream>
#include<variant>

int main()
{
	std::variant<int, float> i = 0;
	std::cout << "hi" << std::endl;
}

//�پ��� ������ �ɼ� ����..