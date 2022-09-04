//문자열 처리 클래스의 정의

#include<iostream>
#include<cstring>
using namespace std;

class String
{
public:
	String();
	String(const char* s);
	String(const String& ref);
	~String();
	String& operator=(const String& ref);
	String& operator+=(const String& ref);
	bool operator==(const String& ref);
	String operator+(const String & ref);
	
	friend ostream& operator<<(ostream& os, const String& s);
	friend istream& operator>>(istream& is, String& s);

private:
	int len;
	char* str;
};

String::String()
{
	len = 0;
	str = nullptr;
}

String::String(const char* s)
{
	len = strlen(s) + 1;
	str = new char[len];
	strcpy_s(str, len, s);
}

String::~String()
{
	if (str != nullptr)
		delete[]str;
}

String::String(const String& ref)
{
	len = ref.len;
	str = new char[len];
	strcpy_s(str, len, ref.str);
}

String& String::operator=(const String& ref)
{
	if (str != nullptr)
		delete[]str;
	len = ref.len;
	str = new char[len];
	strcpy_s(str, len, ref.str);
	return *this;
}

String& String::operator+=(const String& ref)
{
	len += ref.len - 1;
	char* temp = new char[len];
	strcpy_s(temp, len, str);
	strcat(temp, ref.str);

	if (str != nullptr)
		delete[]str;

	str = temp;
	return *this;
}

bool String::operator==(const String& ref)
{
	return strcmp(str, ref.str) ? false : true;
}

String String::operator+(const String& ref)
{
	len += ref.len - 1;
	char* temp = new char[len];
	strcpy_s(temp, len,str);
	strcat(temp, ref.str);

	String res{ temp };
	delete[]temp;
	return res;
}

ostream& operator<<(ostream& os, const String& s)
{
	os << s.str;
	return os;
}

istream& operator>>(istream& is, String& s)
{
	char str[100];
	is >> str;
	s = String(str);
	return is;
}