#include <stdio.h>
#include <stdlib.h>

//test eines Branch
//test test test test

/**
 *Die Funktion berechnet für ein gegebenes Datum des gregorianischen Kalenders bestehend aus Tag, Monat
 *und Jahr die Nummer des Tages, gezählt von Jahresbeginn (1. Januar) an. Schaltjahre werden bei der
 *Berechnung berücksichtigt. Ist das übergebene Datum ungültig, beträgt der Rückgabewert -1.
 **/

int day_of_the_year(int day, int month, int year){
    int dayOfYear = 0;
    int i = 0;
    //ist das Datum gültig?
    if(exists_date(day, month, year) == 0) {
        return -1;
    } else {
        //Für jeden Monat wird die Funktion get_days_for_month aufgerufen bis zum aktuellen Monat.
        //Die jeweilige Tagesanzahl eines Monats wird dann zu Variable dayOfYear addiert.
        //Schaltjahre werden hierbei berücksichtigt.
        for(i = 1; i < month; i++){
            dayOfYear += get_days_for_month(i, year);
        }

        dayOfYear += day;

        printf("Es ist der %i Tag im Jahr", dayOfYear);

        return dayOfYear;
    }
}

/**
 *Die Funktion liest 3 Ganzzahlwerte (Integer) ein, für Tag, Monat und Jahr. Wenn das angegebene Datum
 *ungültig ist, wird erneut eingelesen, solange bis ein gültiges Datum eingegeben wurde.
 **/

int input_date(){
    //Der Nutzer wird zur Eingabe eines Datums aufgefordert, bis das Datum korrekt ist.
    int date[3];

    do {
        printf("gib einen Tag ein: ");
        scanf("%i", &date[0]);
        fflush(stdin);

        printf("gib einen Monat ein: ");
        scanf("%i", &date[1]);
        fflush(stdin);

        printf("gib einen Jahr ein: ");
        scanf("%i", &date[2]);
        fflush(stdin);
    } while (!(exists_date(date[0], date[1], date[2])));

    printf("Test: %i.%i.%i", date[0], date[1], date[2]);
    return date;
}

/**
 *Die Funktion überprüft, ob ein gegebenes Jahr nach den Regeln des gregorianischen Kalender ein Schaltjahr
 *ist. Bei Jahreszahlen vor dem Jahr 1582 wird ein Fehler zurückgegeben.
 **/

int is_leapyear(int year){

    while(year) {
        //Sonderfall wird berücksichtigt, falls das Jahr kleiner 1582 ist gelten unten stehende Regeln nicht mehr!
        if(year < 1582) {
            printf("Das eingegebene Jahr muss groesser sein als 1582!");
            return -1;
            break;
        }

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
}

/**
 *Die Funktion bestimmt für einen gegebenen Monat eines gegebenen Jahres, wie viele Tage der Monat hat. Der
 *Wert des Monats muss zwischen 1 und 12 liegen. Schaltjahre werden berücksichtigt.
 **/

int get_days_for_month(int month, int year) {
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(month < 1 || month > 12) {
        printf("Der Monat lieg ausserhalb des Wertebereichs!");
        return -1;
    } else {
        if(is_leapyear(year)){
            days[1] = 29;
        }
        return days[month - 1];
    }
}

/**
 *Die Funktion überprüft, ob ein eingegebenes Datum gültig ist. Daten vor dem 1.1.1582 sind ungültig, genauso
 *wie alle Daten nach dem 31.12.2400.
 **/

int exists_date(int day, int month, int year) {
    if((day > get_days_for_month(month, year) || day < 1 || month > 12 || month < 1 || year < 1) || (year < 1582) || (year > 2400)) {
        return 0;
    } else {
        return 1;
    }
}

int get_weekday(int date) {
    int months[12] = {11, 12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int m = months[date[1] - 1];
    int d = date[0];


    if (month == 1 || month == 2) {
        int z4 = year % 10;
        int z3 = (year % 100) * 10;
    } else {
        int z4 = (year - 1) % 10;
        int z3 = ((year - 1) % 100) * 10;
    }
    int y = z3 + z4;

        if (month == 1 || month == 2) {
        int z2 = year % 1000;
        int z1 = (year % 10000) * 10;
    } else {
        int z2 = (year - 1) % 1000;
        int z1 = ((year - 1) % 10000) * 10;
    }
    int c = z1 + z2;

    int w = d + (2.6 * m - 0.2) + y + (y/4) + (c/4);

    printf("%i", w);
}
