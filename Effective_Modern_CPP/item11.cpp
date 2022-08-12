//ITEM 11 : Prefer deleted functions to private undefineed ones


//c++11 표준 basic_ios 코드
template<class charT, class traits=char_traits<charT>>
class basic_ios :public ios_base
{
public:
	//안쓰는 함수의 사용을 방지하기 위해 = delete 붙임
	//삭제된 함수는 public으로 두는것이 관례이다.
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
//	void ProcessPointer<void>(void*); //오류
	
};

template<>
void Widget::ProcessPointer<void>(void*) = delete;