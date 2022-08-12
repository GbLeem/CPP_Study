//ITEM 14 : Declare functions noexcept if they won't emit exceptions

template<class T,size_t N>
void swap(T(&a)[N], T(&b)[N]) noexcept(noexcept(swap(*a, *b)));

template<class T1,class T2>
struct pair
{
	void swap(pair& p) noexcept(noexcept(swap(first, p.first)) && noexcept(swap(second, p.second)));
};