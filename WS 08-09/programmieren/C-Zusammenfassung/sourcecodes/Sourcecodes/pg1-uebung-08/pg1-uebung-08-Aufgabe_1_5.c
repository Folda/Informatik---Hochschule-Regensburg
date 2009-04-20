void ListeFreigeben (P_BLOCK pListe) {
  while (pListe) {
    P_BLOCK y = pListe;
    pListe = pListe->pNext;
    BlockFreigeben (y);
  }
}
