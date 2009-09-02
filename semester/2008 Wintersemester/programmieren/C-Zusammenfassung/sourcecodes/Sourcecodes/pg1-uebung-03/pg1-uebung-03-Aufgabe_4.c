#include <stdio.h>

int ggT(int a, int b)
{
	int h;

	while(b != 0)
	{
		h = a % b;
		a = b;
		b = h;
	}

	return a;
}

int main()
{
	int wert1, wert2;
	printf("wert1 und wert2 eingeben\n");
	scanf("%d %d", &wert1, &wert2);

	printf("der groeszte gemeinsamme teiler ist %d\n", ggT(wert1, wert2));

	system("pause");
	return 0;
}
