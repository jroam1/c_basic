/*
    Detalles particulares de los loop en C
    January, 2024
*/

#include <stdio.h>

int main (void) {
    int i;
    int n;
    // Ciclo infinito, no cambia el índice nunca y no se inicializa i
    // for (;i<=10;) {
    //     printf("Este es el índice %d \n", i);
    // };

    /*
        Ciclo normal. El riesgo esta en que no se puede garantizar el valor que toma i, 
        parece inicializar en cero, pero hay un riesgo latente de que empiece con otro valor, 
        depende del compilador en todo caso.
    */ 
    // for (;i<=10;i++) {
    //     printf("Este es el índice %d \n", i);
    // };

    // Ciclo infinito, no cambia el índice nunca
    // for (i=1;i<=10;) {
    //     printf("Este es el índice %d \n", i);
    // };

    // Ciclo infinito, se inicializa el índice y cambia su valor pero no hay criterio de parada
    // for (i=0;;i++){
    //     printf("Este es el índice %d \n", i);
    // };

    //Ciclo infinito, el índice no cambia y tampoco se inicializa. Puede ser útil pero sería más compacto un while
    // for (;;) {
    //     printf("Este es el índice %d \n", i);
    // };

    //Ciclo normal, se inicializa el índice, cambia y se define un criterio de parada
    for (i=0; i<=10; i++){
        printf("Este es el índice %d \n", i);
    };

    n = (1<2);
    printf("Este es el valor de n: %d \n", n);

    return 0;
}