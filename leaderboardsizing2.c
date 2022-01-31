#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void returnString(char* str)
{
	strcpy(str,"sam");
}

void main()
{
	int i;

	char username[100];

	returnString(username);

	printf("size of string = %d",sizeof(username));

	printf("USERNAME = %s",username);
}
