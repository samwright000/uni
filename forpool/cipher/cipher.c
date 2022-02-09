/*
 *
 * updated for the first feed back given
 *
*/ 



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int charToInt(char locationchar){

        // This function will returna char number to an int one
        return locationchar - '0';

}


char shiftLetter(char c, int shiftValue){
	
	int cValue;
	int goOver;

	//printf("\n c = %c\n",c);
	//printf("\n shiftValue = %d\n",shiftValue);

	cValue = c;

	if (shiftValue > 25){

		shiftValue = shiftValue % 26; // makes the shifing cirular - if you enter 27 it would be as if you entered 1
	
	}

	if (cValue > 64 && cValue < 91){
	// this is for capitals
		cValue = cValue - 65; // 0s the value to make a = 0 so then we are able to apply the mod which devides and gives the remainder we mod my 26 as there are 26 letters
		cValue = cValue + shiftValue;
		cValue = cValue % 26;
		cValue = cValue + 65;	

	}

	else if (cValue > 96 && cValue < 123){
	// lower case letters
		cValue = cValue - 97;
		cValue = cValue + shiftValue;
		cValue = cValue % 26;
		cValue = cValue + 97;

	}

	// if it is not lower case or upper case it will not be shifed it will also not be shifted if it is a space which is the 32 



	
//	printf("DEBUG | cValue = %d",cValue);

	//printf("\nDEBUG | cValue = %d\n",cValue);
	
	c = cValue;

	//printf("\nDEBUG | (shiftLetter) c = %c\n",c); 

	return c; 

}

void main(void){

	system("clear");


	char plaintext[25] = "";
	char strShiftValue[5];
	int shiftValue;
	char cipherC;
	char *ciphertext[25];
	char newString[25];
	memset(strShiftValue,0,5);

	printf("\nPlease Enter Input (non-letters will be ignored): ");
	scanf("%[^\n]%*c",plaintext);

	
	//	printf("2");
		int i;
		int valid=0;
		
		while (true){
			printf("\nPlease Enter Shift Value:");
			scanf("%s",&strShiftValue);
//			printf("\n%s strShiftValue\n",strShiftValue);
		
			shiftValue = atoi(strShiftValue);

			if (shiftValue < 1){system("clear"); printf("\nOnly enter Numbers, greater than 0!\n");}
			if (shiftValue > 0){break;}

		}
			
			
			shiftValue=atoi(strShiftValue);		
//			printf("\nSHIFT VALUE = %d\n",shiftValue);	
		
		

	//	printf("1");
	//	if (!isdigit(shiftValue)){printf("enterd a number");break;}


//	printf("\nDEBUG | (main) plaintext = %s\n",plaintext);
//	printf("\nDEBUG | (main) shiftValue = %d\n",shiftValue);
	
	printf("\n");
	printf("\n   INPUT: %s\n",plaintext);
	printf("  OUTPUT: ");

	// below goes though each digit in the array inputs the char and the shift value 
	// I have done it like this so the way it is shifted could be completely different but I am progaming 
	// to the interface so the way it would be dealt with (printed) would be the same 
	//
	for (i=0; i<sizeof(plaintext);i++){

		if (plaintext[i] != NULL) {
		
		//	printf("\nDEBUG | (main) plaintext[] = %c\n",plaintext[i]);
		//	printf("\nDEBUG | (main) i = %d\n",i);	
			
			//if (strcmp(plaintext[i]," ")==0){printf("SPACE");}
			

	//		int intShiftValue;

	//		intShiftValue = charToInt(shiftValue);
			
			cipherC=shiftLetter(plaintext[i],shiftValue);	
			
			printf("%c",cipherC);
		}
	}

	printf("\n\n");


	

}
