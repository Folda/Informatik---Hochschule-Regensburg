#include <stdio.h>

int armstrong(int zahl, int potenz)
{
	int i, temp_zahl, zt;
	float temp = 0;
	temp_zahl = zahl;

	//Schleife um die Einzellnen Potenzierten Ziffern zu addieren
	for(i = 5; i >= 0; i--)
	{
		//Schleife zum Bestimmen der einzellnen Ziffern
		if(zahl >= pow(10,i))
		{
			/*zt ist die rechte hintere stelle die mit der überlegung
			das die hinterste stelle gleich dem rest bei einer division mit 10 entspricht*/
			zt = temp_zahl % 10;

			//Löschen der hintersten Stelle aus dem int
			temp_zahl = temp_zahl / 10;

			//Potenzieren und hinzuzählen der Stelle
			temp += pow(zt,potenz);
		}
	}

	//Wenn die Summe der Potenzen gleich der eingegebenen Zahl ist dann true zurückgeben
	if(temp == zahl)
		return 1;

	return 0;
}

int main()
{
	//Maximalwert
	int maxwert = 999;

	int i;
	for(i = 0; i != maxwert; i++)
	{
		if(armstrong(i, 3) == 1)
			printf("%d\n", i);
	}

	system("pause");
	return 0;
}
