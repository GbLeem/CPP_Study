//item1 : understand template type deduction

//case 1 : paramtype is reference or pointer, but not a universal reference
template<typename T>
void f(T& param);

int main()
{
	int x = 27;
	const int cx = x;
	const int& rx = x;

	f(x);  //T is int, param's type is int&
	f(cx); //T is const int, param's type is const int&
	f(rx); //T is const int&, param's type is const int&
}

//case 2 : paramtype is a universal reference
template<typename T>
void f(T&& param);

int main()
{
	int x = 27;
	const int cx = x;
	const int& rx = x;

	f(x);  //x is lvalue, T is int&, param's type is int&
	f(cx); //cx is lvalue, T is const int&, param's type is const int&
	f(rx); //rx is lvalue, T is const int&, param's type is const int&
	f(27); //27 is lvalue, T is int, param's type is int&&
}

//case3 : paramtype is neither a pointer nor a reference
template<typename T>
void f(T param);

int main()
{
	int x = 27;
	const int cx = x;
	const int& rx = x;

	f(x);  //T and param's type is int
	f(cx); //T and param's type is int
	f(rx); //T and param's type is int
}

//array
const char name[] = "Leem";
const char* namePtr = name;

template<typename T>
//void f(T param);
void f(T& param);

int main()
{
	//f(name);//name is array but T dedeuced as const char*
	f(name);//T is deduced as const char[13]
}