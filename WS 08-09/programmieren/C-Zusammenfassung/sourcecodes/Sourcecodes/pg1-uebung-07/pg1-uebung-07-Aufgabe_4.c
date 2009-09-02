#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define N 20
#define N_EUROSCHEINE 6
/*
** Moegliche Werte fuer Geldscheine 
** 200Euro, 100Euro, 50Euro, 20Euro, 10Euro und 5Euro
** Es gibt nur diese 6 Werte
*/

typedef struct { int anzahl; int scheine[N]; } GELDBOERSE; 
GELDBOERSE haben = { 7, {50, 20, 10, 100, 5, 10, 50}};
GELDBOERSE wunsch1 = { 5, {50, 50, 10, 10, 50}};
GELDBOERSE wunsch2 = { 5, {50, 20, 10, 10, 50}};

typedef int SCHEINE[N_EUROSCHEINE];

SCHEINE gueltigeWerte = {200, 100, 50, 20, 10, 5};

/* holeNummer liefert die Nummer für einen Wert
** Wert = 200 : Ergebnis = 0
** Wert = 100 : Ergebnis = 1
** usw. 
** Ungültiger Wert : Ergebnsi = -1
*/
int holeNummer (int wert) {
  int i;
  for (i = 0; i < N_EUROSCHEINE; i++)
    if (gueltigeWerte[i] == wert)
      return i;
  return -1;
}

void zaehleScheine (GELDBOERSE* g, SCHEINE scheine) {
  int i;
  for (i = 0; i < N_EUROSCHEINE; i++)
    scheine[i] = 0;
  for (i = 0; i < g->anzahl; i++) {
    int wert = holeNummer(g->scheine[i]);
    if (wert >= 0)
      scheine[wert]++;
  }
}

/*
** habeScheine prüft, ob alle Scheine der 
** Geldbörse s in der Geldbörse h vorhanden sind.
** Wenn h nur einen Schein mit dem Wert 20 Euro enthält,
** s aber zwei Scheine zu desem Wert enthält, dann
** soll habeScheine den Wert 0 liefern.
** Falls alle Werte in geforderter Anzahl vorhanden
** sind, soll habeScheine den Wert 1 liefern,
** sonst den Wert 0.
*/ 
int habeScheine (GELDBOERSE *h, GELDBOERSE* s) {
  SCHEINE haben;
  SCHEINE soll;
  int i;
  zaehleScheine (h, haben);
  zaehleScheine (s, soll);
  for (i = 0; i < N_EUROSCHEINE; i++)
    if (haben[i] < soll[i])
      return 0;
  return 1;
}

int main (int argc, char* argv[]) {
  printf ("%d\n", habeScheine (&haben, &wunsch1));
  printf ("%d\n", habeScheine (&haben, &wunsch2));

  return 0;
}
