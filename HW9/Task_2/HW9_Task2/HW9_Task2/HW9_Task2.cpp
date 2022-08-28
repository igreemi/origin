#include <iostream>
#include <string>

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
		if (denominator == 0) {
			throw " Denominator cannot be 0 ";
		}

	}


	Fraction() {}

	Fraction operator+(const Fraction& other)
	{
		Fraction f;
		f.numerator_ = (numerator_ * other.denominator_) +
			(other.numerator_ * denominator_);
		f.denominator_ = (denominator_ * other.denominator_);
		f.Reduction();

		return f;

	}
	Fraction operator-(const Fraction& other)
	{
		Fraction f;
		f.numerator_ = numerator_ * other.denominator_ -
			other.numerator_ * denominator_;
		f.denominator_ = denominator_ * other.denominator_;
		f.Reduction();

		return f;

	}

	Fraction operator*(const Fraction& other)
	{
		Fraction f;
		f.numerator_ = numerator_ * other.numerator_;
		f.denominator_ = denominator_ * other.denominator_;
		f.Reduction();

		return f;

	}

	Fraction operator/(const Fraction& other)
	{
		Fraction f;
		f.numerator_ = numerator_ * other.denominator_;
		f.denominator_ = denominator_ * other.numerator_;
		f.Reduction();

		return f;

	}

	Fraction& operator++()
	{
		numerator_ += denominator_;
		return *this;

	}
	Fraction operator++(int) {

		Fraction f = *this;
		++(*this);
		return f;

	}

	Fraction& operator--()
	{
		numerator_ -= denominator_;
		return *this;

	}
	Fraction operator--(int) {

		Fraction f = *this;
		--(*this);
		return f;

	}

	int gcd(int num, int den) {

		if (num == 0 || den == 0) {
			return num;
		}
		else {
			return gcd(den, num % den);
		}
	}

	void Reduction() {
		int x = gcd(numerator_, denominator_);
		if (x < 0) {
			x = x * -1;
		}
		if (x != 0) {

			numerator_ = numerator_ / x;
			denominator_ = denominator_ / x;
		}
	}

	std::string Print()
	{
		if (numerator_ == denominator_) {
			return std::to_string(1);
		}
		else
			if (numerator_ == 0 || denominator_ == 0) {
				return std::to_string(0);
			}
			else {
				return std::to_string(numerator_) + "/" + std::to_string(denominator_);
			}
	}

};




int main()
{

	setlocale(LC_ALL, "Russian");
	try {
		int num1 = 2, num2 = 2;
		int denom1 = 3, denom2 = 3;

		std::cout << "Введите числитель дроби 1: ";
		std::cin >> num1;

		std::cout << "Введите знаменатель дроби 1: ";
		std::cin >> denom1;

		std::cout << "Введите числитель дроби 2: ";
		std::cin >> num2;

		std::cout << "Введите знаменатель дроби 2: ";
		std::cin >> denom2;
		std::cout << std::endl;

		Fraction f1(num1, denom1);
		Fraction f2(num2, denom2);

		Fraction sum = f1 + f2;
		std::cout << f1.Print() << " + " << f2.Print() << " = " << sum.Print() << std::endl;

		Fraction sub = f1 - f2;
		std::cout << f1.Print() << " - " << f2.Print() << " = " << sub.Print() << std::endl;

		Fraction mult = f1 * f2;
		std::cout << f1.Print() << " * " << f2.Print() << " = " << mult.Print() << std::endl;

		Fraction div = f1 / f2;
		std::cout << f1.Print() << " / " << f2.Print() << " = " << div.Print() << std::endl;
		std::cout << std::endl;

		Fraction incPre = ++f1 * f2;

		std::cout << "++" << f1.Print() << " * " << f2.Print() << " = " << incPre.Print() << std::endl;

		std::cout << "Значение дроби 1 = " << f1.Print() << std::endl;

		//		Fraction incPos = f1++ * f2;
		//		std::cout << f1.Print() << "++" << " * " << f2.Print() << " = " << incPos.Print() << std::endl;

		//		Fraction decPre = --f1 * f2;
		//		std::cout << "--" << f1.Print() << " * " << f2.Print() << " = " << decPre.Print() << std::endl;

		Fraction decPos = f1-- * f2;
		std::cout << f1.Print() << "--" << " * " << f2.Print() << " = " << decPos.Print() << std::endl;
		std::cout << "Значение дроби 1 = " << f1.Print() << std::endl;

	}
	catch (const std::invalid_argument& msg) {
		std::cout << msg.what() << std::endl;
	}
	return 0;
}

