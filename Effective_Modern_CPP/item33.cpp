//ITEM 33 : Use decltype on auto&& parameters to std::forward them

auto f = [](auto x)
{
	return normalize(x);
};

//lval 과 rval모두 제대로 처리
auto f = [](auto&& x)
{
	return normalize(std::forward<decltype(x)>(x));
};

//추가적인 매개변수까지 처리
auto f = [](auto&&... xs)
{
	return normalize(std::forward<decltype(xs)>(xs)...);
};

class C //위의 람다식과 같은 뜻
{
public:
	template<typename T>
	auto operator() (T x)const
	{
		return normalize(x);
	}
};