#include <stdio.h>

//Personenstruktur
typedef struct Person{
	char vname*;
	char nname*;
	char ort*;
} Person;

Person Personen*;

char* z0[] = {"Meier", "Sepp", "Mannheim"};
char* z1[] = {"Huber", "Anton", "Regensburg"};
char* z2[] = {"Berger", "Franz", "Passau"};
char* z3[] = {"Winkler","Hans", "Regensburg"};
char* z4[] = {"Maler", "Horst", "Passau"};

void bubblesort()
{
	int i, j, swaped = 1;
	int firstchar, secondchar;

	for(j = 0; j != 10000; j++)
	{
		for(i = 0; i != 4; i++)
		{
			firstchar = (int)anschriften[i][0][0];
			secondchar = (int)tempanschriften[i + 1][0][0];

			if(secondchar > firstchar)
			{
				printf("%s -- %s\n", anschriften[i], anschriften[i + 1]);
				tempanschriften[0] = anschriften[i];
				anschriften[i] = anschriften[i + 1];
				anschriften[i + 1] = tempanschriften[0];
				printf("%s -- %s\n", anschriften[i], anschriften[i + 1]);
			}
		}
	}
}

int main()
{
	int i;
	bubblesort();

	for(i = 0; i != 5; i++)
	{
		printf("%s -- %s -- %s\n", anschriften[i][0], anschriften[i][1], anschriften[i][2]);
	}

	system("pause");
	return 0;
}