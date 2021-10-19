#include<stdio.h>
#include<string.h>
<<<<<<< HEAD
=======
#include<ctype.h>


//TESTESTESDdddddddddddddddddddddddd

>>>>>>> fd5620347f370a377a0d1936a6ebb7d60e79f5b7
void main(void)
{

	int shiftValue;
	char toShift[50];
<<<<<<< HEAD

=======
	int i;
>>>>>>> fd5620347f370a377a0d1936a6ebb7d60e79f5b7
	printf("Please Enter Shift Value: ");
	scanf("%i",&shiftValue);
	
	printf("Please Enter String To Be Encrptyed: ");
	scanf("%s",toShift);
<<<<<<< HEAD
	int i;
=======
	
	for (i=0; i<strlen(toShift);i++){
	
	toShift[i]=toupper(toShift[i]);
	}	
	
>>>>>>> fd5620347f370a377a0d1936a6ebb7d60e79f5b7
	for (i=0; i<strlen(toShift);++i){

		char charToShift = toShift[i];
		
		int  asciiValue;

		asciiValue = ("%i",charToShift); 
		//printf("%i",asciiValue);
	        charToShift = charToShift+shiftValue;
		
		//printf ("%c",toShift[i]);
		printf ("%c",asciiValue+shiftValue);	       
		
	}

<<<<<<< HEAD


=======
>>>>>>> fd5620347f370a377a0d1936a6ebb7d60e79f5b7
	//char ascii;
	//printf("Please enter letter: ");
	//scanf("%c",&ascii);
	//printf("%i\n",ascii);
<<<<<<< HEAD
	



=======
>>>>>>> fd5620347f370a377a0d1936a6ebb7d60e79f5b7
}
