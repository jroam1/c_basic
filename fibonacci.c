#include <stdio.h>

long fibonacci_iterative(int n){
    long f2=0, f1=1, f_old;
    int i;

    for (i=0; i<n; i++){
        f_old = f2;
        f2 = f2 + f1;
        f1 = f_old;
    };
    return f2;
};

long fibonacci_recursive(int n){
    if (n<=1)
        return n;
    else
        return (fibonacci_recursive(n-1) + fibonacci_recursive(n-2));
};

int main(void) {
    int how_many = 0, i;
    printf("I want table of fibonacci up to n:");

    scanf("%d", &how_many);
    printf("\n Fibonacci \n");

    for (i=0; i<how_many; i++){
        printf("\n%d\t %ld %ld\n", i, fibonacci_iterative(i), fibonacci_recursive(i));
    };
}