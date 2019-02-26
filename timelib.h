#ifndef TIMELIB_H_INCLUDED
#define TIMELIB_H_INCLUDED

/**
*   Initialisieren des Structs
**/
struct Date{
    int day;
    int month;
    int year;
    int foy;
};
int day_of_the_year(struct Date Date);
int is_leapyear(struct Date Date);
struct Date input_date();
int get_days_for_month(struct Date Date);
int exist_date(struct Date Date);
int calc_weekday(struct Date Date);
int calc_week_of_year(struct Date Date);


#endif // TIMELIB_H_INCLUDED
