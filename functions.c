#include <stdio.h>

char cube(double x){
    double result;
    result = x*x*x;
    return result;
}

int main(void){
    printf("%i", cube(2.2));
    return 0;
}