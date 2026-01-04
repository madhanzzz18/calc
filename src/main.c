#include <stdio.h>
#include <string.h>
#include "operations.h" 
int main(int argc, char *argv[])
{
    double a, b, result;

    if (argc != 4)
    {
        printf("Usage: %s <add|sub|mul|div> <num1> <num2>\n", argv[0]);
        return 1;
    }

    if (sscanf(argv[2], "%lf", &a) != 1 ||
        sscanf(argv[3], "%lf", &b) != 1)
    {
        printf("Error: Invalid number\n");
        return 1;
    }

    if (strcmp(argv[1], "add") == 0)
        result = add(a, b);
    else if (strcmp(argv[1], "sub") == 0)
        result = sub(a, b);
    else if (strcmp(argv[1], "mul") == 0)
        result = mul(a, b);
    else if (strcmp(argv[1], "div") == 0)
    {
        if (b == 0)
        {
            printf("Error: Division by zero\n");
            return 1;
        }
        result = divide(a, b);
    }
    else
    {
        printf("Error: Invalid operation\n");
        return 1;
    }

    printf("Result: %.2f\n", result);
    return 0;
}

