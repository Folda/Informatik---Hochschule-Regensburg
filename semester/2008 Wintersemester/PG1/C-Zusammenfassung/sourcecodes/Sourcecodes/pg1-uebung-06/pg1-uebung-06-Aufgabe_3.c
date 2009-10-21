#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubblesort(int *array, int length)
{
	int i, j;
	for (i = 0; i < length; ++i) {
		for (j = 0; j < length - i - 1; ++j) {
			if (array[j] > array[j + 1]) {
				int tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
	}
}

int main()
{
	int zahlen[6];
	int i;
	srand(time(NULL));

	for(i = 0; i != 6; i++)
	{
		zahlen[i] = rand()%49+1;
	}

	bubblesort(&zahlen, 6);

	printf("Die Lottozahlen lauten:\n");

	for(i = 0; i != 6; i++)
	{
		printf("%d\n", zahlen[i]);
	}

	printf("Die Zusatzzahl lautet: %d\n", rand()%49+1);
	system("pause");
	return 0;
}