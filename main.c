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
    struct date currentDate;
    currentDate = input_date();
    day_of_the_year(currentDate);
}
