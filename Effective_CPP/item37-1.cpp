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
	virtual void draw(ShapeColor color = Green)const;// ��ӹ��� �Լ��� �Ű����� ���� �ٸ�(������)! => ����
};

class Circle :public Shape
{
public:
	virtual void draw(ShapeColor color)const;
};

int main()
{
	//����Ÿ�� -> ���� �� ��ü�� ��¥�� �����̳Ŀ� ���� �����Ǵ� Ÿ��

	Shape* ps;				   //����Ÿ�� = Shape*, ����Ÿ�� = ����
	Shape* pc = new Circle;    //����Ÿ�� = Shape*, ����Ÿ�� = Circle*
	Shape* pr = new Rectangle; //����Ÿ�� = Shape*, ����Ÿ�� = Rectangle*
	
	ps = pc; //ps�� ����Ÿ���� Circle*

	//�����Լ��� �������� ���ε�
	//�Ű������� �������� ���ε�

	pc->draw(Shape::Red); //Circle::draw(Shape::Red) ȣ��
	pr->draw(Shape::Red); //Rectangle::draw(Shape::red) ȣ��
	pr->draw();           //Rectangle::draw(Shape::red) ȣ�� -> �⺻ �Ű������� Green�ε�, pr�� ���� Ÿ���� Shape* �̹Ƿ� ����!

	//=>item36-2�� �ذ�å
}