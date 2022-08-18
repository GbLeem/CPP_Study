//ITEM 26 : Avoid overloading on universal references

#include<set>
#include<string>
#include<chrono>

//최적화 시키기
std::multiset<std::string> names; //전역 자료구조

template<typename T>
void logAndAdd(T&& name)
{
	auto now = std::chrono::system_clock::now(); //현재 시간 기록

	log(now, "logAndAdd"); //로그에 기록하기

	names.emplace(std::forward<T>(name)); //이름을 전역 자료구조에 추가하기
}

int main()
{
	std::string petName("Darla");

	logAndAdd(petName); // lval 복사
	logAndAdd(std::string("Persephone")); // rval move
	logAndAdd("Patty Dog"); //multiset 안에 string 객체를 생성
}

//완벽 전달 생성자
std::string nameFromIdx(int idx);

class Person
{
public:
	//template<typename T>
	//explicit Person(T&& n) //완벽 전달 생성자
	//	:name(std::forward<T>(n))

	explicit Person(Person& n) //완벽전달 템플릿에서 인스턴스화된다.
		:name(std::forward<Person&>(n)) 
	{
	}

	explicit Person(int idx) //int값을 받는 생성자
		:name(nameFromIdx(idx))
	{
	}
	
	Person(const Person& rhs);
	Person(Person&& rhs);

private:
	std::string name;
};

class SpecialPerson :public Person
{
public:
	SpecialPerson(const SpecialPerson& rhs) //복사 생성자
		:Person(rhs)						//base 클래스의 완벽 전달 생성자 호출
	{
	}

	SpecialPerson(SpecialPerson&& rhs) //이동 생성자
		:Person(std::move(rhs))		   //base 클래스의 완벽 전달 생성자 호출
	{
	}
};