#include "../include/operations.h"

/* Addition */

double  add(double a,double b)
{
	return a+b;
}
double sub(double a,double b)
{
	return a-b;
}
double mul(double a,double b)
{
	return a*b;
}
double div(double a,double b)
{
	if (b==0)
		return 0;
	return a/b;
}



