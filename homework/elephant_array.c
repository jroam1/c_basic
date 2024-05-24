/*
    Average from raw data usingn array
    Johann Roa
    May, 2024
*/

#include <stdio.h>
#define MAX_SIZE 1000

int array[MAX_SIZE];
int count = 0;

int read_data_from_file(char *str){
    FILE *file_pointer;


    // Open the file in read mode
    file_pointer = fopen(str, "r");

    // Check the state of the file
    if (file_pointer == NULL){
        printf("File could not be opened.");
        return 1;
    }

    // Read the file and store the data in the array
    while (fscanf(file_pointer, "%d", &array[count]) != EOF && count < MAX_SIZE)
        count++;

    // Close the file
    fclose(file_pointer);
};

double average_data(int data[], int size){
    int j;
    double sum = 0.0;
    double average = 0.0;

    for (j=0; j<size; j++){
        sum = sum + array[j];
    };

    // Calculate the average
    average = sum/size;

    return average;
};


int main(void){
    int i;
    double average_weight_elephant_seals = 0.0;

    read_data_from_file("data.txt");

    average_weight_elephant_seals = average_data(array, MAX_SIZE);
    printf("\nThe average weight for a population of elephant seals is: %lf\n", average_weight_elephant_seals);
   
    return 0;
}
