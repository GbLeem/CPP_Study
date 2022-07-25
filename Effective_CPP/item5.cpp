#include<iostream>
#include<string>

template<typename T>
class NameObject
{
public:
	NameObject(const char* name, const T& value)
	{
		namevalue = name;
		objectValue = value;
	}
	NameObject(const std::string name, const T& value)
	{
		namevalue = name;
		objectValue = value;
	}


public:
	std::string namevalue;
	T objectValue;
};

int main()
{
	NameObject<int> no1("Smallest Prime number", 2);
	NameObject<int> no2(no1); //복사 생성자 호출 -> 참조자를 데이터 맴버로 갖고 있지 않은 클래스의 경우만 자동 생성 후 사용
											  //-> 상수객체가 데이터 멤버인 경우도 마찬가지(상수 멤버의 수정은 불가능)
											  //=> 위의 경우에는 직접 복사 연산자를 정의해주어야 한다.
	
	std::cout << no2.namevalue << ' ' << no2.objectValue;

	
}