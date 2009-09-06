#include <stdio.h>

int main()
{
	int wert1, wert2, wert3;
	printf("werte eingeben\n");
	scanf("%d %d %d", &wert1, &wert2, &wert3);

	if(wert1 > wert2)
	{
		if(wert2 > wert3)
			printf("%d (wert1) ist der groeszte wert\n", wert1);

		if(wert3 > wert1)
			printf("%d (wert3) ist der groeszte wert\n", wert3);
	}
	else
	{
		if(wert2 > wert3)
			printf("%d (wert2) ist der groeszte wert\n", wert2);

		if(wert3 > wert2)
			printf("%d (wert3) ist der groeszte wert\n", wert3);
	}

	if(wert1 == wert2 && wert2 == wert3)
		printf("Die Werte sind alle Gleich grosz\n");

	system("Pause");
	return 0;
}
