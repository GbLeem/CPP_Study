//cout, cin, endl의 정체

#include<iostream>

namespace mystd
{
	using namespace std;

	class ostream
	{
	public:
		ostream& operator <<(const char* str)
		{
			printf("%s", str);
			return *this;
		}

		ostream& operator <<(char str)
		{
			printf("%c", str);
			return *this;
		}

		ostream& operator <<(int num)
		{
			printf("%d", num);
			return *this;
		}

		ostream& operator <<(double e)
		{
			printf("%g", e);
			return *this;
		}

		ostream& operator <<(ostream& (*fp)(ostream& ostm))
		{
			return fp(*this);
		}
	};

	ostream& endl(ostream& ostm)
	{
		ostm << '\n';
		fflush(stdout);
		return ostm;
	}

	ostream cout;
}

int main()
{
	using mystd::cout;
	using mystd::endl;

	cout << "Simple String";
	cout << endl;
	cout << 3.14;
	cout << endl;
	cout << 123;
	endl(cout);

	cout << "Simple string" << 123 << endl; //<<연산자의 반환타입이 cout 이어야 하므로 
											//반환 타입을 void 에서 ostream&로 바꿔서 구현
	return 0;
}
