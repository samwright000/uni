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
/*
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
*/


void printUsernameOrScore(int searchingForLineNumber, int usernameOrScore,char* foundUsername, char* foundScore){
        //printf("2.1\n");

        FILE *fp;
        char line[100];
        //char foundUsername[50];
        //char foundScore[50];
        int pass = 0;
        int found = 0;
        int lineNumber=0;
        int sizeOfUsername =0;

        fp = fopen("leaderboard.txt","r");

        //printf("searchingUsername: %s ",searchingUsername);
        //printf("2.2\n");
        //printf("\nUSERNAME    SCORE\n");
        memset(line,0,100);
        memset(foundScore,0,50);
        memset(foundUsername,0,50);


        //printf("2.3\n");


        while (fgets(line,100,fp) && found == 0)
        {

                lineNumber++;
//              printf("\n%s\n",line);

                int i;
                sizeOfUsername = 0;
                pass = 0;
                for (i=0; i<=sizeof(line); i++)
                {
        //              printf("\nline[i] = %c\n",line[i]);

                        if (line[i] == NULL){


                        }

                        if (line[i] == ',')
                        {
                                pass = 1;
                        }

                        else if (line[i] != NULL && pass == 0){
        //                      printf("2.5\n");
                                foundUsername[i]=line[i];
				//printf("\nfound username: %s\n",foundUsername);
                                sizeOfUsername++;
                        }

                        if  (line[i] != NULL && pass == 1){
        //                      printf("\nIn Found Score\n");
                //              printf("2.6\n");

                                foundScore[i-sizeOfUsername]=line[i+1];
                //              printf("\nfound score: %s \n",foundScore);
                        }

                }

        //      printf("2.3\n");

                if (lineNumber == searchingForLineNumber){

                        if (usernameOrScore == 0)
                        {
                                int intFoundUsername = foundUsername;
        //                      printf("intFoundUsername = %i");
        //                      printf("\nUSENRAME = %s\n",foundUsername);
                                return; //usnenrame;
                        }

                        if (usernameOrScore == 1)
                        {
        //                      printf("\nSCORE = %s\n",foundScore);
                                int intFoundScore = foundScore;

                                char temp_score[50];
                                char *token;
                                char toRemove[2]="\n";
                                //printf("\n");
                                //printf("before");
                                //printf("%s = score",foundScore);
                                //printf("...");

                                strtok(foundScore,"\n");

                                //printf("after");
                                //printf("%s = tempscore",foundScore);
                                //printf("...");
                                //printf("\n");

                                return; //foundScore;
                        }
                }

        //      printf("\nLINE = \n%s",line);
                memset(line,0,100);
                memset(foundUsername,0,50);
                memset(foundScore,0,50);

		        }


}



int numberOfLinesLeaderboard()
{

        FILE *fp;
        char line[100];
        char numberOfLinesInFile = 0;

        fp = fopen("leaderboard.txt","r");

        while (fgets(line,100,fp))
        {

                numberOfLinesInFile++;

        }

        return numberOfLinesInFile;
}

void createArrays(char usernames[50][100], char scores[50][5])
{
//      printf("in");
        int i;
        int numberOfLines;

        //char scores [50][5]; // 50 players with 5 digits for there score
        //char usernames[50][100]; // 50 players with 100 digits 

        char username[100];
        char score[100];
        numberOfLines = numberOfLinesLeaderboard();

        for (i=0;i<=numberOfLines;i++){

                int ii;

                printUsernameOrScore(i,0,username,score); //username = 0 score = 1

                for (ii=0;ii<=sizeof(username);ii++){

                        usernames[i][ii] = username[ii];
                        scores[i][ii] = score[ii];
                }

        //printf("%c",usernames[1][0]);
//      printf("%s\n",usernames[i]);
//      printf("%s\n",scores[i]);
        }

//      printf("usernames = %s",usernames[1]);
}

void removeFromArray(int location, char usernames[50][100], char scores[50][5]){

        printf("username = %s\n", usernames[0]);
        printf("username = %s\n", usernames[1]);
        printf("username = %s\n", usernames[2]);
        printf("username = %s\n", usernames[3]);
        printf("username = %s\n", usernames[4]);
        printf("username = %s\n", usernames[5]);
        printf("username = %s\n", usernames[6]);
        printf("username = %s\n", usernames[7]);


	int i;
	char temp_usernames[50][100];
	char temp_scores[50][5];
	int temp_location=0;

	printf("\nlocation to remove = %d\n",location);

	for (i=1;i<=50;i++){

		if (i!=location){
//		printf("\nusername = %s",usernames[i]);
//		printf("\nscore = %s",scores[i]);
		strcpy(temp_usernames[temp_location], usernames[i]);
		temp_location++;
		}
		else{
//			printf("removing username = %s",usernames[i]);
		}
	}
	printf("\n");
	for (i=0;i<=50;i++){
		strcpy(usernames[i],temp_usernames[i]);
	}
	printf("username = %s\n", usernames[0]);
	printf("username = %s\n", usernames[1]);
	printf("username = %s\n", usernames[2]);
	printf("username = %s\n", usernames[3]);
	printf("username = %s\n", usernames[4]);
	printf("username = %s\n", usernames[5]);
	printf("username = %s\n", usernames[6]);
	printf("username = %s\n", usernames[7]);
	printf("\n");
}


void main(){

	char usernames[50][100];
        memset(usernames,0,sizeof(usernames[0][0])*50*100);

	char scores[50][5];
	memset(scores,0,sizeof(scores[0][0])*50*5);


	createArrays(usernames, scores);


	removeFromArray(2,usernames,scores);



	printf("\n");
}
