PERSON lies () {
  PERSON p;
  scanf ("%d %lf %s", &p.personalnummer, &p.gehalt, p.name);
  return p;
}

void printByValue (PERSON a) {
  printf ("Name = %20s Personalnummer = %5d Gehalt = %5.2lf\n", 
    a.name, a.personalnummer, a.gehalt);
}

void printByReference (PERSON *a) {
  printf ("Name = %20s Personalnummer = %5d Gehalt = %5.2lf\n",
    a->name, a->personalnummer, a->gehalt);
}
