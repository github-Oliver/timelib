#ifndef TIMELIB_H_INCLUDED
#define TIMELIB_H_INCLUDED

int day_of_the_year(int day, int month, int year);
void input_date(int *zeigerDay, int *zeigerMonth, int *zeigerYear);
int is_leapyear(int year);
int get_days_for_month(int month, int year);
int exists_date(int day, int month, int year);

#endif // TIMELIB_H_INCLUDED
