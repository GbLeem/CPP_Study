//ITEM 20 : Use std::weak_ptr for std::shared_ptr like pointer that can dangle

#include<iostream>
class Widget {};

int main()
{
	auto spw = std::make_shared<Widget>();

	std::weak_ptr<Widget>wpw(spw);

	spw = nullptr; //wpw는 대상을 잃음

	if (wpw.expired())//wpw가 가리키는 객체가 없다면..
	{

	}
}

//weak_ptr은 shared_ptr을 이용해서 생성된다. 자신을 생성하는데 쓰인 shared_ptr이 가리키는 것과 동일한 객체를
//가리키지만 참조 카운트에는 영향을 주지 않는다.
//역참조 연산이 없다.