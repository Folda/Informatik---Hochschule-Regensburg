#include <stdio.h>

int main()
{
	long long int wert;
	unsigned long long int ergebnis;

	ergebnis = 0;
	printf("geben sie die den wert ein\n");
	scanf("%lld", &wert);

	int i;
	for(i = 0; i != wert; i++)
	{
		ergebnis += (i + 1)*(i + 1);
	}

	printf("die quadratsumme ist:\n%llu\n", ergebnis);

	system("pause");
	return 0;
}
