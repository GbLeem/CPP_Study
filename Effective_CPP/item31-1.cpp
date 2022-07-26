#include<string>
#include<memory>

class PersonImpl;
class Date;
class Address;

class Person //핸들 클래스
{
public:
	Person(const std::string& name, const Date& birthday, const Address& addr);
	std::string name() const;
	std::string birthDate() const;
	std::string address() const;
	//...

private:
	std::tr1::shared_ptr<PersonImpl> pImpl; 
};

Person::Person(const std::string& name, const Date& birthday, const Address& addr)
	:pImpl(new PersonImpl(name,birthday,addr))
{

}

std::string Person::name() const
{
	return pImpl->name();
}