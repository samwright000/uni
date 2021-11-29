#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char shiftLetter(char c, int shiftValue){
	
	int cValue;
	int goOver;

	//printf("\n c = %c\n",c);
	//printf("\n shiftValue = %d\n",shiftValue);

	cValue = c;

	if (shiftValue > 25){

		shiftValue = shiftValue % 26;
	
	}

	if (cValue > 64 && cValue < 91 && cValue != 32){
	
		cValue = cValue - 65;
		cValue = cValue + shiftValue;
		cValue = cValue % 26;
		cValue = cValue + 65;	

	}

	else if (cValue > 96 && cValue < 123 && cValue != 32){
	
		cValue = cValue - 96;
		cValue = cValue + shiftValue;
		cValue = cValue % 26;
		cValue = cValue + 96;
	}



	
//	printf("DEBUG | cValue = %d",cValue);

	//printf("\nDEBUG | cValue = %d\n",cValue);
	
	c = cValue;

	//printf("\nDEBUG | (shiftLetter) c = %c\n",c); 

	return c; 

}

void main(void){

	system("clear");

	char plaintext[25] = "";
	int shiftValue;
	char cipherC;
	char *ciphertext[25];
	int i;
	char newString[25];


	printf("\nPlease Enter Input: ");
	scanf("%[^\n]%*c",plaintext);

	printf("\nPlease Enter Shift Value: ");
	scanf("%d",&shiftValue);

//	printf("\nDEBUG | (main) plaintext = %s\n",plaintext);
//	printf("\nDEBUG | (main) shiftValue = %d\n",shiftValue);
	
	printf("\n");
	printf("OUTPUT: ");
	for (i=0; i<sizeof(plaintext);i++){

		if (plaintext[i] != NULL) {
		
		//	printf("\nDEBUG | (main) plaintext[] = %c\n",plaintext[i]);
		//	printf("\nDEBUG | (main) i = %d\n",i);	
			
			//if (strcmp(plaintext[i]," ")==0){printf("SPACE");}
			
			cipherC=shiftLetter(plaintext[i],shiftValue);
			printf("%c",cipherC);
		}
	}

	printf("\n");




}
