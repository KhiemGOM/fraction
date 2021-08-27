#pragma once
#include <iostream>
#include <string>
using namespace std;

class fraction
{
	int denominator{}, numerator{};
public:

	//constructor
	fraction();
	explicit fraction(int x);
	explicit fraction(float a);
	fraction(int n, int d);
	fraction(fraction a, fraction b);

	//basic fraction operator
	void simplify();
	static fraction simplify(fraction a);
	static fraction inverse(fraction a);
	void inverse();
	static bool isLegalFraction(fraction a);
	bool isLegalFraction() const;

	//advanced math function
	static int signof(fraction a);
	static fraction abs(fraction a);
	static fraction pow(fraction a, int n);
	static fraction sqrt(fraction a);

	//get, set component
	int getDenominator() const;
	int getNumerator() const;
	void setDenominator(int a);
	void setNumerator(int a);
	void setFraction(int a, int b);

	//type cast function
	string to_string(fraction a);
	static float toFloat(fraction a);
	float toFloat() const;

	//basic arithmetic operator
	fraction operator + (fraction b) const;
	fraction operator - (fraction b) const;
	fraction operator - ();
	fraction operator * (fraction b) const;
	fraction operator / (fraction b) const;

	//basic relational operator
	bool operator == (fraction b) const;
	bool operator > (fraction b) const;
	bool operator < (fraction b) const;
	bool operator >= (fraction b) const;
	bool operator <= (fraction b) const;
	bool operator != (fraction b) const;

	//basic assignment operator
	void operator += (fraction b);
	void operator -= (fraction b);
	void operator *= (fraction b);
	void operator /= (fraction b);
	fraction& operator = (int x);
	fraction& operator = (float x);

	//iostream operator
	friend ostream& operator << (ostream& os, const fraction& a);
	friend istream& operator >> (istream& is, fraction& a);

	//type cast operator
	explicit operator float() const;
	explicit operator int() const;

	//literal operator
	//friend fraction operator"" _frac(long double val);
	//friend fraction operator "" _frac(unsigned long long int a);
};