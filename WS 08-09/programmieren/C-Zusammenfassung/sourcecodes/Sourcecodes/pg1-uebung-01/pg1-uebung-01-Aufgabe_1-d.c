#include <stdio.h>

int main()
{
	float x = 5;
	float y = 3;
	float ergebnis;

	ergebnis = pow(x + y, 4);

	printf ("Ergebnis von (x + y)^4 : %f\n", ergebnis);
	system ("PAUSE");
	return 0;
}
