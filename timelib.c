#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"

/**
 *Die Funktion berechnet f�r ein gegebenes Datum des gregorianischen Kalenders bestehend aus Tag, Monat
 *und Jahr die Nummer des Tages, gez�hlt von Jahresbeginn (1. Januar) an. Schaltjahre werden bei der
 *Berechnung ber�cksichtigt. Ist das �bergebene Datum ung�ltig, betr�gt der R�ckgabewert -1.
 *
 *@param struct: tempDate, struct mit properties: day, month, year.
 *
 *@return Integer: dayOfYear, Gibt die Anzahl von Tagen in einem Jahr in bezug zu einem Datum an.
 **/

int day_of_the_year(struct date tempDate){
    int dayOfYear = 0;
    int i = 0;
    //ist das Datum g�ltig?
    if(exists_date(tempDate) == 0) {
        return -1;
    } else {
        //F�r jeden Monat wird die Funktion get_days_for_month aufgerufen bis zum aktuellen Monat.
        //Die jeweilige Tagesanzahl eines Monats wird dann zur Variable dayOfYear addiert.
        //Schaltjahre werden hierbei ber�cksichtigt.
        for(i = 1; i < tempDate.month; i++){
            dayOfYear += get_days_for_month(i, tempDate.year);
        }

        dayOfYear += tempDate.day;

        printf("Es ist der %i Tag im Jahr", dayOfYear);

        return dayOfYear;
    }
}

/**
 *Die Funktion liest 3 Ganzzahlwerte (Integer) ein, f�r Tag, Monat und Jahr. Wenn das angegebene Datum
 *ung�ltig ist, wird erneut eingelesen, solange bis ein g�ltiges Datum eingegeben wurde.
 *
 *@return struct: tempDate, struct mit properties: day, month, year.
 **/

struct date input_date(){
    //Der Nutzer wird zur Eingabe eines Datums aufgefordert, bis das Datum korrekt ist.
    //Die Zeiger verweisen auf Speicheradressen der Variablen day, month, year in der Main-Funktion.
    struct date inputdate;
    do {
        printf("gib einen Tag ein: ");
        scanf("%i", &inputdate.day);
        fflush(stdin);

        printf("gib einen Monat ein: ");
        scanf("%i", &inputdate.month);
        fflush(stdin);

        printf("gib einen Jahr ein: ");
        scanf("%i", &inputdate.year);
        fflush(stdin);
    } while (!(exists_date(inputdate))); //wiederholt Eingabeaufforderung bis ein korrektes Datum gew�hlt wurde.
    return inputdate;
}

/**
 *Die Funktion �berpr�ft, ob ein gegebenes Jahr nach den Regeln des gregorianischen Kalender ein Schaltjahr
 *ist. Bei Jahreszahlen vor dem Jahr 1582 wird ein Fehler zur�ckgegeben.
 *
 *@param Integer: year, Jahresangabe eines Datums
 *
 *@return Integer, 0 = kein Schaltjahr 1 = Schaltjahr
 **/

int is_leapyear(int year){

    while(year) {
        //Sonderfall wird ber�cksichtigt, falls das Jahr kleiner 1582 ist gelten unten stehende Regeln nicht mehr!
        if(year < 1582) {
            printf("Das eingegebene Jahr muss groesser sein als 1582!\n");
            return -1;
            break;
        }

        if(year % 4 == 0) { //Ist die Jahreszahl vollst�ndig druch vierteilbar

            if(year % 100 == 0) { //Ist die Jahreszahl vollst�ndig durch 100 teilbar

                if(year % 400 == 0) { //Ist die Jahreszahl vollst�ndig durch 400 teilbar

                    return 1; //Wenn die Jahreszahl vollst�ndig durch 4, 100 und 400 teilbar ist, ist das Jahr ein Schaltjahr.

                } else {

                    return 0; //Wenn die Jahreszahl vollst�ndig duch 4, 100 aber nicht durch 400 teilbar ist, ist das Jahr kein Schaltjahr

                }

            } else {

                return 1; //Wenn die Jahreszahl durch 4 aber nicht durch 100 vollst�ndig teilbar ist, ist das Jahr ein Schaltjahr

            }

        } else {

            return 0; //Wenn die Jahreszahl nicht vollst�ndig durch 4 teilbar ist, ist das Jahr kein Schaltjahr

        }
    }
}

/**
 *Die Funktion bestimmt f�r einen gegebenen Monat eines gegebenen Jahres, wie viele Tage der Monat hat. Der
 *Wert des Monats muss zwischen 1 und 12 liegen. Schaltjahre werden ber�cksichtigt.
 *
 *@param Integer: month, Monatsangabe eines Datums
 *@param Integer: year, Jahresangabe eines Datums
 *
 *@return Integer, Anzahl der Tage in einem Monat
 **/

int get_days_for_month(int month, int year) {
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    //F�r den jeweiligen Monat wird die Tagesanzahl aus dem days Array extrahiert.

    if((month < 1 || month > 12) || (year < 1582 || year > 2400)) {
        return -1;
    } else {
        //Wenn ein Schaltjahr vorliegt wird die Tagesanzahl f�r den Februar angepasst.
        if(is_leapyear(year)){
            days[1] = 29;
        }
        return days[month - 1];
    }
}

/**
 *Die Funktion �berpr�ft, ob ein eingegebenes Datum g�ltig ist. Daten vor dem 1.1.1582 sind ung�ltig, genauso
 *wie alle Daten nach dem 31.12.2400.
 *
 *@param struct: tempDate, struct mit properties: day, month, year.
 *
 *@return Integer, 0 = Datumsangabe existiert nicht 1 = Datumsangabe existiert
 **/

int exists_date(struct date tempDate) {
    //Bedingung g�ltiges Datum:
    //Anzahl der Tag im Monat ist nicht gr��er als m�glich, R�ckgriff auf get_days_for_month Funktion.
    //Tageszahl nicht kleiner als 1.
    //Monatszahl nicht gr��er als 12.
    //Monatsanzahl nicht kleiner als 1.
    //Jahreszahl nicht kleines als 1582.
    //Jahreszahl nicht gr��er als 2400

    if(tempDate.day > get_days_for_month(tempDate.month, tempDate.year) || tempDate.day < 1 || tempDate.month > 12 || tempDate.month < 1 || (tempDate.year < 1582) || (tempDate.year > 2400)) {
        return 0;
    } else {
        return 1;
    }
}

/*
int get_weekday(double day, int month, int year) {
    int months[12] = {11, 12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int d = day;
    int m = months[month - 1];
    int y = 0;
    int c = 0;


    if (month == 1 || month == 2) {
        y = ((year - 1) % 100);
    } else {
        y = (year % 100);
    }

    if (month == 1 || month == 2) {
        c = ((year - 1) - ((year - 1) % 100)) / 100;
    } else {
        c = ((year) - (year % 100)) / 100;
    }

    int w = (d + (2.6 * m - 0.2) + y + (y/4) + (c/4) - 2 * c) % 7;
    printf("%i \n", y);
    printf("%i \n", c);
    printf("%i", w);
}
*/
