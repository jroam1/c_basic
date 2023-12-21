/*
   Learning to mix float and int operations. Formatting and printing types.
   Johann Roa
   December, 2023
*/

#include <stdio.h>
#define PI 3.14159

int main(void)
{
    double radius;
    printf("Enter radius :");
    scanf("%lf", &radius);
    printf("Volume is : %lf \n\n", 4 * radius * radius * radius * PI / 3.0);
    return 0;
}