/**
 *Name:  Lukas Gutknecht
 *Datum: 18.12.2018
 *
 *Name: Berechnet den Tag im Jahr aufgrund eines Datums
 **/

#include <stdio.h>
#include <stdlib.h>

int day_of_the_year(int day, int month, int year);
int isLeapyear(int Year);

int main()
{
    printf("Tag des Jahres: %i\n", day_of_the_year(31, 12, 2018));
    return 0;
}

/**
 * Nimmt ein Datum und rechnet es in die Anzahl der vergangenen Tage um
 *
 **/
int day_of_the_year(int day, int month, int year)
{
    return 0;
}

/**
Funktion zur Überprüfung auf ein Schaltjahr
**/
int isLeapyear(int Year){

    //Prüfung Teilbarkeit durch 4
    if(Year%4 == 0)
        {
        //Prüfung Teilbarkeit durch 100
        if(Year%100 == 0)
        {
            //Prüfung Teilbarkeit durch 400
            if(Year%400 == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}
