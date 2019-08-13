#pragma once
#include "PolynomialsLib.h"

/*
Command line interface for the polynomials application.
*/
class PolynomialsCli
{
private:
	/*
	Allows the user to input a polynomial on the command line.
	The parameter is the description, first, second, etc.
	*/
	Polynomial PolynomialInput(string description);
	/*
	Allows the user to input a complex number on the command line.
	The parameter is the description, first, second, etc.
	*/
	ComplexNumber ComplexNumberInput(string description);
public:
	/*
	Main function for the polynomials command line application.
	*/
	int Run();
};

