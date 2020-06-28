#include "pch.h"
#include "PolynomialsCli.h"
#include <iostream>
using namespace std;

/*
Allows the user to input a polynomial on the command line.
The parameter is the description, first, second, etc.
*/
Polynomial PolynomialsCli::PolynomialInput(string description)
{
	int degree;
	cout << "Enter the degree (highest exponent) of the" << description << "polynoimial.\n";
	while (!(cin >> degree))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid degree.\n";
	}
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	vector<double> coefficients(degree + 1);
	cout << "Enter the coefficients (x^" << degree << " term first) for the" << description << "polynomial.\n";
	for (int i = degree;i >= 0;i--)
	{
		while (!(cin >> coefficients[i]))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid coefficient.\n";
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return Polynomial(coefficients);
}

/*
Allows the user to input a complex number on the command line.
The parameter is the description, first, second, etc.
*/
ComplexNumber PolynomialsCli::ComplexNumberInput(string description)
{
	int a, b;
	cout << "Enter the coefficients (i term first) for the" << description << "complex number.\n";
	while (!(cin >> a))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid coefficient.\n";
	}
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while (!(cin >> b))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid coefficient.\n";
	}
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return ComplexNumber(a, b);
}

/*
Main function for the polynomials command line application.
*/
int PolynomialsCli::Run()
{
	bool exit = false;

	do
	{
		cout << "Options:\n";
		cout << "1. Add two polynomials.\n";
		cout << "2. Subtract two polynomials.\n";
		cout << "3. Multiply two polynomials.\n";
		cout << "4. Multiply a constant by a polynamial.\n";
		cout << "5. Multiply two complex numbers of the form ai + b.\n";
		cout << "6. Divide two polynomials.\n";
		cout << "7. Divide two complex numbers of the form ai + b.\n";
		cout << "8. Quit.\n";
		int option;
		if (cin >> option)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			switch (option)
			{
			case 1:
			{
				Polynomial p1 = PolynomialInput(" first ");
				Polynomial p2 = PolynomialInput(" second ");
				Polynomial sum = p1 + p2;
				cout << "(" << p1 << ") + (" << p2 << ") = " << sum << "\n\n";
			}
			break;
			case 2:
			{
				Polynomial p1 = PolynomialInput(" first ");
				Polynomial p2 = PolynomialInput(" second ");
				Polynomial difference = p1 - p2;
				cout << "(" << p1 << ") - (" << p2 << ") = " << difference << "\n\n";
			}
			break;
			case 3:
			{
				Polynomial p1 = PolynomialInput(" first ");
				Polynomial p2 = PolynomialInput(" second ");
				Polynomial product = p1 * p2;
				cout << "(" << p1 << ") * (" << p2 << ") = " << product << "\n\n";
			}
			break;
			case 4:
			{
				Polynomial p2 = PolynomialInput(" ");
				cout << "Enter the number by which the polynomial is to be multiplied.\n";
				vector<double> coefficients(1);
				while (!(cin >> coefficients[0]))
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid value.\n";
				}
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				Polynomial p1 = Polynomial(coefficients);
				Polynomial product = p1 * p2;
				cout << p1 << " * (" << p2 << ") = " << product << "\n\n";
			}
			break;
			case 5:
			{
				ComplexNumber n1 = ComplexNumberInput(" first ");
				ComplexNumber n2 = ComplexNumberInput(" second ");
				ComplexNumber product = n1 * n2;
				cout << "(" << n1 << ") * (" << n2 << ") = " << product << "\n\n";
			}
			break;
			case 6:
			{
				Polynomial numerator = PolynomialInput(" dividend ");
				Polynomial denominator = PolynomialInput(" divisor ");
				Polynomial quotient = numerator / denominator;
				cout << "(" << numerator << ") / (" << denominator << ") = " << quotient << "\n\n";
			}
			break;
			case 7:
			{
				ComplexNumber n1 = ComplexNumberInput(" dividend ");
				ComplexNumber n2 = ComplexNumberInput(" divisor ");
				ComplexNumber quotient = n1 / n2;
				cout << "(" << n1 << ") / (" << n2 << ") = " << quotient << "\n\n";
			}
			break;
			case 8:
			{
				exit = true;
				printf("Normal Exit.\n");
			}
			break;
			default:
			{
				printf("Invalid choice.\n");
			}
			break;
			}
		}
		else
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid choice.\n";
		}
	} while (!exit);

	return 0;
}