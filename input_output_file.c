/*
    Use of FILE I/O
    Command line arguments
    Double space input file to output file

    Se lee un archivo que contiene solamente numeros enteros
    y se crea un nuevo archivo en el que se agrega un cambio de línea
    más "\n" cada vez que hay un cambio de línea, así resulta un 
    archivo doblemente espaciado en el sentido vertical.

    June, 2024
*/

#include <stdio.h>
#include <stdlib.h>

void print_file(FILE *fptr){
    int c;
    rewind(fptr); // Ajusta el indicador de posición del archivo en el inicio del mismo
    // En este caso nos aseguramos que el puntero al archivo este ajustado al comienzo del 
    // archivo antes de leer su contenido.
    while ((c=getc(fptr))!= EOF)
        putc(c, stdout); // Esta función escribe un caracter en la salida indicada en el segundo parametro
        // En este caso, se escribe el caracter leído en la salida estándar de la consola --stdout
};

void double_space(FILE *ifp, FILE *ofp){
    int c;
    rewind(ifp);
    while ((c = getc(ifp))!= EOF){
        putc(c, ofp);
        if (c == '\n')
            putc('\n', ofp); 
            // En este caso se escribe el caracter en el archivo de salida 
    };
};

int main(int argc, char *argv[]){
    // Definimos main de modo que acepte comandos de línea
    FILE *ifp, *ofp;

    //De esta forma limitamos el número de comandos que recibe el programa
    if (argc != 3){
        printf("Need executable inputfile outputfile\n");
        exit(1);
    };

    // Hace falta una validación para tipificar los comandos recibidos

    ifp = fopen(argv[1], "r+");
    ofp = fopen(argv[2], "w+");
    printf("My %s file as read is \n\n", argv[1]);
    print_file(ifp);
    printf("\n\n");
    double_space(ifp, ofp);
    printf("My %s file double spaced is\n\n", argv[2]);
    print_file(ofp);
    printf("\n\n");
    fclose(ifp);
    fclose(ofp);

    return 0;
}