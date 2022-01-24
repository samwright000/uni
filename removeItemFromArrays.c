#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void printArray(char usernames[50][100]){
	
	int i;

	for (i=0; i<=50; i++){

		int ii;
		for (ii=0; ii<=100; ii++){
		if(usernames[i][ii]!= NULL){printf("%c",usernames[i][ii]);}
		}
		
	}
}

void removeItemFromArry(char usernames[50][100], char scores[50][5],locationToRemove){


	char temp_usernames[50][100];

	int i;

	for (i=0;i<=sizeof(usernames);i++){
	
		int ii;

		for (ii=0;ii<=sizeof(usernames[50]);ii++){
		
			if (i!=locationToRemove //////
		
		
		}
	
	}


}

void main(){

	char usernames[50][100];
        memset(usernames,0,sizeof(usernames[0][0])*50*100);

	char scores[50][5];

	usernames[0][0] = 'h';
	usernames[0][1] = 'e';
	usernames[0][2] = 'y';

	printArray(usernames);

	removeItemFromArry(usernames,scores);


}
