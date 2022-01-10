#include <string.h>
#include <stdio.h>
#include <stdbool.h>


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

int printLeaderboardUsernameAndScore(int size, char username[100], char score[5])
{
	//char username[100] = "123456789012345";
	//char score[5];
	int usernameSize = 0;
	int scoreSize = 0;

	// --------

	printf("| ");
	
	int i=0;
	while (i<=100)
	{	
		if (username[i] == NULL)
		{
			break;
		}
		usernameSize++;
	//	printf("\nusername[%i] - %c\n",i,username[i]);
		i++;
	}

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
	
	printf("\n");

	//printLeaderboard(maxSize);
	printLeaderboardVBoarder(maxSize);
	printHeaderLeaderBoard(maxSize);
	printLeaderboardVBoarder(maxSize);
	printLeaderboardUsernameAndScore(maxSize,"sam","99999");
	printLeaderboardUsernameAndScore(maxSize,"samualwrightttttt","100");
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
