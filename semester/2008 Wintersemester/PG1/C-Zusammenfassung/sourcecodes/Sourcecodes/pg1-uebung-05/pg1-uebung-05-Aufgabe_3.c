struct stackstruct
{
	int items[20];
	int toppos;
	int itemcount;
};

struct stackstruct Stack;

void push(int zahl)
{
	if(Stack.toppos != 20)
	{
		Stack.toppos++;
		Stack.items[Stack.toppos] = zahl;
		Stack.itemcount++;
	}
	else
		printf("Der Stack ist bereitz voll!\n");
}

int pop()
{
	int returnvalue;

	if(Stack.itemcount != 0)
	{
		returnvalue = Stack.items[Stack.toppos];
		Stack.items[Stack.toppos] = 0;
		Stack.toppos--;
		Stack.itemcount--;
	}
	else
	{
		printf("Der Stack ist leer!\n");
		returnvalue = 0;
	}

	return returnvalue;
}

int peek()
{
	int returnvalue;
	if(Stack.itemcount != 0)
	{
		returnvalue = Stack.items[Stack.toppos];
	}
	else
	{
		printf("Der Stack ist leer!\n");
		returnvalue = 0;
	}

	return returnvalue;
}
