/*
   Programm that prints the sine function for a input between 0 and 1
   Johann Roa
   December, 2023
*/

#include <stdio.h>
#include <math.h>

int main(void) {
    double x;
    printf("Enter value to evaluate sin function (only in the range (0,1)):\n");
    scanf("%lf", &x);
    // We validate the input value
    (x<=0 || x>=1) ? printf("Input value is not valid. Out of range (0,1)!!!\n") : printf("Sin(%lf) = %lf\n", x, sin(x));
    return 0;
}