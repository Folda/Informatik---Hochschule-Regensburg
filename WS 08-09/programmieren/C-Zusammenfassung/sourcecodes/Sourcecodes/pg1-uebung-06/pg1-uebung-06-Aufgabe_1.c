//Benötigt <string.h>
void trim(char *text)
{
	int textlaenge, i;
	textlaenge = strlen(text);

	for(i = 0; i != textlaenge; i++)
	{
		printf("%d - '%c'\n",i ,text[i]);
	}

	while(text[0] == ' ')
	{
		for(i = 0; i != textlaenge; i++)
		{
			text[i] = text[i + 1];
		}

		textlaenge = strlen(text);
	}

	while(text[textlaenge - 1] == ' ')
	{
		text[textlaenge - 1] = '\0';
		textlaenge = strlen(text);
	}
}