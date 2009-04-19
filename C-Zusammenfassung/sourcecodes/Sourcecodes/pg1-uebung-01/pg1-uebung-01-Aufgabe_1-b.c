#include <stdio.h> 

int main() 
{ 
	float a = 15;
	float b = 3; 
	float ergebnis; 

	ergebnis = 1 + (1 / (a + (1 / b)));

	printf ("Ergebnis von 1 + (1 / (a + (1 / b))): %f\n", ergebnis);
	system ("PAUSE"); 
	return 0; 
} 
