/*
   Using struct in date functions.
   Johann Roa
   June, 2024
*/
#include<stdio.h>

typedef enum {January, February, March, April, May, June, July, August, September, October, November, December} month;

typedef struct {
    month m;
    short int d;
} date;

date nextday(date *current_date){
    date next_day;
    if (current_date->m == February && current_date->d >= 28){
        next_day.d = 1;
        next_day.m = March;
    } else if (current_date->m == December && current_date->d >= 31){
        next_day.d = 1;
        next_day.m = January;
    } else if ((current_date->m== April || current_date->m== June || current_date->m== September || current_date->m== November) && current_date->d == 30){
        next_day.d = 1;
        next_day.m = current_date->m + 1;
    } else if ((current_date->m== January || current_date->m== March || current_date->m== May || current_date->m== July || current_date->m== August || current_date->m== October) && current_date->d == 31){
        next_day.d = 1;
        next_day.m = current_date->m + 1;
    } else {
        next_day.d = current_date->d + 1;
        next_day.m = current_date->m;
    };

    return next_day;
};

void printday(date date){
    const char *name_month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    printf("The next day is: %d - %s\n", date.d, name_month[date.m]);
}

int main(){
    date today_1 = {February, 28};
    date tomorrow_1;
    date today_2 = {March, 14};
    date tomorrow_2;
    date today_3 = {October, 31};
    date tomorrow_3;
    date today_4 = {December, 31};
    date tomorrow_4;
    tomorrow_1 = nextday(&today_1);
    printday(tomorrow_1);
    tomorrow_2 = nextday(&today_2);
    printday(tomorrow_2);
    tomorrow_3 = nextday(&today_3);
    printday(tomorrow_3);
    tomorrow_4 = nextday(&today_4);
    printday(tomorrow_4);
    return 0;
};