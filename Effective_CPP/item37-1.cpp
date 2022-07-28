class Shape
{
public:
	enum ShapeColor
	{
		Red,
		Green,
		Blue
	};
	
	virtual void draw(ShapeColor color = Red)const = 0;
};

class Rectangle :public Shape
{
public:
	virtual void draw(ShapeColor color = Green)const;// 상속받은 함수의 매개변수 값이 다름(재정의)! => 문제
};

class Circle :public Shape
{
public:
	virtual void draw(ShapeColor color)const;
};

int main()
{
	//동적타입 -> 현재 그 객체가 진짜로 무엇이냐에 따라 결정되는 타입

	Shape* ps;				   //정적타입 = Shape*, 동적타입 = 없음
	Shape* pc = new Circle;    //정적타입 = Shape*, 동적타입 = Circle*
	Shape* pr = new Rectangle; //정적타입 = Shape*, 동적타입 = Rectangle*
	
	ps = pc; //ps의 동적타입은 Circle*

	//가상함수는 동적으로 바인딩
	//매개변수는 정적으로 바인딩

	pc->draw(Shape::Red); //Circle::draw(Shape::Red) 호출
	pr->draw(Shape::Red); //Rectangle::draw(Shape::red) 호출
	pr->draw();           //Rectangle::draw(Shape::red) 호출 -> 기본 매개변수는 Green인데, pr의 정적 타입은 Shape* 이므로 문제!

	//=>item36-2가 해결책
}