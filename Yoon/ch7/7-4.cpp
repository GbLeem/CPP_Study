//상속을 위한 죠건

//상속은 IS-A 관계에 적합하다.
//HAS-A 관계에 써도 되긴 하지만... 적절한 경우 사용해야 한다.

//문제 1.
//#include<iostream>
//using namespace std;
//
//class Rectangle
//{
//private:
//	int width;
//	int height;
//
//public:
//	Rectangle(int w,int h)
//		:width(w)
//		,height(h)
//	{}
//
//	void ShowAreaInfo() const
//	{
//		cout << "Area : " << width * height << endl;
//	}
//};
//
//class Square :public Rectangle
//{
//public:
//	Square(int w)
//		:Rectangle(w,w)
//	{}
//};
//
//int main()
//{
//	Rectangle rec(4, 3);
//	rec.ShowAreaInfo();
//
//	Square sqr(7);
//	sqr.ShowAreaInfo();
//
//	return 0;
//}


//문제 2.
#include<iostream>
using namespace std;

class Book
{
private:
	char* title;
	char* isbn;
	int price;
public:
	Book(const char* t, const char* i, int p)
		:price(p)
	{
		title = new char[strlen(t) + 1];
		isbn = new char[strlen(i) + 1];

		strcpy_s(title, strlen(t) + 1, t);
		strcpy_s(isbn, strlen(i) + 1, i);
	}

	void showBookInfo()const
	{
		cout << "title : " << title << endl;
		cout << "isbn : " << isbn << endl;
		cout << "price : " << price << endl;
	}
};

class EBook :public Book
{
private:
	char* DRMKey;

public:
	EBook(const char* t, const char* i, int p,const char* D)
		:Book(t,i,p)
	{
		DRMKey = new char[strlen(D) + 1];
		strcpy_s(DRMKey, strlen(D) + 1, D);
	}
	void showEBookInfo() const
	{
		showBookInfo();
		cout << "DRMKey : " << DRMKey << endl;
	}
};

int main()
{
	Book book("good c++", "555-12345-890-0", 20000);
	book.showBookInfo();
	cout << endl;

	EBook ebook("good c++ ebook", "111-11111-111-1", 10000,"fasdc-asd-sadasd");
	ebook.showEBookInfo();
	return 0;
}