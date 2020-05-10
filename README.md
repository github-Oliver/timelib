# Timelib Dokumentation

# Functions

int day\_of\_the\_year(struct date tempDate)

Die Funktion berechnet für ein gegebenes Datum des gregorianischen Kalenders bestehend aus Tag, Monat und Jahr die Nummer des Tages, gezählt von Jahresbeginn (1. Januar) an. Schaltjahre werden bei der Berechnung berücksichtigt. Ist das übergebene Datum ungültig, beträgt der Rückgabewert -1.

- Parameters
  - struct: tempDate, struct mit properties: day, month, year.
- Returns
  - Integer: dayOfYear, Gibt die Anzahl von Tagen in einem Jahr in bezug zu einem Datum an.

struct date input\_date()

Die Funktion liest 3 Ganzzahlwerte (Integer) ein, für Tag, Monat und Jahr. Wenn das angegebene Datum ungültig ist, wird erneut eingelesen, solange bis ein gültiges Datum eingegeben wurde.

- Returns
  - struct: tempDate, struct mit properties: day, month, year.

int is\_leapyear(int year)

Die Funktion überprüft, ob ein gegebenes Jahr nach den Regeln des gregorianischen Kalender ein Schaltjahr ist. Bei Jahreszahlen vor dem Jahr 1582 wird ein Fehler zurückgegeben.

- Parameters
  - Integer: year, Jahresangabe eines Datums
- Returns
  - Integer, 0 = kein Schaltjahr, 1 = Schaltjahr, -1 = Jahr außerhalb des Wertebereichs

int get\_days\_for\_month(int month, int year)

Die Funktion bestimmt für einen gegebenen Monat eines gegebenen Jahres, wie viele Tage der Monat hat. Der Wert des Monats muss zwischen 1 und 12 liegen. Schaltjahre werden berücksichtigt.

- Parameters
  - Integer: month, Monatsangabe eines Datums
  - Integer: year, Jahresangabe eines Datums
- Returns
  - Integer, Anzahl der Tage in einem Monat

int exists\_date(struct date tempDate)

Die Funktion überprüft, ob ein eingegebenes Datum gültig ist. Daten vor dem 1.1.1582 sind ungültig, genauso wie alle Daten nach dem 31.12.2400.

- Parameters
  - struct: tempDate, struct mit properties: day, month, year.
- Returns
  - Integer, 0 = Datumsangabe existiert nicht 1 = Datumsangabe existiert