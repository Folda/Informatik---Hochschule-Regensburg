#include <stdio.h>

int main()
{
	float x = 5;
	float y = 3;
	float ergebnis;

	ergebnis = pow(x, 2) + y;

	printf ("Ergebnis von x^2 + y : %f\n", ergebnis);
	system ("PAUSE");
	return 0;
}
