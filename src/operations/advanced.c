#include <stdio.h>

int mod(int a, int b) {
    if (b == 0) {
        printf("Error: Cannot divide by zero!\n");
        return 0;
    }
    printf("%d\n", a % b);
    return 0;
}

float power(float base, int exp) {
    float result = 1.0;
    for (int i = 0; i < exp; i++) {
        result = result * base;
    }

    printf("%f\n", result);
    return result;
}
