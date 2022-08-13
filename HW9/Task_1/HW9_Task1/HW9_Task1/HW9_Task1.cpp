#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	int Abs() {
		Reduction(numerator_, denominator_);
		if (numerator_ > denominator_) {
			numerator_ = numerator_ + denominator_;
		}
		return std::sqrt(numerator_ * numerator_ + denominator_ * denominator_);
	}

	int gcd(int num, int den) {

		if (num == 0 || den == 0) {
			return num;
		}
		else {
			return gcd(den, num % den);
		}
	}

	void Reduction(int num, int den) {
		int x = gcd(num, den);
		if (x < 0) {
			x = x * -1;
		}
		if (x != 0) {
			numerator_ = num / x;
			denominator_ = den / x;
		}

	}

	bool operator==(Fraction other) { return Abs() == other.Abs(); }
	bool operator!=(Fraction other) { return !(*this == other); }
	bool operator<(Fraction other) { return Abs() < other.Abs(); }
	bool operator>(Fraction other) { return other < *this; }
	bool operator>=(Fraction other) { return !(*this < other); }
	bool operator<=(Fraction other) { return !(*this > other); }

};

int main()
{
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';

	return 0;
}