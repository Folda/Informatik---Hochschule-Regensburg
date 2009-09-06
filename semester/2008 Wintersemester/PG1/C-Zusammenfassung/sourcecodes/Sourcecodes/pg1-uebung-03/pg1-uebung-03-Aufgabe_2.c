#include <stdio.h>

int main()
{
	int rohlinganzahl, rabatt;
	float kosten;
	rohlinganzahl = rabatt = kosten = 0;

	//Rohlinganzahl einlesen
	printf("rohlinganzahl eingeben\n");
	scanf("%d", &rohlinganzahl);

	//Rabattbestimmung
	if(rohlinganzahl >= 10)
		rabatt = 3;

	if(rohlinganzahl >= 50)
		rabatt = 5;

	if(rohlinganzahl >= 100)
		rabatt = 8;

	//Wenn Rabatt zutreffend mit Rabatt ausrechnen
	if(rabatt != 0)
	{
		kosten = rohlinganzahl * 1.20 - ((rohlinganzahl * 1.20) * (rabatt / 100));
	}
	else
		kosten = rohlinganzahl * 1.20;

	//Ausgabe
	printf("bei %d rohlingen muss er bei einem rabatt von %d Prozent genau %.2f euro zahlen\n", rohlinganzahl, rabatt, kosten);
	system("Pause");
	return 0;
}
