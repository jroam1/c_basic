#include <stdio.h>

long int factorial_iterative(int n){
    long f = 1;
    int i;

    for (i=1; i<=n; i++)
        f = f *i;

    return f;
};

long int factorial_recursive(int n){
    if (n==1){
        return 1;
    } else {
        return (factorial_recursive(n-1)*n);
    }
};

int main(void){
    int how_many = 0, i;
    printf("I want table of factorial up to n:");

    scanf("%d", &how_many);
    printf("\n factorials\n\n");

    printf("Iterative method:\n");
    for (i = 1; i <= how_many; i++)
        printf("\n%d\t %ld\n", i, factorial_iterative(i));
    printf("\n\n");
    printf("Recursive method:\n");
    for (i = 1; i <= how_many; i++)
        printf("\n%d\t %ld\n", i, factorial_recursive(i));
    printf("\n\n");
    return 0;
};