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
    int mode,i=1;
    while(i==1){
        printf("----MAIN MENu----\n");
        printf("[1] menu driven \n[2] EXIT\n");
        scanf("%d", &mode);
        if (mode !=1 && mode !=2){
            printf("invalid input");
            while (getchar() !='\n');
            continue;
        }

        else if (mode==1){
            menu_driven();
        }
        /* else if(mode ==2){ */
        /*     CLI(argc,argv); */
        /* } */
        else if(mode ==2){
            i=0;
            
        }       
    }
}

int menu_driven(){
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
        if (option==1){
            perform_operation("add",a,b);
        }
        if (option ==2 ){
            perform_operation("sub",a,b);

        }
        if (option ==3){
            perform_operation("mul",a,b);
        }
        if (option ==4 ){
            perform_operation("div",a,b);
        }
        if (option==5){
            perform_operation("mod",a,b);
        }
        if (option==6){
            perform_operation("power",a,b);
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

int CLI(int argc, char *argv[])
{
    double a, b, result;
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
        result = div(a, b);
    
    }
    else if (strcmp(argv[1], "mod") == 0) {
        if (b == 0) {
            printf("Error: Modulus by zero\n");
            return 1;
        }
        result = mod(a, b);
    }

    else if (strcmp(argv[1], "pow") == 0){
        result = power(a, b);
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
