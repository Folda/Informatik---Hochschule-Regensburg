#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *Soundex (char *S)
{
  static char Code[5];    /* Statisch init. mit 0     */
                          /*ABCDEFGHIJKLMNOPQRSTUVWXYZ*/
  static char Tabelle [] = "01230120022455012623010202";

  char *p = Code;

  *p++ = *S++;            /* 1. Zeichen uebernehemen  */

  while (*S)
    {
    char c = toupper (*S++);
    while (c == toupper (*S+1))
      S++;
    if (isalpha (c) && Tabelle[c-'A'] != '0')
      {
      *p++ = Tabelle[c-'A'];
      if (p - Code == 4)
        return (Code);
      }
    }
  while (p-Code < 4)
    *p++ = '0';
  return (Code);
}


void main (void)
{
  static char *Namen[] =
    {
    "Meier",
    "Maier",
    "Meyer",
    "Mayer",
    "Mayr",
    "Meir",
    "Bayer",
    "Meierhofer",
    "Obermeier",
    "Oberberger",
    "Oberhofer",
    "Rhein",
    "Rayn",
    "Rheinschiff",
    "Rheinschiffahrt",
    "Rheinbrücken",
    "Rein und Raus",
    NULL
    };
  char **p;

  printf ("\n\nStart\n");
  for (p = Namen; *p; p++)
    printf ("Soundex-Code fuer >%-20s< = >%s< \n", *p, Soundex (*p));

}
