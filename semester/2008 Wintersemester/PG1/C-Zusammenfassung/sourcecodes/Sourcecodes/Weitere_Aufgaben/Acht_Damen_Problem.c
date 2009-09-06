typedef int BOOLEAN;
#define TRUE 1
#define FALSE 0

#define ENDE ((int)(-1))
typedef BOOLEAN T_Damen[9]; //8 Damen und eine Endmarke

T_Damen damen;

/*
// Dame setzt ab Spalte i Damen in das Schachbrett.
// Es werden alle Loesungen des 8-Damen-Problems ermittelt.
*/

void dame (T_Damen damen, int i)
{
	int j;

	for(j = 0; j <= 7; j++)
	{
		if(!bedroht) (damen, i, j))
		{
			/* Test Dame Nr. i */
			damen[i] = j;
			if(i == 7)
			{
				add(damen);
				damen[i] = ENDE;
				return;
			}
			else
				dame(damen, i + 1);

			/* Ziehe ggfs. Dame wieder zurück */
			damen[i] = ENDE;
		}
	}
}

/*
// bedroht stellt fest, ob die Damen "damen" das Feld
// x, y bedrohen.
*/
BOOLEAN bedroht (T_Damen damen, int x, int y)
{
	int i = 0;
	while(damen[i] != ENDE)
	{
		if((y == damen[i])
			|| (x == damen[i])
			|| (x + y == i + damen[i])
			|| (y - x == damen[i] - i))
		{
			return (TRUE);
		}
		else
			i++;
	}

	return (FALSE);
}