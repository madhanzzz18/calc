#include<stdio.h>
#include"calculator.h"
int main(){
	printf("===== CALCULATOR MENU =====\n");
	printf("1. Add\n");
	printf("2. Subtract\n");
	printf("3. Multiply\n");
	printf("4. Divide\n");
	printf("5. Modulo\n");
	printf("6. Power\n");
	printf("===========================\n");
	int option;
    	printf("Enter your choice: ");
	if (scanf("%d", &option) != 1)
    	{
        	printf("Invalid input. Please enter a number.\n");
        	return 0;
    	}
	if (option < 1 || option > 6)
	{
        	printf("Invalid option. Choose between 1 and 6.\n");
        	return 0;
    	}
	double a, b;
    	printf("Enter two numbers: ");
   	if (scanf("%lf %lf", &a, &b) != 2)
    	{
        	printf("Invalid input. Please enter numbers only.\n");
        	return 0;
    	}
    	if (option == 4 && b == 0)
    	{
        	printf("Error: Division by zero is not allowed.\n");
        	return 0;
    	}
    	if (option == 5 && b == 0)
    	{
        	printf("Error: Modulo by zero is not allowed.\n");
        	return 0;
    	}
    	if (option == 6 && b < 0)
    	{
        	printf("Error: Power with negative exponent is not allowed.\n");
        	return 0;
    	}
	return 0;
}

