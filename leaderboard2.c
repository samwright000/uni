#include <string.h>
#include <stdio.h>
#include <stdbool.h>


int charToInt(char strscore){
	//printf("\n!!!chartoint strscore = %cs\n",strscore); // trying to print out score and player name in main not working try looking here to set if got correctly - coming out with weird results when printed
	return strscore-'0';
}

int getLineNumberLeaderboard(char searchingUsername[50])
{

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

	
	while (fgets(line,100,fp) && found == 0)
	{

		lineNumber++;
//		printf("\n%s\n",line);
		
		int i;
		sizeOfUsername = 0;
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
				foundUsername[i]=line[i];
				//printf("\nfound username: %s\n",foundUsername);
				sizeOfUsername++;
			}

			if (line[i] != NULL && pass == 1){
				//printf("\nIn Found Score\n");
				
				
				foundScore[i-sizeOfUsername]=line[i];
				//printf("\nfound score: %s \n",foundScore);
			}

		
		}

		if (strcmp(foundUsername,searchingUsername) == 0)
			 
		{found = 1;}

		else
		{
			pass = 0;
			memset(line,0,100);
			memset(foundUsername,0,50);
			memset(foundScore,0,50);
			
		}
	}

	fclose(fp);
	//printf("\n\n ------------------------- RESULT --------------------\n\n");
	if (found == 1){

	//printf("\n\nUsername: %s\n\n", foundUsername);
	//printf("\n\nScore: %s\n\n", foundScore);
	//printf("\n\nLine Number: %d\n\n",lineNumber);	
	
	return lineNumber;
	
	}

	else{printf("\n\nNO PLAYER FOUND!!!\n\n");
	return 0;
	}

}

int getCurrentScore(int lineNumber)
{
	//printf("\nLine Number Looking For: %d\n",lineNumber);
	FILE *fp2;
	fp2 = fopen("leaderboard.txt","r");
	char line[100];
	int fileLineNumber = 0;
	char score[10];
	int ii;
	for (ii=0;ii<=sizeof(line);ii++){
		score[ii]=NULL;
		line[ii]=NULL;
	}
	while (fgets(line,100,fp2))
	{
		fileLineNumber++;
		if (fileLineNumber == lineNumber){
	//	printf("\nline = %s\n",line);

	int i;
	int isScore = 0;
	int posScore = 0;
	int shouldBreak = 0;
	for (i=0;i<=sizeof(line) && line[i]!=NULL && shouldBreak==0;i++){
	//	printf("\nline[i]=%c\n",line[i]);
		if (isScore == 1){
	//		printf("\nline[i]=%c\n",line[i]);
			score[posScore] = line[i];
	//		printf("score = %s",score);
			posScore++;
		}
		if (line[i]==','){	
			isScore=1;
	//		printf("\nisScore = %d\n",isScore);
		}
		if (line[i] == NULL){
			shouldBreak = 1;
		}	
	}
		}}
	//printf("\n!!! score = %s\n",score);
	
	int intscore;

	intscore = atoi(score); //charToInt(score); 
	//printf("\n!!! intScore = %i",intscore);
		
	return intscore;


	fclose(fp2);
}

int printLeaderboard()
{

	/*
	 *
	 * OK,
	 *
	 * so this bit is trying to make a leaderboard
	 * which prints the leaderboard in a nice way so that
	 * it looks good and that it corrects it self so that 
	 * is always wide enough for the longest username (maybe within
	 * reason could try rapping around not sure yet)
	 *
	 * so what doing below is going to try make a an array
	 * of the username and the score will be in the same position
	 * in the score array. so after adding each username and score
	 * will then caulate the size of the largest username
	 * and will print the leadboard. 
	 *
	 * could also try doing it from the user with the highest score
	 * could do this by looking for the highest score in the scores
	 * array then because the username will be in the same poition 
	 * as the score should be ok
	 *
	 * so what I have started below is adding each username to the
	 * username array.
	 *
	 * will get each line and device up into username and score
	 * then add each one to the right array
	 * will need to keep track of which poistion in the array as
	 * well as the chacter. so is this username one, two... and so on
	 * then which chacter of this name it is like before. 
	 *
	 * remeber to remove the size of the username to the i when
	 * adding the score to its own array. 
	 *
	 * it should be simular to the way done before just then adding
	 * it to the array will all the usernames on (then same for the
	 * score). 
	 *
	 * once all the array stuff has been done
	 *
	 * the next bit is to workout how do make changing table
	 * so if the largest username is 100 chaters it works the same 
	 * as 50. 
	 *
	 * once done that also do it so that it orders it. 
	 *
	 * you might think doing the score first would be better but 
	 * thats only useful for when printing, we arent going to store
	 * usernames in the correct order. 
	 * 
	 * because the player with the highest score isn't going to be
	 * the longest username because its in the table... its still
	 * going to have the right spacing. so working out the longest
	 * username is first important then which username goes first. 
	 *
	 * but this can only be done after the "list"s of usernames are 
	 * created 
	*/
	char usernames[100][100];
	char scores[100][3];
	int sizeOfUsername = 0;
	int UserNumber=0;


	int i;

	FILE *fp;
	fp = fopen("leaderboard.txt","r");
	
	while (fgets(line,100,fp))

	{

		for (i=0,i<=sizeof(line);i++)
		{
			if (line[i] != NULL && pass == 0)
			{
				usernames

				sizeOfUsername++;
			}
		}
	
	}


	fclose(fp)



}

void main()
{
	char searchingUsername[50];
	int lineNumber;
	int score;	
	printf("\n Username to search for: ");
	scanf("%s",&searchingUsername);

	lineNumber = getLineNumberLeaderboard(searchingUsername);
	
	//updateScore(lineNumber,searchingUsername);
	
	//printf("\n!!!lineNumber = %d\n",lineNumber);
		
	score = getCurrentScore(lineNumber);
	//printf("\n(main) Line Number = %d\n",lineNumber);

	printf("\n\nUser: %s, has a win score of %d!\n\n",searchingUsername, score);

}
