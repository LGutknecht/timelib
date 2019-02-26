/**
*Name:  Lukas Gutknecht
*Datum: 18.12.2018
*
* Main Function
**/

#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"


int main(){
    struct Date Date;

    Date = input_date();

    printf("Der %i.%i.%i ist der %i. Tag des Jahres\n", Date.day, Date.month, Date.year, day_of_the_year(Date));
    printf("Der Tag liegt in der %i. Woche des Jahres\n", calc_week_of_year(Date));
    switch(calc_weekday(Date)){
        case 1: printf("Der Tag ist ein Montag");    break;
        case 2: printf("Der Tag ist ein Dienstag");  break;
        case 3: printf("Der Tag ist ein Mittwoch");  break;
        case 4: printf("Der Tag ist ein Donnerstag");break;
        case 5: printf("Der Tag ist ein Freitag");   break;
        case 6: printf("Der Tag ist ein Samstag");   break;
        case 7: printf("Der Tag ist ein Sonntag");   break;
    }
}

