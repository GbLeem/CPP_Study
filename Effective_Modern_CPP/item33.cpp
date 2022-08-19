//ITEM 33 : Use decltype on auto&& parameters to std::forward them

auto f = [](auto x)
{
	return normalize(x);
};

//lval �� rval��� ����� ó��
auto f = [](auto&& x)
{
	return normalize(std::forward<decltype(x)>(x));
};

//�߰����� �Ű��������� ó��
auto f = [](auto&&... xs)
{
	return normalize(std::forward<decltype(xs)>(xs)...);
};

class C //���� ���ٽİ� ���� ��
{
public:
	template<typename T>
	auto operator() (T x)const
	{
		return normalize(x);
	}
};