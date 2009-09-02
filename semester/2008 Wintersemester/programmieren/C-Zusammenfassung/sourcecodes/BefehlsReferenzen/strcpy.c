#include <stdio.h>
#include <string.h>

int main(void)
{
	char text[20];
	//Test
	strcpy(text, "Hallo!");
	printf("%s", text);
	strcpy(text, "Ja Du!");
	printf("%s", text);

	return 0;
}