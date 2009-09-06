#include <stdio.h>

int main()
{
	double ergebnis, counter;
	ergebnis = counter = 0;

	for(counter = 1; ergebnis <= 3; counter++)
	{
		ergebnis += 1 / counter;
		printf("counter: %f -- ergebnis: %f -- ", counter, ergebnis);
		printf("zw: %f\n", 1 / counter);
	}

	printf("sie uebersteigt 3 bei einem wert von %.0f\n",counter-1);
	system("pause");
	return 0;
}
