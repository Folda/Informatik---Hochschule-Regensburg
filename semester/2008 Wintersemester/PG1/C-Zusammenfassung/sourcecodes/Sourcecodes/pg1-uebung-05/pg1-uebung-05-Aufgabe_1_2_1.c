void readarray(float feld[],  int anzahl)
{
	int i;
	printf("Bitte %d Gleitpunktzahlen eingeben\n", anzahl);
	for(i = 0; i < anzahl; i++){
		printf("Zahl nr %5d = ", i);
		scanf_s("%f", &feld[i]);
	}
	return;
}

void writearray(float feld[], int anzahl)
{
	int i;
	for(i = 0; i < anzahl; i++)
		printf("feld[%d] = %3f\n", i, feld[i]);
	return;
}