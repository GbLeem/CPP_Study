//Item 9 : Prefer alias declarations to typedefs
#include <iostream>
#include <string>
#include <unordered_map>

//typedef std::unique_ptr<std::unordered_map<std::string, std::string>> UPtrMapSS;  c++98´À³¦
using UPtrMapSS = std::unique_ptr<std::unordered_map<std::string, std::string>>;

typedef void (*FP)(int, const std::string&);//typedef
using FP = void(*)(int, const std::string&); //alias

//----------------------------------------------
//alias template
template<typename T>
using MyAllocList = std::list<T, MyAlloc<T>>;

template<typename T>
class Widget 
{
private:
	MyAllocList<T> list;
};

//----------------------------------------------
template<class T>
using remove_const_t = typename remove_const<T>::type;
