//ITEM 18 : Use std::unique_ptr for exclusive-ownership resource management

//unique_ptr�� move only type!!
#include<iostream>
class Investment
{
public:
	virtual ~Investment();
};

class Stock: public Investment
{};

class Bond : public Investment
{};

class RealEstate : public Investment
{};

template<typename... Ts>
auto makeInvesetment(Ts&&... params)
{
	auto delInvmt = [](Investment* pInvestment) //Ŀ���� ������
	{
		makeLogEntry(pInvestment);
		delete pInvestment;
	};

	std::unique_ptr<Investment, decltype(delInvmt)> pInv(nullptr, delInvmt);

	if (/*Stock ��ü ����*/)
	{
		pInv.reset(new Stock(std::forward<Ts>(params)...));
	}
	else if (/*Bond ��ü ����*/)
	{
		pInv.reset(new Bond(std::forward<Ts>(params)...));
	}
	else if (/*RealEstate ��ü ����*/)
	{
		pInv.reset(new RealEstate(std::forward<Ts>(params)...));
	}
	return pInv;
}