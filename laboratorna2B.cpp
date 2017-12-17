// laboratorna2B.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "stdio.h"
#include "math.h"

int factorial(int n)
{
	int i;
	for (i = n - 1; i > 0; i--)
		n *= i;
	return(n == 0) ? 1: n;
}


int main()
{
	double a, b, d, h, x, result;
	int n;

	printf("a=");
	scanf_s("%lf", &a);

	printf("b=");
	scanf_s("%lf", &b);

	printf("h=");
	scanf_s("%lf", &h);

	printf("d=");
	scanf_s("%lf", &d);

	double sum = 0;
	int m = 3;
	for (x = a; x <= b; x += h)
	{
		n = 1;
		sum = 0;
		result = 0;
		while (sum <= d)
		{
			if (x == 0)
				break;
			int argument = (m + n - 1);
			sum = factorial(argument) / factorial(n)*pow(x, n);
			result = sum + result;
			n++;
		}
		result += 1;
		printf("For %.2lf, the result = %.1lf\n", x, result);

	}
		scanf_s("%lf");
	return 0;

}

