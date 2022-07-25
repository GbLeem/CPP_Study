#include<iostream>

class Point
{
public:
	Point(int x, int y);

	void setX(int newVal);
	void setY(int newVal);
};

struct RectData
{
	Point ulhc;
	Point lrhc;
};

class Rectangle
{
public:
	const Point& upperleft() //const�� ���ٸ� ��ü�� ĸ��ȭ�� �����ϴ� �ڵ尡 �ȴ�.
	{
		return pData->ulhc;
	}

	const Point& lowerRight()
	{
		return pData->lrhc;
	}

private:
	std::tr1::shared_ptr<RectData>pData;
};

//dangling handle
class GUIObject
{
};

Rectangle boundingBox(const GUIObject& obj);

int main()
{
	GUIObject* pgo;
	const Point* pUpperLeft = &(boundingBox(*pgo).upperleft());
	//boundingBox ȣ��� �ӽ� Rectangle ��ü ����(temp��� ����)
	//->upperleft�� ���� temp�� Point��ü�� �����ڰ� ����
	//->�ش� ������ �����鼭 temp�� �Ҹ�
	//->temp�� Point ��ü�鵵 ����� 
}