/**
*Name:  Lukas Gutknecht
*Datum: 29.01.2019
*
*Name: Funktionssammlung zur Tagesbrechnung
**/

#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"


/**
    Die Funktion berechnet f�r ein gegebenes Datum des gregorianischen Kalenders bestehend aus Tag, Monat
    und Jahr die Nummer des Tages, gez�hlt von Jahresbeginn (1. Januar) an. Schaltjahre werden bei der
    Berechnung ber�cksichtigt. Ist das �bergebene Datum ung�ltig, betr�gt der R�ckgabewert -1.
**/
int day_of_the_year(struct Date Date){
    int days = 0;

    //�berpr�fen des �bergebenen Datums
    if (exist_date(Date) == 0){
        return -1;
    }
    //Addieren der Tage der Monate(Bis auf den aktuellen) auf days
    for(int i = 0; i < (Date.month - 1); i++){
        days += get_days_for_month(Date);
    }
    //Addieren der restlichen Tage des aktuellen Monats
    days += Date.day;

    return days;
}

/**
    Die Funktion �berpr�ft, ob ein gegebenes Jahr nach den Regeln des gregorianischen Kalender ein Schaltjahr
    ist. Bei Jahreszahlen vor dem Jahr 1582 wird ein Fehler zur�ckgegeben.
**/
int is_leapyear(struct Date Date){
    if(Date.year < 1582){
        return -1;
    }
    //�berpr�fung auf Teilung durch 4
    if(Date.year%4 == 0){
        //�berpr�fung auf Teilung durch 100, wenn ja, dann kein Schaltjahr
        if(Date.year%100 != 0){
            //�berpr�fung auf Teilung durch 400
            if(Date.year%400 == 0){
                return 1;
            }
            else
                return 0;
        }
        else
            return 1;
    }
    else
        return 0;
}

/**
    Die Funktion bestimmt f�r einen gegebenen Monat eines gegebenen Jahres, wie viele Tage der Monat hat. Der
    Wert des Monats muss zwischen 1 und 12 liegen. Schaltjahre werden ber�cksichtigt.
**/
int get_days_for_month(struct Date Date){
    //Deklarieren einer Monatsvaribale um nicht in eine referenz zu schreiben & Addieren von 1 um den richtigen Monat zu bekommen
    int month = Date.month +1;

    //�berpr�fen des Falles eines Schaltjahres wegen Februar
    if(is_leapyear(Date) == 1 && month == 2){
            month = 13;
    }

    //Ausgabe der Tage pro Monat
    switch (month){
        case 1: //return 31; break;
        case 3: //return 31; break;
        case 5: //return 31; break;
        case 7: //return 31; break;
        case 8: //return 31; break;
        case 10: //return 31; break;
        case 12: return 31; break; //Monate mit 31 Tagen
        case 2:  return 28; break; //Februar im Normaljahr
        case 4: //return 30; break;
        case 6: //return 30; break;
        case 9: //return 30; break;
        case 11: return 30; break; //Monate mit 30 Tagen
        case 13: return 29; break; //Februar im Schaltjahr
        default: return -1; break;
    }
}

/**
    Die Funktion �berpr�ft, ob ein eingegebenes Datum g�ltig ist. Daten vor dem 1.1.1582 sind ung�ltig, genauso
    wie alle Daten nach dem 31.12.2400.
**/
int exist_date(struct Date Date){

    //�berpr�fen des Monats
    if(get_days_for_month(Date) == -1){
        printf("Ungueltiges Datum: Der Monat existiert nicht. \n");
        return 0;
    }

    //�berpr�fen des Tages
    if(Date.day > get_days_for_month(Date)){
        printf("Ungueltiges Datum: Die Anzahl der eingegebenen Tage liegt ausserhalb des Monats. \n");
        return 0;
    }

    //�berpr�fen des Jahres
    if(Date.year > 2400 || Date.year < 1582){
        printf("Ungueltiges Datum: Das Datum liegt nach dem Jahr 2400 oder vor dem Jahr 1582. \n");
        return 0;
    }

    return 1;
}

/**
    Die Funktion liest 3 Ganzzahlwerte (Integer) ein, f�r Tag, Monat und Jahr. Wenn das angegebene Datum
    ung�ltig ist, wird erneut eingelesen, solange bis ein g�ltiges Datum eingegeben wurde.
**/
struct Date input_date(){
    //Deklarieren des Struct
    struct Date Date;
    fflush(stdin);
    //Einlesen des Datums bis dieses durch exist_date als g�ltig ausgegeben wurde
    do{
        printf("Geben sie den Tag ein:");
            scanf("%i", &Date.day);

        printf("Geben sie den Monat ein:");
            scanf("%i", &Date.month);

        printf("Geben sie das Jahr ein:");
            scanf("%i", &Date.year);

    }while(exist_date(Date) == 0);

    return Date;
}

/**
    Funktion bestimmt welcher Wochentag dem gegebenen Datum entspricht. Sollte ein ung�ltiges Datum eingegeben
    werden, wird -1 zur�ckgegeben.
**/
int calc_weekday(struct Date Date){

    //Deklarieren der Variablen
    int days = 0, dayofweek = 0;

    //�berpr�fen ob das Datum g�ltig ist
    if (exist_date(Date) == 0){
        return -1;
    }

    //Addieren aller Tage bis aktuelles Jahr
    for (int i = 1582; i < Date.year; i++){
        if(is_leapyear(Date) == 1){
            days += 366;
        }
        else{
            days += 365;
        }
    }
    //Addieren aller restlichen Tage des Jahre bis Datum
    days += day_of_the_year(Date);

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
/**
*   Funktion bestimmt die Kalenderwoche in der das gegebene Datum liegt. Sollte ein ung�ltiges Datum eingegeben
    werden, wird -1 zur�ckgegeben.
**/

int calc_week_of_year(struct Date Date){

    //Deklarieren der Variablen
    int daysofyear = 0, weeks = 0, first_day = 0, leftover_days = 0;
    struct Date TempDate;

    //Beschreiben des TempDate Struct
    TempDate.day = 1;
    TempDate.month = 1;
    TempDate.year = Date.year;

    //�berpr�fen ob das Datum g�ltig ist
    if (exist_date(Date) == 0){
        return -1;
    }

    //Abfrage des Wochentags
    first_day = calc_weekday(TempDate);

    //Abfrage des Tag des Jahres
    daysofyear = day_of_the_year(Date);

    //Wenn der Wochentag ein anderer Tag au�er Montag ist, befindet man sich in einer Kalenderwoche die
    //im letzten Jahr begonnen hat
    if (first_day != 1){
        daysofyear -= first_day;
        weeks ++;
    }
    //Berechnen der Wochen
    weeks += daysofyear / 7;

    //Berechnen der Resttage
    leftover_days = daysofyear % 7;

    //Wenn Restage da sind und wir noch nicht die 52 Woche erreicht haben wird eine Woche addiert
    //Wenn die 52te Woche erreicht ist, ist die aktuelle Woche die erste Kalenderwoche des n�chsten Jahres
    if ((leftover_days > 0) && (weeks < 52)){
        weeks ++;
    }
    else if ((leftover_days > 0) && (weeks = 52)){
        weeks = 1;
    }

    return weeks;
}

