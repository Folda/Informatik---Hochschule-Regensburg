#include <stdio.h>

float CalcBMI (float Height, float Mass)
{
	return Mass / (Height * Height);
}

int main()
{
	float Height, Mass;

	printf("Bitte geben sie ihre Groesze in Metern an:\n");
	scanf("%f", &Height);

	printf("Bitte geben sie ihre Masse in Kilogramm an:\n");
	scanf("%f", &Mass);

	printf("Ihr Bodymassindex bei einer Hoehe von %f Metern und einem Gewicht von %f Kilogramm betraegt:\n%f\n", Height, Mass, CalcBMI(Height, Mass));

	system("pause");
	return 0;
}
