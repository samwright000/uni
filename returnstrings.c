#include <stdio.h>

char* myName()
{

	char *name = "my name is sam";
	return name;

}

void main()
{
	
	char *string[100];

	*string = myName();

	printf("string = %s",*string);

}
