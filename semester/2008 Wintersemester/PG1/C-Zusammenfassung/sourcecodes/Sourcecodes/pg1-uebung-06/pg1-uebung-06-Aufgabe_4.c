#include <stdio.h>

int main()
{
	int geld, muenzen[8], i;

	for(i = 0; i != 8; i++)
	{
		muenzen[i] = 0;
	}

	printf("Bitte Geld in Cent eingeben: ");
	scanf("%d", &geld);

	while(geld >= 200)
	{
		geld -= 200;
		muenzen[0]++;
	}

	while(geld >= 100)
	{
		geld -= 100;
		muenzen[1]++;
	}

	while(geld >= 50)
	{
		geld -= 50;
		muenzen[2]++;
	}

	while(geld >= 20)
	{
		geld -= 20;
		muenzen[3]++;
	}

	while(geld >= 10)
	{
		geld -= 10;
		muenzen[4]++;
	}

	while(geld >= 5)
	{
		geld -= 5;
		muenzen[5]++;
	}

	while(geld >= 2)
	{
		geld -= 2;
		muenzen[6]++;
	}

	while(geld >= 1)
	{
		geld -= 1;
		muenzen[7]++;
	}

	printf(" 2 Euro: %d\n", muenzen[0]);
	printf(" 1 Euro: %d\n", muenzen[1]);
	printf("50 Cent: %d\n", muenzen[2]);
	printf("20 Cent: %d\n", muenzen[3]);
	printf("10 Cent: %d\n", muenzen[4]);
	printf(" 5 Cent: %d\n", muenzen[5]);
	printf(" 2 Cent: %d\n", muenzen[6]);
	printf(" 1 Cent: %d\n", muenzen[7]);

	system("pause");
	return 0;
}