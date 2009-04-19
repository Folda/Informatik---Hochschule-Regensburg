#include <stdio.h>
#include <string.h>
 
int main()
{
  const char string1[] = "Hello";
  const char string2[] = "World";
  const char string3[] = "Hello";
       
  if (strcmp(string1,string2) == 0)
  {
    printf("Die beiden Zeichenketten %s und %s sind identisch.\n",string1,string2);
  }
  else
  {
    printf("Die beiden Zeichenketten %s und %s sind unterschiedlich.\n",string1,string2);
  }
 
  if (strcmp(string1,string3) == 0)
  {
    printf("Die beiden Zeichenketten %s und %s sind identisch.\n",string1,string3);
  }
  else
  {
    printf("Die beiden Zeichenketten %s und %s sind unterschiedlich.\n",string1,string3);
  }     
       
  return 0;
}
