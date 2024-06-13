/*
    Exercise Week 4:
    Read a list of Int from a file
    convert into rational array and 
    calculate the average.
    Includes rational basic operations.
    Johann Roa
    June, 2024
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_NINT 1000

typedef struct {
    long int numerator;
    long int denominator;
} ration;

ration rational_sum(ration a, ration b){
    ration *c = (ration *)malloc(sizeof(ration));

    if (a.denominator == 0 || b.denominator == 0){
        printf("Error: Denominator cannot be zero");
        exit(1);
    } else {
        c->numerator = (a.numerator*b.denominator) + (b.numerator*a.denominator);
        c->denominator = a.denominator*b.denominator;
    }
    return *c; 
};

ration rational_subt(ration a, ration b){
    ration *c = (ration *)malloc(sizeof(ration));

    if (a.denominator == 0 || b.denominator == 0){
        printf("Error: Denominator cannot be zero");
        exit(1);
    } else {
        c->numerator = (a.numerator*b.denominator) - (b.numerator*a.denominator);
        c->denominator = a.denominator*b.denominator;
    }
    return *c; 
};

ration rational_prod(ration a, ration b){
    ration *c = (ration *)malloc(sizeof(ration));

    if (a.denominator == 0 || b.denominator == 0){
        printf("Error: Denominator cannot be zero");
        exit(1);
    } else {
        c->numerator = a.numerator*b.numerator;
        c->denominator = a.denominator*b.denominator;
    }
    return *c; 
};

ration rational_div(ration a, ration b){
    ration *c = (ration *)malloc(sizeof(ration));

    if (a.denominator == 0 || b.denominator == 0){
        printf("Error: Denominator cannot be zero");
        exit(1);
    } else {
        c->numerator = a.numerator*b.denominator;
        c->denominator = a.denominator*b.numerator;
    }
    return *c; 
};

void read_data(FILE *ptr, int d[], int *size, int *r_size){
    *size = 0;
    while (fscanf(ptr, "%d", &d[*size])==1)
        (*size)++;
    *r_size = d[0];
};

void rational_array(ration r[], int r_size, int d[], int d_size){
    ration *new_ration = (ration *)malloc(sizeof(ration));
    int j=0;
    for (int i=1; i<d_size; i+=2){ 
        new_ration->numerator = d[i];
        new_ration->denominator = d[i+1];
        r[j] = *new_ration; 
        j+=1;
    };
};

ration rational_average(ration r[], int r_size){
    ration *sum = (ration *)malloc(sizeof(ration));
    ration *size = (ration *)malloc(sizeof(ration));
    ration *avg = (ration *)malloc(sizeof(ration));
    
    // Initialize the ration form of sum and size
    sum->numerator = (long int)0;
    sum->denominator = (long int)1;
    size->numerator = (long int)r_size;
    size->denominator = (long int)1;
    
    for (int i=0; i<r_size; i++){
        *sum = rational_sum(*sum, r[i]); 
    };

    // Calculate the average using the rational_div function
    *avg = rational_div(*sum, *size);
    return *avg;
};

int main(int argc, char *argv[]){
    int r_sz, sz = MAX_NINT;
    FILE *ifp;
    int data[MAX_NINT];
    ration average;

    if (argc != 2){
        printf("Need executable inputfile. Invalid options.\n");
        exit(1);
    };

    ifp = fopen(argv[1], "r");
    read_data(ifp, data, &sz, &r_sz);
    ration r[r_sz];
    rational_array(r, r_sz, data, sz);
    average = rational_average(r, r_sz);
    // ration a = {1,2};
    // ration b = {1,3};
    // ration c;
    // c = rational_sum(a,b);
    // printf("c = a + b = %d/%d\n", c.numerator, c.denominator);
    // c = rational_subt(a,b);
    // printf("c = a - b = %d/%d\n", c.numerator, c.denominator);
    // c = rational_prod(a,b);
    // printf("c = a * b = %d/%d\n", c.numerator, c.denominator);
    // c = rational_div(a,b);
    // printf("c = a / b = %d/%d\n", c.numerator, c.denominator);
    printf("The average of the list in rational form is (without simplification): %ld/%ld\n", average.numerator, average.denominator);
    printf("The average of the list in decimal form is: %lf\n", average.numerator/(double)average.denominator);
    return 0;
};