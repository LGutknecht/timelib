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
int weekday(int day, int month, int year);
int week_of_year(int day, int month, int year);

int main(){
    //Deklarieren der Variablen
    int day = 0, month = 0, year = 0, day_of_week = 0;

    //Abfragen des Datums
    input_date(&day, &month, &year);

    //Berechnen und Ausgeben der Tage
    printf("Der %i.%i.%i ist der %i. Tag des Jahres \n", day, month, year, day_of_the_year(day, month, year));

    day_of_week = weekday(day, month, year);

    //Ausgabe des Wochentags
    switch (day_of_week){
        case 1: printf("Der Tag ist ein Montag \n");     break;
        case 2: printf("Der Tag ist ein Dienstag \n");   break;
        case 3: printf("Der Tag ist ein Mittwoch \n");   break;
        case 4: printf("Der Tag ist ein Donnerstag \n"); break;
        case 5: printf("Der Tag ist ein Freitag \n");    break;
        case 6: printf("Der Tag ist ein Samstag \n");    break;
        case 7: printf("Der Tag ist ein Sonntag \n");    break;
    }

    printf("Die Woche ist die %i. Kalenderwoche", week_of_year(day, month, year));

}

/**
    Nimmt ein Datum und rechnet es in die Anzahl der vergangenen Tage um
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
    Funktion zur Überprüfung auf ein Schaltjahr
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
    Funktion zur Ausgabe der Anzahl der Tage eines Monats unter Berücksichtigung der Schaltjahre
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

    //Einlesen desm Datums bis dieses durch exist_date als gültig ausgegeben wurde
    do{
        printf("Geben sie den Tag ein:");
            scanf("%i", day);

        printf("Geben sie den Monat ein:");
            scanf("%i", month);

        printf("Geben sie das Jahr ein:");
            scanf("%i", year);

    }while(exist_date(*day, *month, *year) == 0);
}

/**
    Berechnet den Wochentag
**/
int weekday(int day, int month, int year){
    int days = 0, dayofweek = 0;

    //Addieren aller Tage bis aktuelles Jahr
    for (int i = 1582; i < year; i++){
        if(is_leapyear(year) == 1){
            days += 366;
        }
        else{
            days += 365;
        }
    }
    //Addieren aller restlichen Tage des Jahre bis Datum
    days += day_of_the_year(day, month, year);

    //Berechnen des Modulo
    dayofweek = days % 7;

    //Formatieren von weekday in ein 1-7 Format wobei 1 Montag und 7 Sonntag ist
    switch (dayofweek){
        case 0: dayofweek = 5;   break;
        case 1: dayofweek = 6;   break;
        case 2: dayofweek = 7;   break;
        case 3: dayofweek = 1;   break;
        case 4: dayofweek = 2;   break;
        case 5: dayofweek = 3;   break;
        case 6: dayofweek = 4;   break;
    }
    return dayofweek;
}

int week_of_year(int day, int month, int year){

    int days = 0, weeks = 0, first_day = 0, leftover_days = 0;

    //Abfrage des Wochentags
    first_day = weekday(1,1,year);

    //Abfrage des Tag des Jahres
    days = day_of_the_year(day, month, year);

    //Wenn der Wochentag ein anderer Tag außer Montag ist, befindet man sich in einer Kalenderwoche die
    //im letzten Jahr begonnen hat
    if (first_day != 1){
        days -= first_day;
        weeks ++;
    }
    //Berechnen der Wochen
    weeks += days / 7;

    //Berechnen der Resttage
    leftover_days = days % 7;

    //Wenn Restage da sind und wir noch nicht die 52 Woche erreicht haben wird eine Woche addiert
    //Wenn die 52te Woche erreicht ist, ist die aktuelle Woche die erste Kalenderwoche des nächsten Jahres
    if ((leftover_days > 0) && (weeks < 52)){
        weeks ++;
    }
    else if ((leftover_days > 0) && (weeks = 52)){
        weeks = 1;
    }

    return weeks;
}
