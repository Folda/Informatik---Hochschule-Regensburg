float maximum(float feld[], int anzahl)
{
	float max = 0;
	int i;
	for(i = 0; i < anzahl; i++){
		if(feld[i] > max)
			max = feld[i];
	}

	return max;
}