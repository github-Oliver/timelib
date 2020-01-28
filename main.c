/**
 *
 * Titel: Tag des Jahres
 * Autor: Oliver Röckener
 * Datum: 28.01.2020
 *
 **/

#include <stdio.h>
#include <stdlib.h>

/**
 *
 *
 **/
 int is_leapyear(int year){

    while(year) {

        if(year % 4 == 0) { //Ist die Jahreszahl vollständig druch vierteilbar

            if(year % 100 == 0) { //Ist die Jahreszahl vollständig durch 100 teilbar

                if(year % 400 == 0) { //Ist die Jahreszahl vollständig durch 400 teilbar

                    return 1; //Wenn die Jahreszahl vollständig durch 4, 100 und 400 teilbar ist, ist das Jahr ein Schaltjahr.

                } else {

                    return 0; //Wenn die Jahreszahl vollständig duch 4, 100 aber nicht durch 400 teilbar ist, ist das Jahr kein Schaltjahr

                }

            } else {

                return 1; //Wenn die Jahreszahl durch 4 aber nicht durch 100 vollständig teilbar ist, ist das Jahr ein Schaltjahr

            }

        } else {

            return 0; //Wenn die Jahreszahl nicht vollständig durch 4 teilbar ist, ist das Jahr kein Schaltjahr

        }
    }

    return 0;
}

int day_of_the_year(int day, int month, int year){

    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dayOfYear = 0;

    for(int i = 1; i < month; i++){
        dayOfYear += days[i];
    }

    dayOfYear += day;

    printf("Es ist der %i Tag im Jahr", dayOfYear);

    return 0;
}

int main(){
     int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
     int day, month, year, dayOfYear = 0;

    do {
        printf("gib einen Tag ein: ");
        scanf("%i", &day);
        fflush(stdin);

        printf("gib einen Monat ein: ");
        scanf("%i", &month);
        fflush(stdin);

        printf("gib einen Jahr ein: ");
        scanf("%i", &year);
        fflush(stdin);

        if(is_leapyear(year)) {
            days[1] = 29;
        }
    } while(day > days[month - 1] || day < 1 || month > 12 || month < 1 || year < 1);

    day_of_the_year(day, month, year);
    return 0;
}
