
//non-virtual interface 사용!

class Shape
{
public:
	enum ShapeColor
	{
		Red,
		Green,
		Blue
	};

	void draw(ShapeColor Color = Red) const //비가상 함수
	{
		doDraw(Color); //가상함수 호출
	}
private:
	virtual void doDraw(ShapeColor color) const; //private 가상함수
};

class Rectangle :public Shape
{
public:
	virtual void doDraw(ShapeColor color)const; //매개변수 없이 사용이 가능하다. 37-1의 문제 해결
};

//상속받은 매개변수 값은 재정의 하면 안된다!