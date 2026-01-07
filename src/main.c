#include <stdio.h>
#include <string.h>
#include "operations.h" 
#include"calculator.h"
#include"advanced.h"
int menu_driven();
int CLI(int argc, char *argv[]);
int main(int argc, char *argv[]){
	if (argc == 4) {
		CLI(argc, argv);
		return 0; 
	}

	if (argc > 1 && argc != 4) {
		printf("Invalid arguments.\nUsage: %s <op> <num1> <num2>\n", argv[0]);
		return 1;
	}
	int mode;
	while (1) {
		printf("\n===== MAIN MENU =====\n");
		printf("1. Open Calculator Menu \n");
		printf("2. Exit Calculator\n");
		printf("Select mode: ");

		if (scanf("%d", &mode) != 1 || (mode != 1 && mode != 2)) {
			printf("Error: Please enter 1 or 2 only!\n");
			while (getchar() != '\n');
			continue;
		}

		if (mode == 2) {
			printf("Exiting...\n");
			break;
		}

		menu_driven();
	}

	return 0;
}

int menu_driven() {
	int option;
	double a, b, result = 0.0;
	const char *op = NULL;

	printf("\n===== SIMPLE CALCULATOR =====\n");
	printf("[1] Addition\n[2] Subtraction\n[3] Multiplication\n[4] Division\n[5] Modulo\n[6] Power\n");
	printf("=============================\n");
	printf("Enter option (1-6): ");

	if (scanf("%d", &option) != 1) {
		printf("Invalid input!Enter Number only.\n");
		while (getchar() != '\n');
		return 0;
	}

	if (option < 1 || option > 6) {
		printf("Invalid option! Choose between 1 and 6.\n");
		return 0;
	}

	printf("Enter two values: ");
	if (scanf("%lf %lf", &a, &b) != 2) {
		printf("Invalid number input!\n");
		while (getchar() != '\n');
		return 0;
	}

	if (option == 4 && b == 0) {
		printf("Math Error: Cannot divide by zero!\n");
		return 0;
	}
	if (option == 5 && b == 0) {
		printf("Math Error: Modulo by zero is invalid!\n");
		return 0;
	}
	if (option == 6 && b < 0) {
		printf("Math Error: Exponent must be positive!\n");
		return 0;
	}

	switch(option) {
		case 1: op = "add"; break;
		case 2: op = "sub"; break;
		case 3: op = "mul"; break;
		case 4: op = "div"; break;
		case 5: op = "mod"; break;
		case 6: op = "power"; break;
	}
	result = perform_operation(op, a, b);
	return 0;
}

int CLI(int argc, char *argv[])
{
	double a, b;
	/* if (argc != 4) */
	/* { */
	/*     printf("Usage: %s <add|sub|mul|div> <num1> <num2>\n", argv[0]); */
	/*     return 1; */
	/* } */

	if (sscanf(argv[2], "%lf", &a) != 1 ||
			sscanf(argv[3], "%lf", &b) != 1)
	{
		printf("Error: Invalid number\n");
		return 1;
	}

	if (strcmp(argv[1], "add") == 0)
		add(a, b);
	else if (strcmp(argv[1], "sub") == 0)
		sub(a, b);
	else if (strcmp(argv[1], "mul") == 0)
		mul(a, b);
	else if (strcmp(argv[1], "div") == 0)
	{
		if (b == 0)
		{
			printf("Error: Division by zero\n");
			return 1;
		}
		div(a, b);

	}
	else if (strcmp(argv[1], "mod") == 0) {
		if (b == 0) {
			printf("Error: Modulus by zero\n");
			return 1;
		}
		mod(a, b);
	}

	else if (strcmp(argv[1], "pow") == 0){
		power(a, b);
		return 1;
	}
	else
	{
		printf("Error: Invalid operation\n");
		return 1;
	}

	/* printf("Result: %.2f\n", result); */
	return 0;
}
