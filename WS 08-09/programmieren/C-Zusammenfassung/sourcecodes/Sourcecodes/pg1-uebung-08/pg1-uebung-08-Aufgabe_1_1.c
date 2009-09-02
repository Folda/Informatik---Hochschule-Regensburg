void ListeSortiertEinketten(P_BLOCK *pListe, P_BLOCK pBlock) {
  if (*pListe == NULL || strcmp ((*pListe)->pContent, pBlock->pContent) >= 0)
    ListeVorneEinketten (pListe, pBlock);
  else {
    /* Suche den Platz zum Einketten */
    P_BLOCK p = *pListe;
    while (p->pNext && strcmp (p->pNext->pContent, pBlock->pContent) < 0)
      p = p->pNext;
    ListeVorneEinketten (&(p->pNext), pBlock);
  }
}
