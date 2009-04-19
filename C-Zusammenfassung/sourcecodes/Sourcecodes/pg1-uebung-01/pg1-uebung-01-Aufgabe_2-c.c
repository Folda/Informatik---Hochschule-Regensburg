#include <stdio.h>

int main()
{
	float wert_a, wert_b, wert_c, wert_x, ergebnis;

	printf("Bitte geben sie die Werte für a, b, c und x in der form ax^2 + bx + c ein:\n");

	printf("Wert a:");
	scanf("%f", &wert_a);

	printf("Wert b:");
	scanf("%f", &wert_b);

	printf("Wert c:");
	scanf("%f", &wert_c);

	printf("Wert x:");
	scanf("%f", &wert_x);

	//Nach Horner siehe http://de.wikipedia.org/wiki/Horner-schema
	ergebnis = (wert_a * wert_x + wert_b) * wert_x + wert_c;

	printf("Das Ergebnis für %f*%f^2+%f*%f+%f lautet:\n%f\n", 
		wert_a, wert_x, wert_b, wert_x, wert_c, ergebnis);
	system("pause");
	return 0;
}
