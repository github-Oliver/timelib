/**
 *
 * Titel: Tag des Jahres
 * Autor: Oliver Röckener
 * Datum: 28.01.2020
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"

int main(){
    int day;
    int month;
    int year;

    input_date(&day, &month, &year);
    get_weekday(day, month, year);

}
