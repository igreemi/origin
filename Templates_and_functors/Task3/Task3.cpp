#include <iostream>
#include <vector>

class Functor
{
private:
	int sum = 0;
	int count = 0;

public:
	void operator () (int val)
	{
		if (val % 3 == 0)
		{
			sum += val;
			++count;
		}
	}
	int get_sum()
	{
		return sum;
	}
	int get_count()
	{
		return count;
	}
};
int main() {
	std::vector<int> arr = { 4, 1, 3, 6, 25, 54 };
	std::cout << "[IN]: ";
	for (int i : arr)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	Functor f;
	for (int i : arr)
	{
		f(i);
	}

	std::cout << "[OUT] : get_sum() = " << f.get_sum() << std::endl;
	std::cout << "[OUT] : get_count() = " << f.get_count() << std::endl;

	return 0;
}
