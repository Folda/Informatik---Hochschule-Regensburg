#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
  char    name[80]; 
  int     personalnummer; 
  double  gehalt;
} PERSON;


PERSON lies () {
  PERSON p;
  scanf ("%d %lf %s", &p.personalnummer, &p.gehalt, p.name);
  return p;
}

void lies2 (PERSON *p) {
  scanf ("%d %lf %s",
    &(p->personalnummer), &(p->gehalt), p->name);
}

void printByValue (PERSON a) {
  printf ("Name = %20s Personalnummer = %5d Gehalt = %5.2lf\n", 
    a.name, a.personalnummer, a.gehalt);
}

void printByReference (PERSON *a) {
  printf ("Name = %20s Personalnummer = %5d Gehalt = %5.2lf\n",
    a->name, a->personalnummer, a->gehalt);
}


PERSON Max (PERSON feld[], int anzahl) {
  int i;
  double max_gehalt = feld[0].gehalt;
  int max_index = 0;
  for (i = 1; i < anzahl; i++)
    if (feld[i].gehalt > max_gehalt) {
      max_gehalt = feld[i].gehalt;
      max_index = i;
    }
  return feld[max_index];
}

int main (int argc, char* argv[]) {
  PERSON p1 = {"Hugo", 6, 8.0};
  PERSON feld[] = {{"a", 1, 4.0}, {"b", 2, 6.0}, {"a", 7, 4.5}};

  printByValue (p1);
  printByReference (&p1);
  printByValue (Max(feld, sizeof(feld)/sizeof(feld[0])));
  p1 = lies ();
  printByValue (p1);
  lies2 (&p1);
  printByReference (&p1);
  return 0;
}
