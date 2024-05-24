/*
    Ejemplos de uso de estructuras y punteros a estructuras en C
    May, 2024
*/

#include <stdio.h>
#include <string.h>

struct Person 
{
    char name[50];
    int age;
    float height;
};

int main(void) {
    char name_1[50] = "Johann";
    char name_2[50] = "Violeta";

    struct Person person_1 = {"John", 30, 75.2}; // Declaración e inicialización de una estructura
    struct Person *pointer_person = &person_1;  // Declaración e inicialización de un puntero a person_1
    
    // Modificamos los miembros directamente:
    /*
        Tuvimos que usar la funcion strcpy de C para poder asignar los nuevos nombres al miembro name
        debido a que C no permite asignar una cadena a un arreglo directamente ni asignar un arreglo a otro
        arreglo:
    
        person_1.name = name_1;
        person_1.name = "Violeta";
    
    */ 
    strcpy(person_1.name, "Violeta");
    person_1.age = 28;
    // Revisamos los nuevos valores:
    printf("\nNuevo nombre:%s\n", person_1.name);
    printf("\nNueva edad:%d\n", person_1.age);

    // Modificamos los miembros a través del puntero:
    strcpy(pointer_person->name,"Johann");
    pointer_person->age = 29; 
    // Revisamos los nuevos valores:
    printf("\nNuevo nombre:%s\n", pointer_person->name);
    printf("\nNueva edad:%d\n", pointer_person->age);

    return 0;
};