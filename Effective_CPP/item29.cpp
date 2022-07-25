#include<iostream>

//class Mutex
//{
//
//};
//
//class Lock
//{
//public:
//	explicit Lock(Mutex* pm)
//		:mutexPtr(pm,std::mutex::unlock)
//	{
//		lock
//	}
//private:
//	std::tr1::shared_ptr<Mutex> mutexPtr;
//};

class Image
{
	//...
};

struct PMImpl
{
	std::tr1::shared_ptr<Image> bgImage;
	int imageChange;
};

class PrettyMenu
{
	//...
private:
	Mutex mutex;
	std::tr1::shared_ptr<PMImpl> pImpl;
};

void PrettyMenu::ChangeBackGround(Image& imgSrc)
{
	using std::swap;

	Lock ml(&mutex);
	std::tr1::shared_ptr<PMImpl> pNew(new PMImpl(*pImpl)); //��ü�� ������ �κ��� ����

	pNew->bgImage.reset(new Image(imgSrc)); //�纻 ����
	++pNew->imageChange;

	swap(pImpl, pNew); //�� �����Ϳ� �ٲٱ�
}