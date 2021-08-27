#include "cfraction.h"

//constructor
fraction::fraction()
{
	denominator = 1;
	numerator = 0;
}
fraction::fraction(const int x)
{
	denominator = 1;
	numerator = x;
}
fraction::fraction(const float a)
{
	int pow = 1;
	while (round(a * static_cast<float>(pow)) != a * static_cast<float>(pow))
	{
		pow *= 10;
	}
	fraction b(a * static_cast<float>(pow), pow);
	b.simplify();
	numerator = b.numerator;
	denominator = b.denominator;
}
fraction::fraction(const int n, const int d) :
	denominator(d), numerator(n)
{
	if (d == 0)
	{
		setDenominator(1);
	}
}
fraction::fraction(const fraction a, const fraction b)
{
	*this = a / b;
}

//basic fraction operator
void fraction::simplify()
{
	for (int i = denominator; i > 1; i--)
	{
		if (denominator % i == 0 && numerator % i == 0)
		{
			denominator /= i;
			numerator /= i;
			break;
		}
	}
	if (denominator < 0)
	{
		denominator *= -1;
		numerator *= -1;
	}
}
fraction fraction::simplify(fraction a)
{
	a.simplify();
	return a;
}
fraction fraction::inverse(const fraction a)
{
	fraction r;
	if (a.getNumerator() != 0)
		r = fraction(a.getDenominator(), a.getNumerator());
	return simplify(r);
}
void fraction::inverse()
{
	if (numerator != 0)
	{
		int temp = numerator;
		numerator = denominator;
		denominator = temp;
	}
}

bool fraction::isLegalFraction(const fraction a)
{
	return (a.getDenominator() != 0);
}

//advanced math function
int fraction::signof(fraction a)
{
	a.simplify();
	return a.getNumerator() > 0 ? 1 : -1;
}
fraction fraction::abs(const fraction a)
{
	return fraction(signof(static_cast<fraction>(a.getNumerator())) * a.getNumerator(),
		signof(static_cast<fraction>(a.getDenominator())) * a.getDenominator());
}
fraction fraction::pow(fraction a, const int n)
{
	a.simplify();
	int nu = a.getNumerator(), de = a.getDenominator();
	for (int i = 1; i < n; i++)
	{
		a.setFraction(a.getNumerator() * nu, a.getDenominator() * de);
	}
	return a;
}
fraction fraction::sqrt(const fraction a)
{
	return fraction(std::sqrt(a.getNumerator()), std::sqrt(a.getDenominator()));
}

//get, set component
int fraction::getDenominator() const
{
	return denominator;
}
int fraction::getNumerator() const
{
	return numerator;
}
void fraction::setDenominator(const int a)
{
	if (a != 0)
	{
		denominator = a;
	}
	else
	{
		denominator = 1;
	}
}
void fraction::setNumerator(const int a)
{
	numerator = a;
}
void fraction::setFraction(const int a, const int b)
{
	setNumerator(a);
	setDenominator(b);
}

//type cast function
float fraction::toFloat(const fraction a)
{
	return static_cast<float>(a.getNumerator()) / static_cast<float>(a.getDenominator());
}
float fraction::toFloat() const
{
	return static_cast<float>(numerator) / static_cast<float>(denominator);
}
string fraction::to_string(const fraction a)
{
	return std::to_string(a.getNumerator()) + "/"
		+ std::to_string(a.getDenominator());
}

//basic arithmetic operator
fraction fraction::operator + (const fraction b) const
{
	fraction r(numerator * b.getDenominator() + b.getNumerator() * denominator, denominator * b.getDenominator());
	return simplify(r);
}
fraction fraction::operator - (const fraction b) const
{
	fraction r(numerator * b.getDenominator() - b.getNumerator() * denominator, denominator * b.getDenominator());
	return simplify(r);
}
fraction fraction::operator - ()
{
	simplify();
	setNumerator(-getNumerator());
	return simplify(*this);
}
fraction fraction::operator * (const fraction b) const
{
	fraction r(numerator * b.getNumerator(), denominator * b.getDenominator());
	return simplify(r);
}
fraction fraction::operator / (fraction b) const
{
	b.inverse();
	fraction r(numerator * b.getNumerator(), denominator * b.getDenominator());
	return simplify(r);
}

//basic relational operator
bool fraction::operator == (fraction b) const
{
	fraction a(numerator, denominator);
	a.simplify();
	b.simplify();
	return (a.getDenominator() == b.getDenominator() && a.getNumerator() == b.getNumerator());
}
bool fraction::operator > (const fraction b) const
{
	fraction a(numerator, denominator);
	fraction fraction = fraction::simplify(a - b);
	return (fraction.getNumerator() > 0);
}
bool fraction::operator <(fraction b) const
{
	fraction a(numerator, denominator);
	a.simplify();
	b.simplify();
	fraction frac = fraction::simplify(a - b);
	return (frac.getNumerator() < 0);
}
bool fraction::operator >= (fraction b) const
{
	fraction a(numerator, denominator);
	a.simplify();
	b.simplify();
	return (a == b || a > b);
}
bool fraction::operator <= (const fraction b) const
{
	fraction a(numerator, denominator);
	return (a == b || a < b);
}
bool fraction::operator != (const fraction b) const
{
	fraction a(numerator, denominator);
	return (!(a == b));
}

//basic assignment operator
void fraction::operator += (const fraction b)
{
	fraction a(numerator, denominator);
	*this = fraction::simplify(a + b);
}
void fraction::operator -= (const fraction b)
{
	fraction a(numerator, denominator);
	*this = fraction::simplify(a - b);
}
void fraction::operator *= (const fraction b)
{
	fraction a(numerator, denominator);
	*this = fraction::simplify(a * b);
}
void fraction::operator /= (const fraction b)
{
	fraction a(numerator, denominator);
	*this = fraction::simplify(a / b);
}
fraction& fraction::operator = (const int x)
{
	this->setDenominator(1);
	this->setNumerator(x);
	return *this;
}
fraction& fraction::operator = (const float x)
{
	*this = fraction(x);
	return *this;
}

//iostream operator
ostream& operator << (ostream& os, const fraction& a)
{
	if (a.denominator == 1)
	{
		os << a.numerator;
	}
	else
	{
		os << a.numerator << "/" << a.denominator;
	}
	return os;
}
istream& operator >> (istream& is, fraction& a)
{
	is >> a.numerator >> a.denominator;
	return is;
}

//type cast operator
fraction::operator float() const
{
	return static_cast<float>(numerator) / static_cast<float>(denominator);
}
fraction::operator int() const
{
	return numerator / denominator;
}

//literal operator
fraction operator"" _frac(const long double val)
{
	return fraction(static_cast<float>(val));
}

fraction operator ""_frac(const unsigned long long int a)
{
	return fraction(a, 1);
}