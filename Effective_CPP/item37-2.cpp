
//non-virtual interface ���!

class Shape
{
public:
	enum ShapeColor
	{
		Red,
		Green,
		Blue
	};

	void draw(ShapeColor Color = Red) const //�񰡻� �Լ�
	{
		doDraw(Color); //�����Լ� ȣ��
	}
private:
	virtual void doDraw(ShapeColor color) const; //private �����Լ�
};

class Rectangle :public Shape
{
public:
	virtual void doDraw(ShapeColor color)const; //�Ű����� ���� ����� �����ϴ�. 37-1�� ���� �ذ�
};

//��ӹ��� �Ű����� ���� ������ �ϸ� �ȵȴ�!