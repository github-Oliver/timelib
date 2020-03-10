#ifndef TIMELIB_H_INCLUDED
#define TIMELIB_H_INCLUDED
struct date {
    int day;
    int month;
    int year;
};

int day_of_the_year(struct date tempDate);
struct date input_date(void);
int is_leapyear(int year);
int get_days_for_month(int month, int year);
int exists_date(struct date tempDate);
#endif // TIMELIB_H_INCLUDED
