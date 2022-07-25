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
	const Point& upperleft() //const가 없다면 객체의 캡슐화를 위협하는 코드가 된다.
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
	//boundingBox 호출로 임시 Rectangle 객체 생성(temp라고 하자)
	//->upperleft를 통해 temp의 Point객체의 참조자가 나옴
	//->해당 문장이 끝나면서 temp가 소멸
	//->temp의 Point 객체들도 사라짐 
}