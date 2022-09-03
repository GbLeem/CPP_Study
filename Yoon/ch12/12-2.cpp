//문자열 처리 클래스의 정의

class String
{
public:
	String(const char* str);
	~String();
	String(const String& ref);
	String& operator=(const String& ref);
	String& operator+=(const String& ref);
	bool operator==(const String& ref);
	String operator+(const String & ref);
private:
	const char* str;
};