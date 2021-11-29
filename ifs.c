#include<stdio.h>
#include<string.h>

void main(void)
{

	char name[50];
	
	printf("Please Enter Name: ");
	scanf("%s",name);

	if (strcmp(name,"sam") == 0)
	{
		
		printf("Hello Sam\n");

	}

	else{
	
		printf("Hello there\n");
	
	}
}
