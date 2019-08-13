// PolynomialsLib.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "PolynomialsLib.h"
#include <ostream>
using namespace std;

// TODO: This is an example of a library function
void fnPolynomialsLib()
{
}

/*
Constructor. Takes the coefficients of the polynomial. The 
coefficients should be at the index of their variables
exponent. For example, 4x^3 + 2x^2 - 7 would be passed in as
Polynomial(int[4]{7, 0, 2, 4}).
*/
Polynomial::Polynomial(vector<double> coefficients)
{
	this->coefficients = coefficients;
	while (this->coefficients.size() > 0 && this->coefficients[this->coefficients.size()-1] == 0)
	{
		this->coefficients.pop_back();
	}
}

/*
Gets the degree of the polynomial, or the highest eponent of the polynomial.
*/
int Polynomial::GetDegree() const
{
	int degree = coefficients.size() - 1;

	if (degree < 0)
	{
		degree = 0;
	}
	return degree;
}

/*
Gets the coefficient of the monomial for the given degree.
*/
double Polynomial::GetCoefficient(int degree) const
{
	return coefficients[degree];
}

/*
Overloads the + operator to allow two polynomials to be added.
*/
Polynomial Polynomial::operator+(Polynomial const& p)
{
	int sumDegree;

	if (p.GetDegree() > GetDegree())
	{
		sumDegree = p.GetDegree();
	}
	else
	{
		sumDegree = GetDegree();
	}

	vector<double> sumCoefficients(sumDegree + 1, 0);

	for (int i = 0;i <= sumDegree;i++)
	{
		if (GetDegree() >= i)
		{
			sumCoefficients[i] += coefficients[i];
		}
		if (p.GetDegree() >= i)
		{
			sumCoefficients[i] += p.coefficients[i];
		}
	}

	return Polynomial(sumCoefficients);
}

/*
Overloads the - operator to allow two polynomials to be subtracted.
*/
Polynomial Polynomial::operator-(Polynomial const& p)
{
	int differenceDegree;

	if (p.GetDegree() > GetDegree())
	{
		differenceDegree = p.GetDegree();
	}
	else
	{
		differenceDegree = GetDegree();
	}

	vector<double> differenceCoefficients(differenceDegree + 1, 0);

	for (int i = 0;i <= differenceDegree;i++)
	{
		if (GetDegree() >= i)
		{
			differenceCoefficients[i] += coefficients[i];
		}
		if (p.GetDegree() >= i)
		{
			differenceCoefficients[i] -= p.coefficients[i];
		}
	}

	return Polynomial(differenceCoefficients);
}

/*
Overloads the * operator to allow two polynomials to be multiplied.
*/
Polynomial Polynomial::operator*(Polynomial const& p)
{
	int productDegree = GetDegree() + p.GetDegree();
	vector<double> productCoefficients(productDegree + 1, 0);

	for (int i = GetDegree();i >= 0;i--)
	{
		for (int j = p.GetDegree();j >= 0;j--)
		{
			productCoefficients[i + j] += GetCoefficient(i) * p.GetCoefficient(j);
		}
	}

	return Polynomial(productCoefficients);
}

/*
Overloads the / operator to allow two polynomials to be divided.
*/
Polynomial Polynomial::operator/(Polynomial const& p)
{
	int quotientDegree = GetDegree() - p.GetDegree();
	vector<double> quotientCoefficients(quotientDegree + 1, 0);

	Polynomial remainder = *this;

	while (remainder.GetDegree() >= p.GetDegree())
	{
		int i = remainder.GetDegree() - p.GetDegree();
		vector<double> quotientPartCoefficient = vector<double>(i + 1, 0);
		quotientPartCoefficient[i] += remainder.GetCoefficient(remainder.GetDegree()) / p.GetCoefficient(p.GetDegree());
		quotientCoefficients[i] += quotientPartCoefficient[i];
		Polynomial product = Polynomial(quotientPartCoefficient) * p;
		remainder = remainder - product;
	}

	return Polynomial(quotientCoefficients);
}

/*
Overloads the << operator to write the polynomial to an output stream.
*/
ostream& operator<<(ostream& out, const Polynomial& p)
{
	bool secondary = false;
	for (int i = p.GetDegree();i >= 0;i--)
	{
		int coefficient = p.GetCoefficient(i);
		if (coefficient != 0)
		{
			if (secondary)
			{
				out << " + ";
			}
			else
			{
				secondary = true;
			}
			out << coefficient;
			if (i > 0)
			{
				out << "x";
				if (i > 1)
				{
					out << "^" << i;
				}
			}
		}
	}
	return out;
}

/*
Constructor.
*/
ComplexNumber::ComplexNumber(double a, double b)
{
	this->a = a;
	this->b = b;
}

/*
Gets the a portion of the number in the format ai + b.
*/
double ComplexNumber::GetA() const
{
	return a;
}

/*
Gets the b portion of the number in the format ai + b.
*/
double ComplexNumber::GetB() const
{
	return b;
}

/*
Gets the conjugate of the complex number.
*/
ComplexNumber ComplexNumber::GetConjugate() const
{
	return ComplexNumber(a * -1, b);
}

/*
Overloads the * operator to allow two complex numbers to be multiplied.
*/
ComplexNumber ComplexNumber::operator*(ComplexNumber const& n)
{
	Polynomial polynomialA(vector<double> { b, a });
	Polynomial polynomialB(vector<double> { n.GetB(), n.GetA() });
	Polynomial product = polynomialA * polynomialB;
	return ComplexNumber(product.GetCoefficient(1), (product.GetCoefficient(2) * -1) + product.GetCoefficient(0));
}

/*
Overloads the / operator to allow two complex numbers to be divided.
*/
ComplexNumber ComplexNumber::operator/(ComplexNumber const& n)
{
	ComplexNumber conjugate = n.GetConjugate();
	ComplexNumber numerator = *this * conjugate;
	double denominator = (conjugate * n).GetB();
	return ComplexNumber(numerator.GetA() / denominator, numerator.GetB() / denominator);
}

/*
Overloads the << operator to write the complex number to an output stream.
*/
ostream& operator<<(ostream& out, const ComplexNumber& n)
{
	out << n.GetA() << "i + " << n.GetB();
	return out;
}
