/**
*Name:  Lukas Gutknecht
*Datum: 18.12.2018
*
*Name: Berechnet den Tag im Jahr aufgrund eines Datums
**/

#include <stdio.h>
#include <stdlib.h>

int day_of_the_year(int day, int month, int year);
int is_leapyear(int year);
//int input_date(&day, &month, &year);
int get_days_for_month(int month, int year);
int exist_date(int day, int month, int year);

int main()
{
    printf("Tag des Jahres: %i\n", day_of_the_year(31, 12, 2018));
    return 0;
}

/**
*   Nimmt ein Datum und rechnet es in die Anzahl der vergangenen Tage um
**/
int day_of_the_year(int day, int month, int year)
{
    return 0;
}

/**
*   Funktion zur Überprüfung auf ein Schaltjahr
**/
int is_leapyear(int year){

    if(year < 1582){
        return -1;
    }

    //Prüfung Teilbarkeit durch 4
    if(year%4 == 0)
        {
        //Prüfung Teilbarkeit durch 100
        if(year%100 == 0)
        {
            //Prüfung Teilbarkeit durch 400
            if(year%400 == 0)
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


int get_days_for_month(int month, int year){


    //Überprüfen des Falles eines Schaltjahres wegen Februar
    if(is_leapyear(year) == 1 && month == 2){
            month = 13;
    }

    //Ausgabe der Tage pro Monat
    switch (month){
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12: return 31; break; //Monate mit 31 Tagen
    case 2:  return 28;        //Februar im Normaljahr
    case 4:
    case 6:
    case 9:
    case 11: return 30; break; //Monate mit 30 Tagen
    case 13: return 29; break; //Februar im Schaltjahr
    default: return -1; break;
    }
}


/**
*   Prüft ob das Datum gültig ist.
**/
int exist_date(int day, int month, int year){

    //Überprüfen des Datums
    if(get_days_for_month(month, year) == -1){
        return 0;
    }

    //Überprüfen des Jahres
    if(year > 2400 || year < 1582){
        return 0;
    }

    return 1;
}
