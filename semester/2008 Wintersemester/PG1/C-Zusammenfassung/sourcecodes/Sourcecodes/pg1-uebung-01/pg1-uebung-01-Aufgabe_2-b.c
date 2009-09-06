#include <stdio.h>

int main()
{
	int euro;

	printf("Bitte Euro betrag eingeben: ");
	scanf("%i", &euro);

	euro = (euro / 36) * 36 + 18;
	printf("Das Ergebnis lautet: %i Euro\n", euro);

	system("pause");
	return 0;
}