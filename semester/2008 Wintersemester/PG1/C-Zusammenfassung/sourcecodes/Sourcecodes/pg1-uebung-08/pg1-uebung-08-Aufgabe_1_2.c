int ListeAnzahlElemente (P_BLOCK pListe) {
  int anzahl = 0;
  while (pListe) {
    anzahl++;
    pListe = pListe->pNext;
  }
  return anzahl;
}
