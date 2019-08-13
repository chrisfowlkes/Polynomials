// Polynomials.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
/*This program will display a menu of options which the user will be able*/
/*to choose from. Each option will perform a mathematical function with  */
/*polynomials.                                                           */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "..\PolynomialsLib\PolynomialsCli.h"

int main()
{
	PolynomialsCli application = PolynomialsCli();
	return application.Run();
}
