void printPascalschesDreieck (int anzahlZeilen)
{
  int zahlen [MAXPASCAL], i, j;

  for (i = 1; i <= anzahlZeilen; i++)
  {
    /* Einsetzen der 1 : Hinten */
    zahlen[i-1] = 1;
    for (j = i-2; j >= 1; j--) {
      zahlen[j] = zahlen[j]+zahlen[j-1];
  }

  for (j = 1; j <= (anzahlZeilen-i); j++)
      printf("   "); /* Halbe Stellenanzahl */

    /* Ausgabe */
    for (j = 0; j < i; j++)
      printf ("%6d", zahlen[j]);  
    printf("\n");
  }
}
