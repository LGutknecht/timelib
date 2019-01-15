/**
*Name:  Lukas Gutknecht
*Datum: 18.12.2018
*
*Name: Berechnet den Tag im Jahr aufgrund eines Datums
**/

#include <stdio.h>
#include <stdlib.h>
/**
*   Funktionsprototypen
**/
int day_of_the_year(int day, int month, int year);
int is_leapyear(int year);
void input_date(int *day,int *month,int *year);
int get_days_for_month(int month, int year);
int exist_date(int day, int month, int year);

int main(){
    //Deklarieren der Variablen
    int day = 0, month = 0, year = 0;

    //Abfragen des Datums
    input_date(&day, &month, &year);

    //Berechnen und Ausgeben der Tage
    printf("Der %i.%i.%i ist der %i. Tag des Jahres", day, month, year, day_of_the_year(day, month, year));
}

/**
*   Nimmt ein Datum und rechnet es in die Anzahl der vergangenen Tage um
**/
int day_of_the_year(int day, int month, int year){
    int days = 0;
    //Addieren der Tage der Monate(Bis auf den aktuellen) auf days
    for(int i = 0; i < (month - 1); i++){
        days += get_days_for_month(month, year);
    }
    //Addieren der restlichen Tage des aktuellen Monats
    days += day;

    return days;
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

/**
*   Funktion zur Ausgabe der Anzahl der Tage eines Monats unter Berücksichtigung der Schaltjahre
**/
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
    Funktion prüft ob das Datum gültig ist.
    0: Datum existiert nicht
    1: Datum existiert
**/
int exist_date(int day, int month, int year){

    //Überprüfen des Monats
    if(get_days_for_month(month, year) == -1){
        printf("Ungueltiges Datum: Der Monat existiert nicht. \n");
        return 0;
    }

    //Überprüfen des Tages
    if(day > get_days_for_month(month, year)){
        printf("Ungueltiges Datum: Die Anzahl der eingegebenen Tage liegt ausserhalb des Monats. \n");
        return 0;
    }

    //Überprüfen des Jahres
    if(year > 2400 || year < 1582){
        printf("Ungueltiges Datum: Das Datum liegt nach dem Jahr 2400 oder vor dem Jahr 1582. \n");
        return 0;
    }

    return 1;
}

/**
*   Funktion liest Datum ein
**/
void input_date(int *day,int *month,int *year){
    do{
        printf("Geben sie den Tag ein:");
            scanf("%i", &*day);

        printf("Geben sie den Monat ein:");
            scanf("%i", &*month);

        printf("Geben sie das Jahr ein:");
            scanf("%i", &*year);

    }while(exist_date(*day, *month, *year) == 0);
}
