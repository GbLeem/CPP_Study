//���ڿ� ó�� Ŭ������ ����

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