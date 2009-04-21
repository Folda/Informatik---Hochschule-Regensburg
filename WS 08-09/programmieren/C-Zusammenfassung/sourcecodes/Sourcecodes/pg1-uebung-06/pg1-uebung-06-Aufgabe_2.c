#include <stdio.h>
#include <assert.h>

#define DIM 2
typedef float TMATRIX[DIM][DIM];

void add (TMATRIX a, TMATRIX b, TMATRIX c);
void sub (TMATRIX a, TMATRIX b, TMATRIX c);
void mul (TMATRIX a, TMATRIX b, TMATRIX c);
void print (TMATRIX a);


void main () {
  TMATRIX a = {{1,0},{0,1}};
  TMATRIX b = {{0,1},{1,0}};
  TMATRIX c, d, e;

  add (a, b, c);
  sub (a, b, d);

  print (c);
  print (d);


}


void add (TMATRIX a, TMATRIX b, TMATRIX c) {
  int i, j;
  assert (a != NULL);
  assert (b != NULL);
  assert (c != NULL);
  /* Schleife über die Zeilen */
  for (i = 0; i < DIM; i++) {
    /* Schleife über die Spalten */
    for (j = 0;j < DIM; j++)
      c[i][j] = a[i][j] + b[i][j];
  }
}

void sub (TMATRIX a, TMATRIX b, TMATRIX c) {
  int i, j;
  assert (a != NULL);
  assert (b != NULL);
  assert (c != NULL);
  /* Schleife über die Zeilen */
  for (i = 0; i < DIM; i++) {
    /* Schleife über die Spalten */
    for (j = 0;j < DIM; j++)
      c[i][j] = a[i][j] - b[i][j];
  }
}


void mul (TMATRIX a, TMATRIX b, TMATRIX c) {
  int i;
  /* Für alle Zeilen i tue */
  for (i = 0; i < DIM; i++) {
    int j;
    /* Für alle Spalten j tue*/
    for (j = 0; j < DIM; j++) {
      int k;
      float summe = 0.0;
      for (k = 0; k < DIM; k++) {
        summe += a[i][k] * b[k][j];
      }
      c[i][j] = summe;
    }
  }
}

void print (TMATRIX a) {
  /*
  Für alle Zeilen tue;
  Für alle Spalten tue
  Ausgabe des Elements[zeile][spalte]
  */
  int i, j;
  assert (a);
  printf ("----------------\n");
  /* Schleife über die Zeilen */
  for (i = 0; i < DIM; i++) {
    /* Schleife über die Spalten */
    for (j = 0; j < DIM; j++) {
      printf ("%5.2f", a[i][j]);
    }
    printf ("\n");
  }

}
