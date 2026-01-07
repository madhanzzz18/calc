#include <string.h> 
#include <stdio.h>
#include "operations.h"  
#include "calculator.h" 
#include "advanced.h"

double perform_operation(const char *op_name, double a, double b) { 
    if (strcmp(op_name, "add") == 0) {
        return add(a, b);
    }
    else if (strcmp(op_name, "sub") == 0) {
        return sub(a, b);
    }
    else if (strcmp(op_name, "mul") == 0) {
        return mul(a, b);
    }
    else if (strcmp(op_name, "div") == 0) {
        return div(a, b);
    }
    else if (strcmp(op_name,"power")==0){
        return (double)power((float)a,(int)b);
    }
    else if(strcmp(op_name,"mod")==0){
        return (double)mod((int)a,(int)b);
    }
    else {
        printf("Error: Unknown operation '%s'\n", op_name);
        return 0.0;
    }
}
