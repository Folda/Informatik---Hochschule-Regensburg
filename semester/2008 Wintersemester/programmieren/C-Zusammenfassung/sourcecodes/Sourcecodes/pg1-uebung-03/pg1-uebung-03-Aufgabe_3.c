#include <stdio.h>

int main()
{
	int tag, monat, jahr, tagtypwert;

	printf("geben sie tag, monat und jahr ein\n");
	scanf("%d %d %d", &tag, &monat, &jahr);

	tagtypwert = (tag + 2*monat + (3*monat+3) / 5 + jahr + jahr / 4 - jahr / 100 + jahr / 400 + 1 ) % 7;

	printf("der %d. %d. %d ist ein ", tag, monat, jahr);
	switch(tagtypwert)
	{
	case 0:
		printf("Sonntag\n");
		break;

	case 1:
		printf("Montag\n");
		break;

	case 2:
		printf("Dienstag\n");
		break;

	case 3:
		printf("Mittwoch\n");
		break;

	case 4:
		printf("Donnerstag\n");
		break;

	case 5:
		printf("Freitag\n");
		break;

	case 6:
		printf("Samstag\n");
		break;                           
	}

	system("Pause");
	return 0;
}
