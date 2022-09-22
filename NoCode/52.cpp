//				<std::function>


//�Լ��� �ϳ� �����ϸ� input�� output�� �߻�
//->input�� output ���̿��� side effect�� ����!

#include<iostream>
#include<functional>
#include<vector>

class FunctionObj
{
public:
	void operator() (int i)
	{
		std::cout << "functionObj " << i << std::endl;
	}
};

void freeFunction(int i)
{
	std::cout << "freefunction " << i << std::endl;
}

//�Լ��� �޾Ƽ� �Լ��� �������� -> �Լ� ������ �� �ƴ϶�, function object, lambda function ���� �ְ� �ʹ�!->std::function
void runFunction(int i, void (*fnPtr)(int))
{
	(*fnPtr)(i);
}

//std::function ���
void runFunctionBetter(int i, const std::function<void(int)> &fn)
{
	fn(i);
}

void runFunctions(const std::vector<std::function<void(int)>>& functions)
{
	int i = 0;
	for (const auto& fn : functions)
	{
		fn(++i);
	}
}

int main()
{
	//�Ϲ� function
	freeFunction(10);

	//function pointer
	void(*fnPtr)(int);
	fnPtr = freeFunction;
	(*fnPtr)(20);

	//function object
	FunctionObj functionObj;
	functionObj(10);

	//lambda function
	auto lambdaFunc = [](int i)
	{
		std::cout << "lambda function " << i << std::endl;
	};
	lambdaFunc(10);
	
	std::cout << std::endl;

	//std::function -> �Ʒ� ó�� ��� �Լ� �� �־���
	runFunctionBetter(10, fnPtr);
	runFunctionBetter(20, functionObj);
	runFunctionBetter(30, lambdaFunc);

	std::cout << std::endl;

	//�Լ��� ������Ʈ ó�� �� �� �ִ�.
	std::vector<std::function<void(int)>> functions;
	functions.emplace_back(freeFunction);
	functions.emplace_back(functionObj);
	functions.emplace_back(lambdaFunc);
	runFunctions(functions);
	return 0;
}