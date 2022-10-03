//			<floating numbers1>


#include<iostream>

bool almostEqual(float a, float b)
{
	const float diff = std::abs(a - b);
	return diff < 0.0001;
}

bool almost_equal(float x, float y, int ulp)
{
	const float diff = std::fabs(x - y);
	return diff <= std::numeric_limits<float>::epsilon() * std::fabs(x + y) * ulp
		// unless the result is subnormal
		|| diff < std::numeric_limits<float>::min();
}

int main()
{
	const float num1 = 0.3f;
	const float num2 = 0.4f;

	const float sum = num1 + num2;

	if (almost_equal(0.7f, sum, 1))
	{
		std::cout << "sum is 0.7f" << std::endl;
	}
	else
		std::cout << "sum is not 0.7" << std::endl;

	//"sum is not 0.7" ���
	//�Ҽ����� ��Ȯ�ϰ� ǥ���� �� �� ����.(�ٻ簪���� ǥ��)
	//-> almost_equal ���
	return 0;
}