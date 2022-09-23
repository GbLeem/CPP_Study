//					<ND array>


#include<array>
#include<vector>
#include<iostream>

//2���� referencing ����, ���� �����ʹ� 1���� data
template<typename T, int ROW, int COL>
class Matrix
{
public:
	Matrix(int ROW, int COL)
		:mMatrix(ROW* COL, 0)
	{
	}
	T& operator()(int rowIdx, int colIdx)
	{
		const int idx = rowIdx * COL + colIdx;
		return mMatrix[idx];
	}
private:
	std::vector<T>mMatrix;
};

int main()
{
	////2���� array
	//std::array < std::array<int, 3>, 3> fixedMatrix;
	////2���� vector
	//std::vector<std::vector<int>> dynamicMatrix(3, std::vector <int>(3));

	//fixedMatrix[1][1] = 5;
	//dynamicMatrix[1][2] = 100;

	Matrix<int,10,10> mat(10, 10);
	mat(3, 3) = 3;
	mat(4, 3) = mat(3, 3) * 10;
	std::cout << mat(4, 3) << std::endl;
	return 0;
}

//������  array�� loop

int main()
{
	std::array<std::array<int, 10>, 10> mat;

	//cache�� ���� �ٸ� ������ ��Ÿ����.
	for (int row = 0; row < 10; ++row)
	{
		for (int col = 0; col < 10; ++col)
		{
			mat[row][col] += 1;
		}
	}


	for (int col = 0; col < 10; ++col)
	{
		for (int row = 0; row < 10; ++row)
		{
			mat[col][row] += 1;
		}
	}