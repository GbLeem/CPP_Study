//ITEM 41

#include<string>
#include<vector>
class Widget //case 1 : lval�� rval�� ���� �Լ� overload �����
{
public:
	void addName(const std::string& newName)
	{
		names.push_back(newName);
	}
	void addName(const std::string&& newName)
	{
		names.push_back(std::move(newName));
	}

private:
	std::vector<std::string> names;
};


class Widget //case 2 : universal reference
{
public:
	template<typename T>
	void addName(T&& newName)
	{
		names.push_back(std::forward<T> newName);
	}

private:
	std::vector<std::string> names;
};


class Widget //case 3 : ������ ����
{
public:
	void addName(std::string newName)
	{
		names.push_back(std::move(newName));
	}

private:
	std::vector<std::string> names;
};

//�̵��� �����ϰ� �׻� ����Ǵ� ���� ���� �Ű������� ���ؼ��� �� ������ ����϶�

