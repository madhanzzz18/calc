#include <stdio.h>
#include "operations.h"

double mod(double a, double b)
{
	if((int)b==0)
	{
		printf("Error: Modulo by zero\n");
		return 0;
	}
	return (int)a%(int)b;
}
double power(double base, int exp)
{
	double result=1.0;
	if(exp<0)
	{
		printf("Error: Negative power not supported\n");
		return 0.0;
	}
	for (int i=0;i<exp;i++)
	{
		result*=base;
	}
	return result;
}

