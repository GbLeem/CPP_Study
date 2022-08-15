//ITEM 16 : Make const member functions threada safe


#include<vector>
#include<mutex>
class Polynomial
{
public:
	using RootsType = std::vector<double>;

	RootsType roots() const
	{
		std::lock_guard <std::mutex>g(m);
		if (!rootsAreValid)
		{
			rootsAreValid = true;
		}
		return rootVals;
	}

private:
	mutable std::mutex m;
	mutable bool rootsAreValid{ false };
	mutable RootsType rootVals{};
};