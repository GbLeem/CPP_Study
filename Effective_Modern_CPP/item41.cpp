//ITEM 41

#include<string>
#include<vector>
class Widget //case 1 : lval과 rval에 대한 함수 overload 만들기
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


class Widget //case 3 : 값으로 전달
{
public:
	void addName(std::string newName)
	{
		names.push_back(std::move(newName));
	}

private:
	std::vector<std::string> names;
};

//이동이 저렴하고 항상 복사되는 복사 가능 매개변수에 대해서는 값 전달을 고려하라

