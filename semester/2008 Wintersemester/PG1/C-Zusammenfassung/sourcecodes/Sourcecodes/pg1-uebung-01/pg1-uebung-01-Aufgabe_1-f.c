#include <stdio.h>

int main()
{
	float x = 5;
	float y = 3;
	float ergebnis;

	ergebnis = (x + y) *37 - (pow(x, 3) + pow(y, 3));

	printf ("Ergebnis von (x + y) * 37 - x^3) + y^3)) : %f\n", ergebnis);
	system ("PAUSE");
	return 0;
}
