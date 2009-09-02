#include <stdio.h> 

int main() 
{ 
	float x = 15;
	float y = 3; 
	float ergebnis; 

	ergebnis = (x + y) / (2 * x - y); 

	printf ("Ergebnis von (x + y) / (2*x - y): %f\n", ergebnis); 
	system ("PAUSE"); 
	return 0; 
} 
