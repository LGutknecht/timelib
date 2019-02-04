/**
*Name:  Lukas Gutknecht
*Datum: 18.12.2018
*
* Main Function
**/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int day = 0, month = 0, year = 0;

    input_date(&day, &month, &year);

    printf("Der %i.%i.%i ist der %i. Tag des Jahres\n", day, month, year, day_of_the_year(day, month, year));
    printf("Der Tag liegt in der %i. Woche des Jahres\n", week_of_year(day, month, year));
    switch(weekday(day, month, year)){
        case 1: printf("Der Tag ist ein Montag");
    }
}

