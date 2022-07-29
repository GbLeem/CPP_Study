class Person
{

};

class Student :private Person
{

};

void eat(const Person& p);
void study(const Student& s);

int main()
{
	Person p;
	Student s;

	eat(p);
	//eat(s); 에러-> private 상속 :  파생 클래스 객체를 기본 클래스 객체로 변환하지 않음
								 // 기본 클래스로부터 물려받은 멤버는 파생클래스에서 private 멤버가 된다
	//-> private 상속의 의미는 is-implemented-in-terms-of 이다.
	//private 상속은 비공개 멤버에 접근 / 가상 함수를 재정의 할때 private 상속 사용하고 나머지는 is-implemented-in-terms-of 사용
}