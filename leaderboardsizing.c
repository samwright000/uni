#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int charToInt(char locationchar){

        // This function will returna char number to an int one
        return locationchar - '0';

}

// FOR SOME REASON ONLY PRINITING one charter for leaderboard, find the change and fix it.




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
	//printf("\nUSERNAME 	SCORE\n");
	memset(line,0,100);
	memset(foundScore,0,50);
	memset(foundUsername,0,50);


	//printf("2.3\n");

	
	while (fgets(line,100,fp) && found == 0)
	{

		lineNumber++;
//		printf("\n%s\n",line);
		
		int i;
		sizeOfUsername = 0;
		pass = 0;
		for (i=0; i<=sizeof(line); i++)
		{
	//		printf("\nline[i] = %c\n",line[i]);
			
			if (line[i] == NULL){
			
				
			}

			if (line[i] == ',')
			{
				pass = 1;
			}

			else if (line[i] != NULL && pass == 0){
	//			printf("2.5\n");
				foundUsername[i]=line[i];
		//		printf("\nfound username: %s\n",foundUsername);
				sizeOfUsername++;
			}

			if  (line[i] != NULL && pass == 1){
	//			printf("\nIn Found Score\n");
		//		printf("2.6\n");
				
				foundScore[i-sizeOfUsername]=line[i+1];
		//		printf("\nfound score: %s \n",foundScore);
			}
		
		}	

	//	printf("2.3\n");

		if (lineNumber == searchingForLineNumber){
		
			if (usernameOrScore == 0)
			{
				int intFoundUsername = foundUsername;
	//			printf("intFoundUsername = %i");
	//			printf("\nUSENRAME = %s\n",foundUsername);
				return; //usnenrame;
			}

			if (usernameOrScore == 1)
			{
	//			printf("\nSCORE = %s\n",foundScore);
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
		
	//	printf("\nLINE = \n%s",line);
		memset(line,0,100);
		memset(foundUsername,0,50);
		memset(foundScore,0,50);
	}	


}

int printLeaderboardVBoarder(int size)
{
	int addSize;
	int i;

	printf("+-");
	printf("--------");

	if (size > 8 ){
		addSize = size - 8;
		
		for (i=0; i<=addSize; i++)
		{
			printf("-");
		}		
	}
	
	printf("-+");

	printf("-------+\n");

	return 0;
}

int printHeaderLeaderBoard(int size)
{
	int addSize;
	int i;

	printf("| Username ");
	
	if (size > 8)
	{
		addSize = size - 8;
		
		for (i=0; i<=addSize; i++)
		{
			printf(" ");
		}
	}

	printf("| Score |\n");



}


int printLeaderboardUsernameAndScore(int size, char username[100], char score[100])
{
	//char username[100] = "123456789012345";
	//char score[5];
	int usernameSize = 0;
	int scoreSize = 0;

//	printf("\n inprint leaderboardusenrameandscore\n");
//	printf("\nUSERNAME 3 = %s\n",username);
	//printf("\nSCORE 3 = %i\n",score);

	// --------

//	printf("\nin\n");


	printf("| ");
	
	int i=0;
//	printf("\nin2\n");
	
	while (i<=100)
	{
//		printf("\n in while \n");
		//printf("username = %c",username);	
//		printf("after username");
		if (username[i] == NULL)
		{
//			printf("\nin if username\n");
			break;
		}
		usernameSize++;
	//	printf("\nusername[%i] - %c\n",i,username[i]);
		i++;
	}

	//printf("\nin3\n");
	
	i=0;
	while (i<=5)
	{
		if (score[i] == NULL)
		{
			break;
		}
		scoreSize++;
		i++;


	}

	//printf("\nDEBUG - username size %i\n",usernameSize);

	
	int sizeCorrect;

	if (usernameSize < 8)
	{
	//	printf("\nDEBUG - Username size < 8\n");
		sizeCorrect = size - usernameSize;
		printf("%s",username);

		for (i=0;i<=sizeCorrect;i++)
		{
			printf(" ");
		}


	}

	if (usernameSize > 8)
	{
//		printf("\nDEBUG - username size > 8\n");
		sizeCorrect = size-usernameSize ;
		printf("%s",username);

		for (i=0;i<=sizeCorrect;i++)
		{
			printf(" ");

		}
	}

	if (usernameSize == 8)
	{
		printf("%s",username);
		for (i=0;i<=sizeCorrect-3;i++)
                {
                        printf(" ");

                }

	}

	printf(" | ");


	int scoreSizeCorrect = 0; 
	int intScore;

	intScore = charToInt(score);

	for (i=0;i<sizeof(score);i++){
	
//		printf("score[i] = %c\n",score[i]);
	}

	printf("%s",score);

	scoreSizeCorrect = 5 - scoreSize; // its very unlikely to have user with greater than 99999 score so just doing it to the spacing of the word score

	for (i=0;i<=scoreSizeCorrect;i++)
	{
		printf(" ");
	}

	printf("|");
	printf("\n");	



	return 0;
}

int getMaxUsernameSize()
{
	FILE *fp; 
	char line[100];
	char foundUsername[100];
	int pass = 0;
	int currentSizeUsername;
	int maxSizeUsername = 0;

	fp = fopen("leaderboard.txt","r");

	while (fgets(line,100,fp))
	{
		currentSizeUsername = 0;
		int i;

		for (i=0;i<=sizeof(line);i++)
		{
			if (line[i] == ',')
			{
				break;
			}

			if (line[i] != NULL)
			{
				currentSizeUsername++;
			}
		}


		if (currentSizeUsername > maxSizeUsername)
		{
			maxSizeUsername = currentSizeUsername;
	//		printf("\nMAX SIZE = %i",maxSizeUsername);
		}
		
	}

	return maxSizeUsername;

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
// workout the number of lines in the file
// then after that create 2 functions one that returns the name for hte line number
// and one that returns the score (might of already been made)
// 
// then after that create a function that runs both for each line number and adds the result to an array
//
// then from this we should have an 2 arrays one with all the usernames
// and on with all the scores for each username in the same location
// the array will be created in the main fuction so the array will be created there
//
// then in main will make something which looks for the highest score 
// and then prints the highest score and username. 
}


void createArrays(char usernames[50][100], char scores[50][5])
{
//	printf("in");
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
//	printf("%s\n",usernames[i]);
//	printf("%s\n",scores[i]);
	}

//	printf("usernames = %s",usernames[1]);
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
//              printf("\nusername = %s",usernames[i]);
//              printf("\nscore = %s",scores[i]);
                strcpy(temp_usernames[temp_location], usernames[i]);
                temp_location++;
                }
                else{
//                      printf("removing username = %s",usernames[i]);
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


void main()
{
//	printf("\n1\n");

	int maxSize = getMaxUsernameSize();
	int numberOfLinesFile;
	char username[100];
	char score[100];
	int i;
	char scores [50][5]; // 50 players with 5 digits for there score
	char usernames[50][100]; // 50 players with 100 digits 

	numberOfLinesFile = numberOfLinesLeaderboard();
	
	createArrays(usernames, scores);

	int currentScoreLocation;
	char currentScore[5];

	int currentHighestScore = 0;
	int currentHighestScoreLocation = 1;
	char currentHighestScoreString[5];	
	
	int numberOfTimesToRun = 0;
	
	currentHighestScoreLocation = 1;
	currentHighestScore=0;
	
	printLeaderboardVBoarder(maxSize);
	printHeaderLeaderBoard(maxSize);
	printLeaderboardVBoarder(maxSize);
	

	// CREATED REMOVE ARRAY NOW JUST NEED TO GET IT SO GETS THE HIGHEST SCORE LOCATION



	/*
	for (i=1;i<=numberOfLinesFile;i++){
		printUsernameOrScore(i,0,username,score);
		printUsernameOrScore(i,1,username,score);
		
		printLeaderboardUsernameAndScore(maxSize,username,score);
	}
*/
	printLeaderboardVBoarder(maxSize);

	/*
	 * Ok so the working out the correct spacing is good enough, could improve by
	 * making the score also ajust size but is unlikely for someone to have such a high score. 
	 *
	 * next bit is so that that the ...UsernameAndScore function is then ran for every 
	 * username, this should be ok just use the current way it is printed, then
	 * get the username and score for the user. 
	 *
	 * that would to be to do it simiply
	 * just remembered that we want to do it in the order of highest score to lowest score.
	 *
	 * so instead the next task is to add each username and score to the arrays then search
	 * though the array for the highest score, then print the username and score for
	 * that score. then remove it from the list so then print the next highest score
	 *
	 * so task:
	 * 	- carray array of all the usernames and score 2 different arrys but have the username and score 
	 * 	in the same location
	 * 	
	 * 	- then make something which searches though the list looking for the highest score.
	 * 	which then prints that username and score then removes it - then look for the highest
	 * */
}
