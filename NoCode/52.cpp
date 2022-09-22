//				<std::function>


//함수를 하나 정의하면 input과 output이 발생
//->input과 output 사이에는 side effect가 없다!

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

//함수를 받아서 함수를 실행해줌 -> 함수 포인터 뿐 아니라, function object, lambda function 등을 넣고 싶다!->std::function
void runFunction(int i, void (*fnPtr)(int))
{
	(*fnPtr)(i);
}

//std::function 사용
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
	//일반 function
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

	//std::function -> 아래 처럼 모든 함수 다 넣어짐
	runFunctionBetter(10, fnPtr);
	runFunctionBetter(20, functionObj);
	runFunctionBetter(30, lambdaFunc);

	std::cout << std::endl;

	//함수를 오브젝트 처럼 쓸 수 있다.
	std::vector<std::function<void(int)>> functions;
	functions.emplace_back(freeFunction);
	functions.emplace_back(functionObj);
	functions.emplace_back(lambdaFunc);
	runFunctions(functions);
	return 0;
}