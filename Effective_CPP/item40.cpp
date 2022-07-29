#include<string>

class IPerson //interface
{
public:
	virtual ~IPerson();

	virtual std::string name() const = 0;
	virtual std::string birthDate() const = 0;
};

class DatabaseID
{

};

class PersonInfo //IPerson interface�� �����ϴµ� �ʿ��� �Լ��� ����
{
public:
	explicit PersonInfo(DatabaseID pid);
	virtual ~PersonInfo();

	virtual const char* theName() const;
	virtual const char* theBirthDate() const;

	virtual const char* valueDelimOpen() const;
	virtual const char* valueDelimClose() const;
};

class CPerson :public IPerson, private PersonInfo //IPerson�� interface ������, PersonInfo�� �����Լ��� ������ �Ϸ���
{
public:
	explicit CPerson(DatabaseID pid)
		:PersonInfo(pid)
	{

	}
	virtual std::string name() const
	{
		return PersonInfo::theName();
	}
	virtual std::string birthDate() const
	{
		return PersonInfo::theBirthDate();
	}

private:
	const char* valueDelimOpen() const
	{
		return "";
	}
	const char* valueDelimClose() const
	{
		return "";
	}
};