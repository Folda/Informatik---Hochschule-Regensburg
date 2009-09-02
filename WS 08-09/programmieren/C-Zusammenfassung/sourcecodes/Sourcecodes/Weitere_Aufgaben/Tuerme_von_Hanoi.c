#include <stdio.h>                                                //für ein und ausgabe
#define anzahl 5                                                  //hoehe des turms

typedef int feldtyp[3][anzahl];                                   //3 positionen mit maximaler höhe

void ausgabe (feldtyp feld, int zuege)                            //ausgabe der aktuellen position, das feld und anzahl züge werden übergeben
{
	int i;                                                          //zaehlvariable
	for (i = anzahl-1; i>=0; i--)                                   //anzahl-oft ausführen, rückwärts zählen
		printf("%2d %2d %2d\n",feld[0][i],feld[1][i],feld[2][i]);   //ausgabe für die aktuelle höhe
	printf("_-__-__-_ %8d. Zug\n",zuege);                           //begrenzung
}

int main ()
{ 
	int richtung,i,naechster,ziel;                                  //hilfsvariablen
	int hoehe[3];                                                   //aktuelle höhe auf den 3 positionen
	int zuege = 0;                                                  //zum zuege zählen
	feldtyp feld;                                                   //in diesem feld wird gearbeitet

	for (i = 0; i<anzahl; i++)                                      //anzahl-oft ausführen, vorwärts
	{
		feld[0][i] = anzahl-i;                                      //an 1. position sind alle steine
		feld[1][i] = 0;                                             //an 2. und
		feld[2][i] = 0;                                             //3. position noch keine
	}
	hoehe[0] = anzahl-1;                                            //die anfangshoehen
	hoehe[1] = -1;                                                  //für
	hoehe[2] = -1;                                                  //die 3 positionen

	richtung = anzahl & 1 ? -1 : 1;                                 //wenn anzahl gerade dann richtung=1 sonst richtung=-1
	ausgabe(feld,0);                                                //feld ausgeben

	naechster = 0;                                                  //erster zu rückender stein steht auf postion 1
	while (hoehe[2] < anzahl-1)                                     //wiederhole, solange nicht der komplette turm auf postion 2 steht
	{
		ziel = naechster + (feld[naechster][hoehe[naechster]] & 1 ? 1 : -1) * richtung;
		//4 möglichkeiten, 2 richtungen:
		//1. turm hat gerade höhe und aktueller stein gerade breite -> stein geht rückwärts
		//2. gerade höhe, ungerade breite -> vorwärts
		//3. ungerade höhe, gerade breite -> vorwärts
		//4. ungerade höhe, ungerade breite -> rückwärts
		if (ziel == -1)                                               //statt position 0
			ziel = 2;                                                 //lieber position 3
		else if (ziel == 3)                                           //statt position 4
			ziel = 0;                                                 //lieber position 1
		hoehe[ziel]++;                                                //bei der zielpostion steigt die höhe um eins
		feld[ziel][hoehe[ziel]] = feld[naechster][hoehe[naechster]];  //auf zielposition wird der stein gelegt
		feld[naechster][hoehe[naechster]] = 0;                        //auf alter position liegt nun keiner mehr
		hoehe[naechster]--;                                           //bei der alten position sinkt die höhe um eins
		zuege++;                                                      //es wurde ein zug mehr gemacht
		ausgabe(feld,zuege);                                          //feld ausgeben, bei großer anzahl auskommentieren
		if (ziel==0)                                                  //der nächste zu ziehende stein wird ausgewählt
			//es wird nicht der gerade gezogene
			//von den anderen beiden oben liegenden wird der kleinste ausgewählt
			//bzw. steht auf einer position kein stein, wird die andere gewählt
			naechster = ((hoehe[1] >= 0) && ((hoehe[2] == -1) || (feld[1][hoehe[1]] < feld[2][hoehe[2]]))) ? 1 : 2;
		else if (ziel == 1)
			naechster = ((hoehe[0] >= 0) && ((hoehe[2] == -1) || (feld[0][hoehe[0]] < feld[2][hoehe[2]]))) ? 0 : 2;
		else
			naechster = ((hoehe[0] >= 0) && ((hoehe[1] == -1) || (feld[0][hoehe[0]] < feld[1][hoehe[1]]))) ? 0 : 1;
		getc(stdin);                                                //auf return warten, dann soviele züge machen, wie tasten gedrückt wurden
		//bei großer anzahl auskommentieren
	}																//ausgabe(feld,zuege);
	//bei großer anzahl reinkommentieren
	return 0;                                                       //um warning zu verhindern
}
//fertig
