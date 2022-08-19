//protected 선언과 세가지 형태의 상속

class Base
{
private:
	int privateNum;
protected:
	int protectedNum;
public:
	int publicNum;
};

class Derived1 : public Base
{

};


class Derived2 : protected Base
{
	//protected보다 넓은 멤버를(public멤버) protected로 변경시켜서 상속
};

class Derived3 : private Base
{
	//private보다 넓은 멤버를(protected와 public 멤버) private로 변경시켜서 상속
};

int main()
{
	Derived1 dr1;
	dr1.publicNum = 10; //이것만 가능

	Derived2 dr2;	
	//불가능

	Derived3 dr3;
	//불가능
}