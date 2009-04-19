#include <stdio.h>

float FarToCel(float Fahrenheit)
{
	return (Fahrenheit - 32) / 1.8;   
}

float CelToFar(float Celsius)
{
	return Celsius * 1.8 + 32;
}

int main()
{
	int Entscheidung_FaroderCel;
	float Fahrenheit, Celsius;

	printf("Wollen sie von Farenheit in Celsius umrechnen (1)?\noder wollen sie von Celsius in Farenheit umrechnen (2)?\n");
	scanf("%d", &Entscheidung_FaroderCel);

	switch(Entscheidung_FaroderCel)
	{
	case 1:
		printf("Bitte geben sie die Grad Farenheit ein\n");
		scanf("%f", &Fahrenheit);
		Celsius = FarToCel(Fahrenheit);
		printf("%f Grad Farenheit sind %f Grad Celsius\n", Fahrenheit, Celsius);
		break;

	case 2:
		printf("Bitte geben sie die Grad Celsius ein\n");
		scanf("%f", &Celsius);
		Fahrenheit = CelToFar(Celsius);
		printf("%f Grad Celsius sind %f Grad Farenheit\n", Celsius, Fahrenheit);
		break;

	default :
		printf("Es wurde keine Operation ausgewaehlt!\n");
		break;
	}

	system("pause");
	return 0;
}
