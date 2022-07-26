#include<string>
#include<iostream>
class Date;
class Address;

class Person // 인터페이스 클래스
{
public:
	virtual ~Person();
	
	virtual std::string name() const = 0;
	virtual std::string birthDate() const = 0;
	virtual std::string address() const = 0;
	//...

	static std::tr1::shared_ptr<Person> create(const std::string& name, const Date& birthday, const Address& addr);
};

class RealPerson :public Person
{
public:
	RealPerson(const std::string& name, const Date& birthday, const Address& addr)
		: name(name)
		, date(birthday)
		, address(addr)
	{

	}

	virtual ~RealPerson(){}

	std::string name() const;
	std::string birthDate() const;
	std::string address() const;

private:
	std::string name;
	Date date;
	Address address;

};

std::tr1::shared_ptr<Person> Person::create(const std::string& name, const Date& birthday, const Address& addr)
{
	return std::tr1::shared_ptr<Person>(new RealPerson(name, birthday, addr));
}

//사용자
int main()
{
	std::string name;
	Date date;
	Address address;

	std::tr1::shared_ptr<Person> pp(Person::create(name, date, address));

	std::cout << pp->name() << pp->birthDate() << pp->address() << std::endl;
}