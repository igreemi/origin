#include <iostream>
#include <string>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	//Fraction(){}
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
		if (denominator == 0) {
			throw " Denominator cannot be 0 ";
		}
	}

	Fraction operator+(const Fraction& other)
	{

		numerator_ = (numerator_ * other.denominator_) +
			(other.numerator_ * denominator_);
		denominator_ = denominator_ * other.denominator_;
		Reduction(numerator_, denominator_);
		return Fraction(numerator_, denominator_);

	}
	Fraction operator-(const Fraction& other)
	{
		numerator_ = (numerator_ * other.denominator_) -
			(other.numerator_ * denominator_);
		denominator_ = denominator_ * other.denominator_;
		Reduction(numerator_, denominator_);
		return Fraction(numerator_, denominator_);

	}

	Fraction operator*(const Fraction& other)
	{

		numerator_ = numerator_ * other.numerator_;
		denominator_ = denominator_ * other.denominator_;
		Reduction(numerator_, denominator_);
		return Fraction(numerator_, denominator_);

	}

	Fraction operator/(const Fraction& other)
	{

		numerator_ = numerator_ * other.denominator_;
		denominator_ = denominator_ * other.numerator_;
		Reduction(numerator_, denominator_);
		return Fraction(numerator_, denominator_);

	}

	Fraction& operator++()
	{
		numerator_++;
		denominator_++;

		return *this;
	}
	Fraction operator++(int) {

		Fraction temp = *this;
		++(*this);
		return temp;

	}

	Fraction& operator--()
	{
		numerator_--;
		denominator_--;

		return *this;
	}
	Fraction operator--(int) {

		Fraction temp = *this;
		--(*this);
		return temp;

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

	void Print() { std::cout << numerator_ << "/" << denominator_ << "\n"; }
};




int main()
{

	setlocale(LC_ALL, "Russian");
	int num1 = 3, num2 = 4;
	int denom1 = 4, denom2 = 5;

	std::cout << "Введите числитель дроби 1: ";
	//	std::cin >> num1;

	std::cout << "Введите знаменатель дроби 1: ";
	//	std::cin >> denom1;

	std::cout << "Введите числитель дроби 2: ";
	//	std::cin >> num2;

	std::cout << "Введите знаменатель дроби 2: ";
	//	std::cin >> denom2;
	std::cout << std::endl;

	Fraction f1(num1, denom1);
	Fraction f2(num2, denom2);

	Fraction sum = f1 + f2;
	sum.Print();
	std::cout << std::endl;

	Fraction sub = f1 - f2;
	sub.Print();
	std::cout << std::endl;

	Fraction mult = f1 * f2;
	mult.Print();
	std::cout << std::endl;

	Fraction div = f1 / f2;
	div.Print();
	std::cout << std::endl;

	Fraction incPre = ++f1 * f2;
	incPre.Print();
	std::cout << std::endl;

	Fraction incPos = f1++ * f2;
	incPos.Print();
	std::cout << std::endl;

	Fraction decPre = --f1 * f2;
	decPre.Print();
	std::cout << std::endl;

	Fraction decPos = f1-- * f2;
	decPos.Print();
	std::cout << std::endl;

	return 0;
}

