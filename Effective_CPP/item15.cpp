#include<iostream>

class Investment
{
public:
	bool isTaxFree() const;
};

Investment* createInvestment();

int daysHeld(const Investment* pi);

std::tr1::shared_ptr<Investment>pInv(createInvestment());

int days = daysHeld(pInv.get()); // ����� ��ȯ


//�Ͻ��� ��ȯ
std::tr1::shared_ptr<Investment>pi1(createInvestment());

bool taxable1 = !(pi1->isTaxFree()); 

std::auto_ptr<Investment>pi2(createInvestment());

bool taxable2 = !((*pi2).isTaxFree());
