//¹®Á¦ 1.
#include<iostream>
#include<cstring>
using namespace std;

//class Gun
//{
//private:
//	int bullet;
//public:
//	Gun(int bnum)
//		:bullet(bnum)
//	{}
//	void Shot()
//	{
//		cout << "bang!" << endl;
//		bullet--;
//	}
//};
//
//class Police
//{
//private:
//	int handcuffs;
//	Gun* pistol;
//public:
//	Police(int bnum, int bcuff)
//		:handcuffs(bcuff)
//	{
//		if (bnum > 0)
//			pistol = new Gun(bnum);
//		else
//			pistol = nullptr;
//	}
//	void PutHandcuff()
//	{
//		cout << "Snap!" << endl;
//		handcuffs--;
//	}
//	void Shot()
//	{
//		if (pistol == nullptr)
//			cout << "NO GUN" << endl;
//		else
//			pistol->Shot();
//	}
//	~Police()
//	{
//		if (pistol != nullptr)
//			delete pistol;
//	}
//	Police& operator=(const Police& ref)
//	{
//		if(pistol!=nullptr)
//			delete pistol;
//		if (ref.pistol != nullptr)
//			pistol = new Gun(*(ref.pistol));//!!
//		else
//			pistol = nullptr;
//
//		handcuffs = ref.handcuffs;
//		return *this;
//	}
//};
//
//int main()
//{
//	Police p1(1, 1);
//	Police p2(10, 20);
//	p2 = p1;
//
//	p2.Shot();
//	p2.Shot();
//	p2.Shot();
//}

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
	Book& operator=(const Book& ref)
	{
		delete []title;
		delete []isbn;
		
		title = new char[strlen(ref.title) + 1];
		isbn = new char[strlen(ref.isbn) + 1];

		strcpy_s(title, strlen(ref.title) + 1, ref.title);
		strcpy_s(isbn, strlen(ref.isbn) + 1, ref.isbn);

		price = ref.price;

		return *this;
	}
	//~Book()
	//{
	//	delete []title;
	//	delete []isbn;
	//	cout << "book destructor" << endl;
	//}
};

class EBook :public Book
{
private:
	char* DRMKey;

public:
	EBook(const char* t, const char* i, int p, const char* D)
		:Book(t, i, p)
	{
		DRMKey = new char[strlen(D) + 1];
		strcpy_s(DRMKey, strlen(D) + 1, D);
	}
	void showEBookInfo() const
	{
		showBookInfo();
		cout << "DRMKey : " << DRMKey << endl;
	}
	EBook& operator=(const EBook& ref)
	{
		Book::operator=(ref);
		delete []DRMKey;

		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy_s(DRMKey, strlen(ref.DRMKey) + 1, ref.DRMKey);

		return *this;
	}
	/*~EBook()
	{
		delete []DRMKey;
		cout << "desturctor EBook" << endl;
	}*/
};

int main()
{
	EBook ebook1("C++", "555-1234-555-1", 10000, "asfasfa");
	EBook ebook2 = ebook1;
	ebook2.showEBookInfo();
	cout << endl;

	EBook ebook3("python", "111-1111-111-1", 20000, "aaaaaa");
	ebook3 = ebook2;
	ebook3.showEBookInfo();

	return 0;
}