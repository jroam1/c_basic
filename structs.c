/*
    Ejemplos de uso de estructuras y punteros a estructuras en C
    May, 2024
*/

#include <stdio.h>
#include <string.h>
#define MAX_KEYS 3
struct Person 
{
    char name[50];
    int age;
    float height;
};

struct key {
    char *word;
    int count;
};


int main(void) {
    char name_1[50] = "Johann";
    char name_2[50] = "Violeta";
    char *name_3;

    struct Person person_1 = {"John", 30, 75.2}; // Declaración e inicialización de una estructura
    struct Person *pointer_person = &person_1;  // Declaración e inicialización de un puntero a person_1
    struct key keytab[MAX_KEYS] = {  // Declaración e inicialización de un arreglo de estructuras
        {"auto", 0},
        {"break", 1},
        {"case", 2}
    };  
    
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

    // Veamos que es equivalente usar el operador de desreferencia 
    // para modificar directamente los datos:
    (*pointer_person).age = 30;
    printf("\nRetornamos los dos valores directamente, %d - %d\n", person_1.age, (*pointer_person).age);
    

    /*
        El cambio de valores en el nombre podría hacerse de forma más directa si se
        declara name como puntero a char y los nombres se declaran como arreglos, 
        como name_3 y name_1 respectivamente.
    */
    name_3 = name_1;
    printf("\nEjemplo de asignación %s\n", name_3);

    for (int i=0; i<MAX_KEYS; i++){
        printf("\nEl contenido de cada elemento:{%s, %d}\n", keytab[i].word, keytab[i].count);
    }

    return 0;
};