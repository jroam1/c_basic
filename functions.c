#include <stdio.h>

char cube(double x){
    double result;
    result = x*x*x;
    return result;
}

int main(void){
    int a=1, b=2, c=3;
    int i=0, j=1, k=2;
    printf("%i\n", cube(2.2));
    printf("%d", (i&&(j=k))||(k>j));
    return 0;
}