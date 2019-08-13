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

/*This function creates the menu.                                        */
void menu()
{
	printf("Options:\n\n");
	printf("1. Add two first-degree polynomials of the form ax + b.\n");
	printf("2. Subtract two first-degree polynomials of the form ax + b.\n");
	printf("3. Multiply two first-degree polynomials of the form ax + b.\n");
	printf("4. Multiply a constant by a first-degree polynamial of the");
	printf(" form ax + b.\n");
	printf("5. Multiply two complex numbers of the form ai + b.\n");
	printf("6. Divide two first-degree polynomials of the form ax + b.\n");
	printf("7. Divide two complex numbers of the form ai + x.\n");
	printf("8. Quit.\n\n");
}

/*This function executes the input statements for options 1, 2, 3, and 6.*/
void input1(int *r1, int *s1, int *r2, int *s2)
{
	printf("Enter the coefficients (x term first) for the first polynomial.");
	scanf_s("%d%d", r1, s1);
	printf("\nEnter the coefficients (x term first) for the second ");
	printf("polynomial.");
	scanf_s("%d%d", r2, s2);
	printf("\n");
}

/*This function executes the input statements for option 4.              */
void input2(int *r1, int *s1, int *t)
{
	printf("Enter the coefficients (x term first) for the first polynomial.");
	scanf_s("%d%d", r1, s1);
	printf("\nEnter the number by which the polynomial is to be multiplied.");
	scanf_s("%d", t);
	printf("\n");
}

/*This function executes the input statements for options 5 and 7.       */
void input3(int *r1, int *s1, int *r2, int *s2)
{
	printf("Enter the coefficients (i term first) for the first polynomial.");
	scanf_s("%d%d", r1, s1);
	printf("\nEnter the coefficients (i term first) for the second ");
	printf("polynomial.");
	scanf_s("%d%d", r2, s2);
	printf("\n");
}

/*This function executes option 1.                                       */
void funcone(int x1, int y1, int x2, int y2, int *a, int *b)
{
	*a = x1 + x2;
	*b = y1 + y2;
}

/*This function executes option 2.                                       */
void functwo(int x1, int y1, int x2, int y2, int *a, int *b)
{
	*a = x1 - x2;
	*b = y1 - y2;
}

/*This function executes option 3.                                       */
void functhree(int x1, int y1, int x2, int y2, int *a, int *b, int *c)
{
	*a = x1 * x2;
	*b = x1 * y2 + x2 * y1;
	*c = y1 * y2;
}

/*This function executes option 4.                                       */
void funcfour(int x, int y, int c, int *a, int *b)
{
	*a = c * x;
	*b = c * y;
}

/*This function executes option 5.                                       */
void funcfive(int x1, int y1, int x2, int y2, int *a, int *b)
{
	*a = x1 * y2 + x2 * y1;
	*b = (y1 * y2) - (x1 * x2);
}

/*This function executes option 6.                                       */
void funcsix(int x1, int y1, int x2, int y2, float *a, float *d1, float *d2)
{
	float X1, Y1, X2, Y2, num;
	X1 = x1;
	Y1 = y1;
	X2 = x2;
	Y2 = y2;
	*a = X1 / X2;
	num = Y1 - (*a * Y2);
	*d1 = X2 / num;
	*d2 = Y2 / num;
	printf("%.4f %.4f %.4f", *a, *d1, *d2);
}

/*This function executes option 7.                                       */
void funcseven(int x1, int y1, int x2, int y2, float *a, float *b)
{
	float num1, num2, den;
	num1 = (x1 * -1 * y2) + (x2 * y1);
	num2 = (-1 * x1 * x2) + (y1 * -1 * y2);
	den = (-1 * x2 * x2) + (-1 * y2 * y2);
	*a = num1 / den;
	*b = num2 / den;
}

int main()
{
	PolynomialsCli application = PolynomialsCli();
	return application.Run();
}

int main2()
{
	int x1, y1, x2, y2, x3, y3, z3, c, opt, exit;
	float X3, Y3, c1;
	exit = 0;
	while (exit == 0)
	{
		menu();
		scanf_s("%d", &opt);
		switch (opt)
		{
		case 1:
		{
			input1(&x1, &y1, &x2, &y2);
			funcone(x1, y1, x2, y2, &x3, &y3);
			printf("(%dx + %d) + (%dx + %d) = %dx + %d\n", x1, y1, x2, y2, x3, y3);
		}
		break;
		case 2:
		{
			input1(&x1, &y1, &x2, &y2);
			functwo(x1, y1, x2, y2, &x3, &y3);
			printf("(%dx + %d) - (%dx + %d) = %dx + %d\n", x1, y1, x2, y2, x3, y3);
		}
		break;
		case 3:
		{
			input1(&x1, &y1, &x2, &y2);
			functhree(x1, y1, x2, y2, &x3, &y3, &z3);
			printf("(%dx + %d) * (%dx + %d) =", x1, y1, x2, y2);
			printf(" %dx^2 + %dx + %d\n", x3, y3, z3);
		}
		break;
		case 4:
		{
			input2(&x1, &y1, &c);
			funcfour(x1, y1, c, &x2, &y2);
			printf("%d * (%dx + %d) = %dx + %d\n", c, x1, y1, x2, y2);
		}
		break;
		case 5:
		{
			input3(&x1, &y1, &x2, &y2);
			funcfive(x1, y1, x2, y2, &x3, &y3);
			printf("(%di + %d) * (%di + %d) = %di + %d\n", x1, y1, x2, y2, x3, y3);
		}
		break;
		case 6:
		{
			input1(&x1, &y1, &x2, &y2);
			funcsix(x1, y1, x2, y2, &c1, &X3, &Y3);
			printf("(%dx + %d) / (%dx + %d) =", x1, y1, x2, y2);
			printf(" %.4f + 1 / (%.4fx + %.4f)\n", c1, X3, Y3);
		}
		break;
		case 7:
		{
			input3(&x1, &y1, &x2, &y2);
			funcseven(x1, y1, x2, y2, &X3, &Y3);
			printf("(%di + %d) / (%di + %d) = %.4fi + %.4f\n", x1, y1, x2, y2, X3, Y3);
		}
		break;
		case 8:
		{
			exit = 1;
			printf("Normal Exit.");
		}
		break;
		default:
		{
			printf("Invalid choice.");
		}
		break;
		}
	}
	return 0;
}
