#include <iostream>
#include <string>
#include <algorithm>

class big_integer {
private:
	std::string value;

public:
	big_integer() {}

	~big_integer() {}

	big_integer(const std::string& val) : value(val) {}

	big_integer(std::string&& val) : value(std::move(val)) {}

	big_integer(const big_integer& other) : value(other.value) {}

	big_integer(big_integer&& other) noexcept : value(std::move(other.value)) {}

	big_integer& operator=(const big_integer& other)
	{
		if (this != &other)
		{
			value = other.value;
		}
		return *this;
	}

	big_integer& operator=(big_integer&& other) noexcept
	{
		if (this != &other) {
			value = std::move(other.value);
		}
		return *this;
	}

	big_integer operator+(const big_integer& other) const
	{
		std::string result;

		int carry = 0;
		int i = value.size() - 1;
		int j = other.value.size() - 1;

		while (i >= 0 || j >= 0 || carry != 0)
		{
			int x = (i >= 0) ? value[i--] - '0' : 0;
			int y = (j >= 0) ? other.value[j--] - '0' : 0;
			int sum = x + y + carry;
			carry = sum / 10;
			result += std::to_string(sum % 10);
		}

		std::reverse(result.begin(), result.end());

		return big_integer(std::move(result));
	}

	big_integer operator*(const big_integer& other) const
	{
		std::string result;
		std::string tmp_res;
		std::string tmp_res2;

		int carry = 0;
		int discharge_counter = 0;
		int j = other.value.size() - 1;

		for (j; j >= 0; j--)
		{
			int i = value.size() - 1;

			if (tmp_res != tmp_res2)
			{
				tmp_res2 = result;
				result = "";
				tmp_res = "";
			}

			int y = (j >= 0) ? other.value[j] - '0' : 0;

			while (i >= 0 || carry != 0)
			{
				int x = (i >= 0) ? value[i--] - '0' : 0;
				int mult = x * y + carry;
				carry = mult / 10;
				tmp_res += std::to_string(mult % 10);
			}

			std::reverse(tmp_res.begin(), tmp_res.end());

			if (j >= 0)
			{
				for (int i = 0; i < discharge_counter; i++)
				{
					tmp_res.push_back('0');
				}

				int carry = 0;
				int a = tmp_res.size() - 1;
				int b = tmp_res2.size() - 1;

				while (a >= 0 || b >= 0 || carry != 0)
				{
					int x = (a >= 0) ? tmp_res[a--] - '0' : 0;
					int y = (b >= 0) ? tmp_res2[b--] - '0' : 0;
					int sum = x + y + carry;
					carry = sum / 10;
					result += std::to_string(sum % 10);
				}
				std::reverse(result.begin(), result.end());
			}
			discharge_counter++;
		}
		return big_integer(std::move(result));
	}

	friend std::ostream& operator<<(std::ostream& os, const big_integer& obj)
	{
		os << obj.value;
		return os;
	}
};

int main() 
{
	auto number1 = big_integer("114575");
	auto number2 = big_integer("78524");
	auto result = number1 + number2;
	std::cout << "SUM: " << result << " | reference: 193099" <<  std::endl; // 193099

	auto number3 = big_integer("78524");
	auto number4 = big_integer("114575");
	auto result2 = number3 * number4;
	std::cout << "MULT: " << result2 << " | reference: 8996887300" << std::endl; // 8996887300

	return 0;
}
