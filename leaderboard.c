/*
 * Basically trying to get values from a CSV into two variables
 * you need to be able to split them then store them seperatly.
 *
 * works for the first few but not the rest.
 *
 * maybe the arrays just get full need to look at
 *
 */





#include <string.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int charToInt(char locationchar){

        // This function will returna char number to an int one
        return locationchar - '0';

}

char getLeaderboardInfoForSearchedUsername(char searchingUsername[96], int which){

	FILE *fp;
	char str[100]; //line
	char *username[96];
	int usernameLength = 0;
	char *score[4];
	int i;
	int pass = 0;
	int scorePointer;
	int found = 0;
	int lineInTXT=0;

	fp = fopen("leaderboard.txt","r");

	while (fgets(str,50,fp) && found == 0){
		lineInTXT++;
		usernameLength = 0;
		pass = 0;
		
		printf("\nLINE = %S\n",str);

		
		printf("\n\n---------------- NEW LINE -------------------- \n\n");

		for (i=0; i<=51; i++){
			
			

			if (str[i] != NULL){
			
			printf("\nstr=%c\n",str[i]);
			}
			if (str[i] == ','){
				pass = 1;
			
			}
			
			if (pass == 0 && str[i] != NULL){
				username[i] = str[i];
				usernameLength++;
				if (sizeof(username)<2){
				
					printf("\nusername: %c\n",username);
				}
			}
				else{printf("\nusername: %s\n",username);
			}

			if (pass == 1 && str[i] != NULL){
				scorePointer = i-usernameLength;
				score[scorePointer]=str[i];
			}

			if (strcmp(username,searchingUsername) == 0 && pass == 1){
				found = 1;
			}
		}

		if (found != 1){
			
		printf("\n\nsearchingUsername = %s\n\n",searchingUsername);
		memset(username,0,96);	
		memset(str,0,50);
		}
	}

	if (found == 1){
		int ii;
		char newScore[40];
		for (ii=1;ii<=sizeof(score)-1;ii++){
		
			newScore[ii-1] = score[ii];
		
			printf("\nscore = %c\n",newScore[ii-1]); /// SCORE NOT PRINTER START FROM HERE AND FIX GETTING THE , OUT OF THE SCORE
		}
	
		printf("\nusername = %s\n",username);

		if (sizeof(newScore)<2){
			
			printf("\nscore=%c\n",newScore);
		}

		else{printf("\nscore=%s\n",newScore);}

		printf("\nlineInTXT = %d\n",lineInTXT);
		
		char returnArray[3][96];

		int x;

		for (x=0; x<sizeof(username);x++){
			returnArray[0][i] = username[i];
		}

		for (x=0; x<sizeof(newScore);x++){
			returnArray[1][i] = newScore[i];
		}

	}

	else{printf("\nPlayer Not Found...");}
	fclose(fp);


}

void main(){
	
	char searchingUsername[96];
	
	char score[40];
	char username[96];
	char line[5];

	int which = 0;

	printf("\nEnter Username To Search For: ");
	scanf("%s",&searchingUsername);
//	username = getLeaderboardInfoForSearchedUsername(searchingUsername,1);
//	score = getLeaderboardInfoForSeachedUsername(searchingUsername,2);
//	line = getLeaderboardInfoForSeachedUsername(searchingUsername,3);

	printf("\nusername: %s\n",username);
	printf("\nscore: %d\n",score);
	printf("\nline: %d\n",line);

//	printf("%d",leaderboardArray);

}
