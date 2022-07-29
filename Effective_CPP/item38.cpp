//is-a ����
//template<typename T>
//class Set : public std::list<T> // list�� ��� Ư¡�� Set���� ���� �ȴ�. -> ���ϴ� ��� x
//{
	//...
//};

//is-implemented-in-terms-of ����
#include<iostream>
#include<list>

template<class T>
class Set
{
public:
	bool member(const T& item) const;
	void insert(const T& item);
	void remove(const T& item);
	std::size_t size() const;

private:
	std::list<T> rep;
};

template<typename T>
bool Set<T>::member(const T& item) const
{
	return std::find(rep.begin(), rep.end(), item != rep.end());
}

template<typename T>
void Set<T>::insert(const T& item)
{
	if (!member(item))rep.push_back(item);
}

template<typename T>
void Set<T>::remove(const T& item)
{
	typename std::list<T>::iterator iter = std::find(rep.begin(), rep.end(), item);

	if (iter != rep.end())
		rep.erase(iter);
}

template<typename T>
std::size_t Set<T>::size() const
{
	return rep.size();
}

