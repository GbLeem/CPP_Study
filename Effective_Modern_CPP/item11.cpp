//ITEM 11 : Prefer deleted functions to private undefineed ones


//c++11 ǥ�� basic_ios �ڵ�
template<class charT, class traits=char_traits<charT>>
class basic_ios :public ios_base
{
public:
	//�Ⱦ��� �Լ��� ����� �����ϱ� ���� = delete ����
	//������ �Լ��� public���� �δ°��� �����̴�.
	basic_ios(const basic_ios&) = delete; 
	basic_ios& operator=(const basic_ios&) = delete;
};


//---------------------------
class Widget
{
public:
	template<typename T>
	void ProcessPointer(T* ptr)
	{}

//private:
//	template<>
//	void ProcessPointer<void>(void*); //����
	
};

template<>
void Widget::ProcessPointer<void>(void*) = delete;