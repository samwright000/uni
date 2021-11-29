#include <string.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


void main(){

	FILE *fp;
	char str[100];
	char username[96];
	char score[4];
	int i;
	int stop = 0;

	char searchingUsername[96];

	printf("\nEnter Username To Search For: ");
	scanf("%s",&searchingUsername);

	fp = fopen("leaderboard.csv","r");
	while (fgets(str,50,fp)){
		
		for (i=0; i<50; i++){
			if (str[i] != ','){
			
				username[i] = str[i];
			}
			else{break;}
			printf("\n%s",username);
			printf("\n%s",str);

		
		}
		 	

		if (strcmp(username,searchingUsername) == 0){
		
			printf("\nusername: %s\n",username);
			//get the score for the username found
			
			break;
		}
		
		

	}

	fclose(fp);

}
