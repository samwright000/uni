#include <stdio.h>

char* myName(char number[1])
{

	char* name;

	name = "my name is sam";
	
	if (number == '1'){
	return name;
	}


	return "test";

}

void main()
{
	
	char* *string[100];
	
	char option[100] = '1';


	*string = myName(option);

	printf("string = %s",*string);

}
