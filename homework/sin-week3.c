/*
   Programm that prints the sine and cosine functions for a range values between 0 and 1
   Johann Roa
   January, 2024
*/

#include <stdio.h>
#include <math.h>

int main(void) {
    double x=0.1;
    double tolerance = 0.0000001;  
    // I add a tolerance to avoid the evaluation of 1.0 due to rounding errors
    while (x<1.0 - tolerance) {
        (x<=0 || x>=1.0) ? printf("Input value is not valid. Out of range (0,1)!!!\n") : printf(" Sin(%lf) = %lf | Cos(%lf) = %lf\n", x, sin(x), x, cos(x));
        printf("-----------------------------------------------------\n");
        x+=0.1;
    }
    return 0;
}