void ListeUmdrehen (P_BLOCK *pListe) {
  P_BLOCK a, b, c;

  a = (P_BLOCK)NULL;
  c = *pListe;

  while (c != (P_BLOCK)NULL) {
    b = c->pNext;
    c->pNext = a;
    a = c;
    c = b;
  }
  *pListe = a;
}
