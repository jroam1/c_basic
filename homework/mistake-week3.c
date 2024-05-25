/*
    Debugging the sine function program
    Johann Roa
    January, 2024
*/

#include <stdio.h>
#include <math.h> /* has  sin(), abs(), and fabs() */

int main(void)
{
    double interval;
    int i;
    for (i = 0; i < 30; i++)
    {
        /*
            The abs() function in math library only allows integer values.
            We need double values in the return of the function, so we use
            the fabs() function instead.
        */ 

        interval = i / 10.0;
        printf("sin(% lf) = % lf \t", interval, fabs(sin(interval)));
    }

    printf("\n++ +++++\n");
    return 0;
}