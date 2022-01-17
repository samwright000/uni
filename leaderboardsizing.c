#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>



// FOR SOME REASON ONLY PRINITING one charter for leaderboard, find the change and fix it.




char * printUsernameOrScore(int searchingForLineNumber, int usernameOrScore){
	//printf("2.1\n");
	
	FILE *fp;
	char line[100];
	char foundUsername[50];
	char foundScore[50];
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
				printf("2.5\n");
				foundUsername[i]=line[i];
		//		printf("\nfound username: %s\n",foundUsername);
				sizeOfUsername++;
			}

			if  (line[i] != NULL && pass == 1){
				printf("\nIn Found Score\n");
		//		printf("2.6\n");
				
				foundScore[i-sizeOfUsername]=line[i+1];
		//		printf("\nfound score: %s \n",foundScore);
			}
		
		}	

		printf("2.3\n");

		if (lineNumber == searchingForLineNumber){
		
			if (usernameOrScore == 0)
			{
				int intFoundUsername = foundUsername;
				printf("intFoundUsername = %i");
				printf("\nUSENRAME = %s\n",foundUsername);
				return foundUsername;
			}

			if (usernameOrScore == 1)
			{
				printf("\nSCORE = %s\n",foundScore);
				int intFoundScore = foundScore;
				return (char *)foundScore; 
			}
		}
		
		printf("\nLINE = \n%s",line);
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

	printf("\n inprint leaderboardusenrameandscore\n");
	printf("\nUSERNAME 3 = %s\n",username);
	//printf("\nSCORE 3 = %i\n",score);

	// --------

	printf("\nin\n");


	printf("| ");
	
	int i=0;
	printf("\nin2\n");
	/*
	while (i<=100)
	{
		printf("\n in while \n");
		//printf("username = %c",username);	
		printf("after username");
		if (username[i] == NULL)
		{
			printf("\nin if username\n");
			break;
		}
		usernameSize++;
	//	printf("\nusername[%i] - %c\n",i,username[i]);
		i++;
	}*/

	printf("\nin3\n");
	
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
	}

	printf(" | ");


	int scoreSizeCorrect = 0; 
	printf("%s",score);

	scoreSizeCorrect = 5 - scoreSize; // its very unlikely to have user with greater than 99999 score so just doing it to the spacing of the word score

	for (i=0;i<=scoreSizeCorrect;i++)
	{
		printf(" ");
	}
	
	printf("|\n");


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
			printf("\nMAX SIZE = %i",maxSizeUsername);
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

void main()
{
	int maxSize = getMaxUsernameSize();
	int numberOfLinesFile;
	char *username;
	//printf("\nUSERNAMMMMME %s\n",*username);
	char *score[100];
	int i;

	numberOfLinesFile = numberOfLinesLeaderboard();

	printf("\n");

	//printLeaderboard(maxSize);
	
	printLeaderboardVBoarder(maxSize);
	printHeaderLeaderBoard(maxSize);
	printLeaderboardVBoarder(maxSize);

	printf("\n1\n");	
	for (i=1;i<=numberOfLinesFile;i++){
		printf("2\n");
		username = printUsernameOrScore(i,0);
		printf("3\n");
		*score = printUsernameOrScore(i,1);
		
		printf("\nUSERNAME 2 = %s\n",username);
		printf("\nSCORE 2 = %s\n",*score);

		printf("\n222\n");
		printLeaderboardUsernameAndScore(maxSize,username,score);

		printf("\n111\n");
	}

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
