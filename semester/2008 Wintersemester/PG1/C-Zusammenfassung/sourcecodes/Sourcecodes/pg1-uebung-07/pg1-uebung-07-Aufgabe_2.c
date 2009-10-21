#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define N_PARTEIEN 200
#define N_SITZE 300
#define N_STRING 80


/*
** Beschreibung einer Höchstzahl
*/
typedef struct {
  int    nr;     /* Laufende Nummer der Höchstzahl */
  double wert;   /* Wert des Divisors             */
  int    partei; /* Laufende Nummer der Partei    */
} HOECHSTZAHL;

/*
** Beschreibung einer Partei
*/
typedef struct {
  char   name[N_STRING]; /* Name der Partei    */
  int    stimmen;        /* Anzahl der Stimmen */
  int    sitze;          /* Anzahl der Sitze   */
  double prozent;        /* Prozentualer Anteil*/
} PARTEI;

/*
** Einlesen einer Partei
*/
PARTEI liesPartei (char * zeile) {
  PARTEI partei = {"", 0, 0, 0.0 };
  char token[80], *p;
  p = strtok (zeile, "#");
  strncpy (partei.name, p, N_STRING);
  p = strtok (NULL, "#");
  strncpy (token, p, N_STRING);
  sscanf (token, "%d", &partei.stimmen);
  return partei;
}

/*
** Ausgabe einer Partei
*/
void printPartei (PARTEI p) {
  printf ("Partei %-20s Stimmen=%8d Sitze = %5d Prozent = %3.2lf%%\n", 
    p.name, p.stimmen, p.sitze, p.prozent*100);
}

/*
** Daten
*/
PARTEI      parteien[N_PARTEIEN];  /* Daten für die Parteien */
HOECHSTZAHL divisoren[N_SITZE+1];  /* Die Divisoren          */
int anzahlSitze = 0; 
int anzahlParteien = 0;
int anzahlStimmen = 0;
int anzahlHoechstzahlen = 0;

/*
** Eingabe aller Daten
*/
void eingabe (char* name) {
  char zeile[200];
  FILE* f = fopen (name, "r");
  if (f == (FILE*)NULL)
    exit (1);
  printf ("%s\n", fgets (zeile, sizeof(zeile)-1, f));
  sscanf (zeile, "%d", &anzahlSitze);
  while (!feof (f)) {
    printf ("%s\n", fgets (zeile, sizeof(zeile)-1, f));
    if (strlen(zeile) <= 2)
      break;
    parteien[anzahlParteien++] = liesPartei (zeile);
  }
  if (f != (FILE*)NULL)
    fclose (f);
}

/*
** Ausgabe aller Daten
*/
void ausgabe () {
  int i = 0;
  printf ("Anzahl der Parteien = %d \n", anzahlParteien);
  for (i = 0; i < anzahlParteien; i++)
    printPartei (parteien[i]);
}

/*
** Sortieren der Divisoren nach ihrem Wert.
** Man benoetigt nur die obersten anzahlSitze+1 Divisoren
*/
void bubble (HOECHSTZAHL divisoren[], int anzahl) {
  int i, j;
  for (j = 1; j < anzahl; j++) 
    for (i = j; i >= j; i--) 
      if (divisoren[i].wert > divisoren[i-1].wert) {
        HOECHSTZAHL temp = divisoren[i];
        divisoren[i] = divisoren[i-1];
        divisoren[i-1] = temp;
      }
}

/*
** Berechne die Divisoren.
** Fuer jede Partei werden alle Divisoren berechnet
** Ein neuer Divisor wird zu den vorhandenen Divisoren hinzugefuegt.
** Dadurch koennten (anzahlSitze+1) - Divisoren vorliegen.
** Danach werden die Divisoren (anzahlSitze+1) nach ihrem Wert sortiert.
** Es werden nur die ersten anzahlSitze-Divisoren beruecksichtigt,
** da es nicht mehr Sitze zu verteilen gibt.
** Diese Divisoren stehen für die Sitze der Parteien
*/
void berechneDivisoren () {
  int partei, j, nummer = 0;
  anzahlHoechstzahlen = 0;
  /* Berechne für jede Partei die Divisoren
  ** und füge sie zum Array der Divisoren hinzu
  */
  for (partei = 0; partei < anzahlParteien; partei++) {
    int divisor = 1;
    for (j = 0; j < anzahlSitze; j++) {
      HOECHSTZAHL d = {nummer++, (1.0*parteien[partei].stimmen)/divisor++, partei};
      divisoren[anzahlHoechstzahlen++] = d;
      bubble (divisoren, anzahlHoechstzahlen);
      if (anzahlHoechstzahlen > anzahlSitze)
        anzahlHoechstzahlen = anzahlSitze;
    }
  }
}

/*
** Berechne die prozentualen Anteile der Parteien
*/
void berechneProzent () {
  int i = 0;
  anzahlStimmen = 0;
  for (i = 0; i < anzahlParteien; i++)
    anzahlStimmen += parteien[i].stimmen;
  for (i = 0; i < anzahlParteien; i++)
    parteien[i].prozent = (1.0*parteien[i].stimmen) / anzahlStimmen;
}

/*
** Berechne die Sitze der Parteien
** Die Folge der Divisoren (anzahlHoechstzahlen) wird untersucht. 
** Bei jedem Divisor ist angegeben, zu welcher Partei er gehört.
** Die Anzahl der Sitze der entsprechenden Partei wird erhöht.
*/
void berechneSitze () {
  int i;
  for (i = 0; i < anzahlHoechstzahlen; i++) {
    parteien[divisoren[i].partei].sitze++;
  }
}

int main (int argc, char* argv[]) {
  char *name = "dhondt-ergebnisse2.txt";
  if (argc > 1)
    name = argv[1];
  eingabe (name);
  berechneProzent();
  berechneDivisoren ();
  berechneSitze();
  ausgabe ();
  return 0;
}
