#include <vector>
#include <ostream>
using namespace std;
/*
Represents a polynomial in the format ax + b.
*/
class Polynomial
{
private:
	/*
	The coefficients in the equation.
	*/
	vector<double> coefficients;
public:
	/*
	Constructor. Takes the coefficients of the polynomial. The
	coefficients should be at the index of their variables
	exponent. For example, 4x^3 + 2x^2 - 7 would be passed in as
	Polynomial(int[4]{7, 0, 2, 4}, 3).
	*/
	Polynomial(vector<double> coefficients);
	/*
	Gets the degree of the polynomial, or the highest eponent of the polynomial.
	*/
	int GetDegree() const;
	/*
	Gets the coefficient of the monomial for the given degree.
	*/
	double GetCoefficient(int degree) const;
	/*
	Overloads the + operator to allow two polynomials to be added.
	*/
	Polynomial operator + (Polynomial const& p);
	/*
	Overloads the - operator to allow two polynomials to be subtracted.
	*/
	Polynomial operator - (Polynomial const& p);
	/*
	Overloads the * operator to allow two polynomials to be multiplied.
	*/
	Polynomial operator * (Polynomial const& p);
	/*
	Overloads the / operator to allow two polynomials to be divided.
	*/
	Polynomial operator / (Polynomial const& p);
	/*
	Overloads the << operator to write the polynomial to an output stream.
	*/
	friend ostream& operator<<(ostream& out, const Polynomial& p);
};

/*
Represents a complex number in the form ai + b.
*/
class ComplexNumber
{
private:
	double a, b;
public:
	/*
	Constructor.
	*/
	ComplexNumber(double a, double b);
	/*
	Gets the a portion of the number in the format ai + b.
	*/
	double GetA() const;
	/*
	Gets the b portion of the number in the format ai + b.
	*/
	double GetB() const;
	/*
	Gets the conjugate of the complex number.
	*/
	ComplexNumber GetConjugate() const;
	/*
	Overloads the * operator to allow two comple numbers to be multiplied.
	*/
	ComplexNumber operator * (ComplexNumber const& n);
	/*
	Overloads the / operator to allow two complex numbers to be divided.
	*/
	ComplexNumber operator / (ComplexNumber const& n);
	/*
	Overloads the << operator to write the complex number to an output stream.
	*/
	friend ostream& operator<<(ostream& out, const ComplexNumber& n);
};
