#include <stdio.h>

int main()
{
	int cent, euro;

	printf("Bitte geben sie den Cent Betrag ein der in Euro umgerechnet werden soll:\n");
	scanf("%d", &cent);

	euro = (cent + 99) / 100;

	printf("%d Cent sind %d Euro\n", cent, euro);

	system("pause");
	return 0;
}
