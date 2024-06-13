/*
    Uso de estructuras dentro de funciones.
    May, 2024
*/

#include <stdio.h>

struct Point {
    int x;
    int y;
};


struct Point makepoint(int x, int y){
    /*
        Función que retorna una instancia de una estructura.
    */
    struct Point temp;

    temp.x = x;
    temp.y = y;

    return temp;
};

struct Point addpoint(struct Point p1, struct Point p2){
    /*
        Función que toma por argumento dos estructuras por copia
        y retorna una tercer estructura.
    */
   p1.x += p2.x;
   p1.y += p2.y;

   return p1;
};

void movepoint(struct Point *p, struct Point delta_p){
    /*
        Función que toma por argumento una estructura por referencia,
        otra estructura por copia, modificando la primera con la 
        información de la segunda.
    */
    p->x+=delta_p.x;
    p->y+=delta_p.y;
};

int main(void){
    struct Point middle;
    struct Point p1 = {45,89};
    struct Point p2 = {89,-96};
    struct Point p3;
    struct Point p4 = {12, 89};
    struct Point delta_p4 = {5,-9};
    
    middle = makepoint(4, 20);
    // Primera forma de funciones con estructuras: pasar los miembros como argumento
    printf("\nLos miembros de middle: %d, %d\n", middle.x, middle.y);
    
    // Segunda forma de funciones con estructuras: pasar por copia
    printf("\nLos miembros de p1 (antes de la función): %d, %d\n", p1.x, p1.y);
    printf("\nLos miembros de p2 (antes de la función): %d, %d\n", p2.x, p2.y);
    p3 = addpoint(p1, p2);
    printf("\nLos miembros de p3: %d, %d\n", p3.x, p3.y);
    printf("\nLos miembros de p1 (despues de la función): %d, %d\n", p1.x, p1.y);
    printf("\nLos miembros de p2 (despues de la función): %d, %d\n", p2.x, p2.y);

    // Tercera forma de funciones con estructuras: pasar por referencia
    printf("\nLos miembros de p4 (antes de la función): %d, %d\n", p4.x, p4.y);
    printf("\nLos miembros de delta_p4 (antes de la función): %d, %d\n", delta_p4.x, delta_p4.y);
    movepoint(&p4, delta_p4);
    printf("\nLos miembros de p4 (despues de la función): %d, %d\n", p4.x, p4.y);
    printf("\nLos miembros de p2 (despues de la función): %d, %d\n", delta_p4.x, delta_p4.y);
    return 0;
};

