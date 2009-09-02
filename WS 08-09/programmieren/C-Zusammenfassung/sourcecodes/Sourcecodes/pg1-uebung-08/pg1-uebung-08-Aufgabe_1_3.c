void ListeHintenEinketten (P_BLOCK *pListe, P_BLOCK pBlock) {
  assert (pBlock && pBlock->pContent);

  if ((*pListe) == (P_BLOCK)NULL)
    *pListe = pBlock;
  else {
    P_BLOCK p;
    for (p = *pListe; p->pNext != (P_BLOCK)NULL; p = p->pNext)
      ;
    p->pNext = pBlock;
  }
}
