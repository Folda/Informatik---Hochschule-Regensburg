void bubblesort(float feld[], int anzahl, int sort)
{
	int i, j;
	for(i = 0; i < anzahl; i++) {
		for(j = 0; j < (anzahl - 1); j++) {
			if(feld[j] > feld[j + 1] && sort == 1) 
			{
				swapFloat(&feld[j], &feld[j + 1]);
			}
			if(feld[j] < feld[j + 1] && sort == 2) 
			{
				swapFloat(&feld[j], &feld[j + 1]);
			}
		}
	}

	return;
}