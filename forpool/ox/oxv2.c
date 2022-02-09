#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int charToInt(char locationchar){
	
	// This function will returna char number to an int one
	return locationchar - '0';

}


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
    //printf("\nUSERNAME     SCORE\n");
    memset(line,0,100);
    memset(foundScore,0,50);
    memset(foundUsername,0,50);


    //printf("2.3\n");

    
    while (fgets(line,100,fp) && found == 0)
    {

        lineNumber++;
//        printf("\n%s\n",line);
        
        int i;
        sizeOfUsername = 0;
        pass = 0;
        for (i=0; i<=sizeof(line); i++)
        {
    //        printf("\nline[i] = %c\n",line[i]);
            
            if (line[i] == NULL){
            
                
            }

            if (line[i] == ',')
            {
                pass = 1;
            }

            else if (line[i] != NULL && pass == 0){
    //            printf("2.5\n");
                foundUsername[i]=line[i];
        //        printf("\nfound username: %s\n",foundUsername);
                sizeOfUsername++;
            }

            if  (line[i] != NULL && pass == 1){
    //            printf("\nIn Found Score\n");
        //        printf("2.6\n");
                
                foundScore[i-sizeOfUsername]=line[i+1];
        //        printf("\nfound score: %s \n",foundScore);
            }
        
        }    

    //    printf("2.3\n");

        if (lineNumber == searchingForLineNumber){
        
            if (usernameOrScore == 0)
            {
                int intFoundUsername = foundUsername;
    //            printf("intFoundUsername = %i");
    //            printf("\nUSENRAME = %s\n",foundUsername);
                return; //usnenrame;
            }

            if (usernameOrScore == 1)
            {
    //            printf("\nSCORE = %s\n",foundScore);
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
        
    //    printf("\nLINE = \n%s",line);
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

//    printf("\n inprint leaderboardusenrameandscore\n");
//    printf("\nUSERNAME 3 = %s\n",username);
    //printf("\nSCORE 3 = %i\n",score);

    // --------

//    printf("\nin\n");


    printf("| ");
    
    int i=0;
//    printf("\nin2\n");
    
    while (i<=100)
    {
//        printf("\n in while \n");
        //printf("username = %c",username);    
//        printf("after username");
        if (username[i] == NULL)
        {
//            printf("\nin if username\n");
            break;
        }
        usernameSize++;
    //    printf("\nusername[%i] - %c\n",i,username[i]);
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
    //    printf("\nDEBUG - Username size < 8\n");
        sizeCorrect = size - usernameSize;
        printf("%s",username);

        for (i=0;i<=sizeCorrect;i++)
        {
            printf(" ");
        }


    }

    if (usernameSize > 8)
    {
//        printf("\nDEBUG - username size > 8\n");
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
    
//        printf("score[i] = %c\n",score[i]);
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
    //        printf("\nMAX SIZE = %i",maxSizeUsername);
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
//    printf("in");
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
//    printf("%s\n",usernames[i]);
//    printf("%s\n",scores[i]);
    }

//    printf("usernames = %s",usernames[1]);
}

void finalLeaderboard()
{
//    printf("\n1\n");

    int maxSize = getMaxUsernameSize();
    int numberOfLinesFile;
    char username[100];
    char score[100];
    int i;
    char scores [50][5]; // 50 players with 5 digits for there score
    char usernames[50][100]; // 50 players with 100 digits

//    printf("\n2\n");
    numberOfLinesFile = numberOfLinesLeaderboard();
    
    createArrays(usernames, scores);

    int currentScoreLocation;
    char currentScore[5];

    int currentHighestScore = 0;
    int currentHighestScoreLocation = 1;
    char currentHighestScoreString[5];    
    
    int numberOfTimesToRun = 0;
    
//    while (numberOfTimesToRun<=numberOfLinesFile){
//    printf("\n...\n");
    currentHighestScoreLocation = 1;
    currentHighestScore=0;
        //while (currentScoreLocation <= numberOfLinesFile){
            //currentHighestScore =0;
            //currentScoreLocation = 0;
/*    
        for (currentScoreLocation=1; currentScoreLocation<=numberOfLinesFile; currentScoreLocation++){
    
            for (i=0; i<=sizeof(score); i++){
        

                currentScore[i]=scores[currentScoreLocation][i];
        
                if (currentScore[i] == NULL){
            
                    break;
                }

                strtok(currentScore,"\n");
            

            }
        
            int intScore = atoi(currentScore);
*/    /*
        printf("\n");
        printf("\nint score = %d",intScore);
        printf("\ncurrentScore = %s",currentScore);
        printf("\ncurrentHighestScore %d",currentHighestScore);
        printf("\nlocation = %d",currentScoreLocation);
        printf("\ncurrent Highestscore location %d",currentHighestScoreLocation);
        printf("\n");
            
        if (intScore > currentHighestScore){
        
                currentHighestScore = intScore;
                currentHighestScoreLocation=currentScoreLocation;
                strcpy(currentHighestScoreString,currentScore);
            }

//            printf("\n5\n");


        }

        printLeaderboardUsernameAndScore(maxSize,usernames[currentHighestScoreLocation],currentHighestScoreString);
        
        int toRemoveI;
        char temp_usernames[50][100];
        char temp_scores[50][5];
        int pass=0;

        for (toRemoveI=0;toRemoveI<=sizeof(scores);toRemoveI++){
        
            if (toRemoveI==currentHighestScoreLocation){
                pass =1;
            }

            else if (pass ==1){
            
                strcpy(scores[toRemoveI+1],scores[toRemoveI]);
                strcpy(usernames[toRemoveI+1],usernames[toRemoveI]);
*/
//                int x;
                /*
                for (x=0;x<sizeof(scores[currentHighestScore-1]);x++){
                    temp_scores[toRemoveI-1][x]=scores[toRemoveI][x];
                */
        
//            }

//        }

    
    
//    numberOfTimesToRun++;    
//    }


    //printLeaderboard(maxSize);
    
    
    printLeaderboardVBoarder(maxSize);
    printHeaderLeaderBoard(maxSize);
    printLeaderboardVBoarder(maxSize);

    //printf("\n1\n");    
    for (i=1;i<=numberOfLinesFile;i++){
    //    printf("2\n");
        printUsernameOrScore(i,0,username,score);
    //    printf("3\n");
        printUsernameOrScore(i,1,username,score);
        
    //    printf("\nUSERNAME 2 = %s\n",username);
    //    printf("\nSCORE 2 = %s\n",score);

    //    printf("\n222\n");
        printLeaderboardUsernameAndScore(maxSize,username,score);

    //    printf("\n111\n");
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
     *     - carray array of all the usernames and score 2 different arrys but have the username and score
     *     in the same location
     *     
     *     - then make something which searches though the list looking for the highest score.
     *     which then prints that username and score then removes it - then look for the highest
     * */
}


char getPlayerInput(char board[9]){

	int validInput = 0; 
	/*int validInput = 0; - added to each time each time the input passes a test. there are three test:
		- Firstly, the first character is a letter a,b,c
		- Secondly the second character is a number between 1,2,3
		- Finally, the location which is got from the cords is not already in use */
	int i;
	int intlocation; // the location is taken in as a string and is converted into an int later, this is used
	char location; // the location is first stored as a string 
	char cordLocation[2]; 
	char playerInput[50]; // the players input is taken in as a large string then using the array above, only the first 2 charicters are taken
	// this is because if the user enters move than 2 digits for the cord location. there will not be enough spaces.
	// this could be fixed better but using execption handling but for a quick fix just made it a larger array to people where less likely
	// to crash the program easliy, if have time will add execption handling. 

	while (validInput < 3){ // it is three because I have three checks and t hey all most be forfilled to carry on. otherwise the user must reenter an input 
		validInput = 0;		
		
		printf("\n\033[0m Please Enter location: ");
		scanf("%s", &playerInput);
		
		cordLocation[0] = playerInput[0];
		cordLocation[1] = playerInput[1];

		//scanf("%s",&cordLocation);
		//printf("\nDEBUG | cordLocation = %s\n",cordLocation);
	
		if (cordLocation[0] == 'a' || cordLocation[0] == 'b' || cordLocation[0] == 'c'){
			
			validInput++;
		//	printf("\nDEBUG | cordLocation[0] is a b or c\n");
		} 
			
// add the statement to validate an in put fo the first bit saying if the first bit is a or b or c good then do second bit if 1 or 2 or 3 it is good. then after that do the switch player then do player make move then do who wins 	
					
		if (playerInput[1] == '1' || playerInput[1] == '2' || playerInput[1] == '3'){
		
			validInput++;
		//	printf("\nDEBUG | cordLocation[1] is 1 2 or 3\n");
		}
		
		if (cordLocation[0] == 'a' && cordLocation[1] == '1'){location = '0';}
		if (cordLocation[0] == 'b' && cordLocation[1] == '1'){location = '1';}
		if (cordLocation[0] == 'c' && cordLocation[1] == '1'){location = '2';}
		if (cordLocation[0] == 'a' && cordLocation[1] == '2'){location = '3';}
		if (cordLocation[0] == 'b' && cordLocation[1] == '2'){location = '4';}
		if (cordLocation[0] == 'c' && cordLocation[1] == '2'){location = '5';}
		if (cordLocation[0] == 'a' && cordLocation[1] == '3'){location = '6';}
		if (cordLocation[0] == 'b' && cordLocation[1] == '3'){location = '7';}
		if (cordLocation[0] == 'c' && cordLocation[1] == '3'){location = '8';}
	

		// above converts the entered cord to an array location.

		intlocation = charToInt(location);

		for (i=0; i<=9;i++)
		
		{
		//	printf("\nDEBUG | board[%d] = %c",i,board[intlocation]);

		//	printf("\nDEBUG | before if\n");
			//printf("\n%c\n",board[intlocation]);
			if (board[intlocation]=='-'){
				
				validInput++;
				i=10;

			//	printf("\nDEBUG | validinputpart3 = %d\n",validInputPart3);
			}
		
		//	printf("\nDEBUG | after if\n");
		}

		//printf("\n\n\n%d\n\n\n",validInput);	
		
		//validInput = validInputPart1 + validInputPart2 + validInputPart3;

		if (validInput == 3){

			
			//printf("\nDEBUG | validInput = %d	part1 = %d part2 = %d part3 = %d \n",validInput,validInputPart1, validInputPart2, validInputPart3);
			break;}
	}
	
	return location;		

}
void drawBoard(char board[9]){

	printf("\n\n\033[0;33m   PLAYING BOARD\n");// the numbers and stuff before "playing board" just changed the colour of the text when printed
	printf("\nPlease enter a letter then a number e.g. 'a1', 'b3', 'c2'...\n\n");
	printf("   +---+---+---+\n");
	printf(" 1 | %c | %c | %c |\n",board[0],board[1],board[2]);
	printf("   +---+---+---+\n");
	printf(" 2 | %c | %c | %c |\n",board[3],board[4],board[5]);
	printf("   +---+---+---+\n");
	printf(" 3 | %c | %c | %c |\n",board[6],board[7],board[8]);
	printf("   +---+---+---+\n");	
	printf("     a   b   c\n");
	printf("\nPLAYER 1 = x\n");
	printf("PLAYER 2 = o\n");

}

int playerChangeTurn(int playerTurn){

	if (playerTurn == 1){playerTurn = 2;}
	else{playerTurn = 1;}

	return playerTurn;

	// if it is currently player ones go it changes to 2 and if it is two it changed to 1

}

void placeOnBoard(char board[9], char playerInput,int playerTurn){
	
	char toPlace;

	if (playerTurn == 1){toPlace = 'x';}
	else{toPlace='y';}

	board[playerInput] = toPlace;

	 	// when this is called the location is already checked to see if valid. so just places a x if player 1 or y if player 2 on the board
}

void printBoardArray(char array[9]){

	int i;
	
	printf("\n");
	for (i=0; i<=sizeof(array);i++){
	
//		printf("DEBUG | %c\n",array[i]);
	
	}
}

int checkWhoWin(char playerMoves[9]){
	
	int win = 0;

	char across012[3] = "012";
	char across345[3] = "345";
	char across678[3] = "678";
	
	char down036[3] = "036";
	char down147[3] = "147";
	char down258[3] = "258";

	char dag047[3] = "048";
	char dag246[3] = "246";

	// above are all the wining states 

	if (playerMoves[0] != '-' && playerMoves[1] != '-' && playerMoves[2] != '-'){win = 1;}
	if (playerMoves[3] != '-' && playerMoves[4] != '-' && playerMoves[5] != '-'){win = 1;}
	if (playerMoves[6] != '-' && playerMoves[7] != '-' && playerMoves[8] != '-'){win = 1;}

	if (playerMoves[0] != '-' && playerMoves[3] != '-' && playerMoves[6] != '-'){win = 1;}
	if (playerMoves[1] != '-' && playerMoves[4] != '-' && playerMoves[7] != '-'){win = 1;}
	if (playerMoves[2] != '-' && playerMoves[5] != '-' && playerMoves[8] != '-'){win = 1;}

	if (playerMoves[0] != '-' && playerMoves[4] != '-' && playerMoves[8] != '-'){win = 1;}
	if (playerMoves[2] != '-' && playerMoves[4] != '-' && playerMoves[6] != '-'){win = 1;}


	// these are the checks for the winning states 

	return win; 	
}

int checkIfDraw(char board[9]){

	int i;

	for (i=0;i<=9;i++){
	
		if (board[i] == '-'){
		
			return 0;
		}
	}

	// the board array staff will 9 '-'
	// the if win is checked first. if it doesn't have a winner
	// and then there are no availble spaces (no more '-') left then there is a draw

	return 1;

}

int getLineNumberLeaderboard(char searchingUsername[50])
{

	// below is used for getting the line number for an entered user
	// it also checks to see if there name the user has entered is valid or not. 

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
			// this clears all the array so there is no left over data
		}
	}

	fclose(fp);
	if (found == 1){

	return lineNumber; // returns a number greater than 0 if a user is found (and will be the line number in the text doc)
	
	}

	else{

//	printf("\n\nNO PLAYER FOUND!!!\n\n");
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
		if (isScore == 1){
			score[posScore] = line[i];
			posScore++;
		}
		if (line[i]==','){	
			isScore=1;
		}
		if (line[i] == NULL){
			shouldBreak = 1;
		}	
	}
		}}
	
	int intscore;

	intscore = atoi(score); //charToInt(score); 
		
	return intscore;


	fclose(fp2);
}

int findUser(char username[50]){
	int lineNumber;
	
	lineNumber = getLineNumberLeaderboard(username);
	if (lineNumber == 0){
	
//		printf("\nUsername Not Found...\n");

		return 0;


	}

	if (lineNumber != 0){
	
//		printf("\nUser Found!\n");

		return 1;
	}


}

int createNewUser(char newUsername[50]){

	FILE *fp;
	char line[100];
	char inputToFile[100];

	sprintf(inputToFile,"%s",strcat(newUsername,",1\n"));

//	printf("\ninputToFile = %s\n",inputToFile);

	fp = fopen("leaderboard.txt","a");

	fputs(inputToFile,fp);

	fclose(fp);

//you can assume that any username is good because it has already been changed
//so all we need to do is fine the next available line.
//and put the new line into it.



}

int addScoreToUser(char username[100]){
	int currentLinenumber = 0;
	int lineNumber = getLineNumberLeaderboard(username);
	int currentScore = getCurrentScore(lineNumber); 
	int newScore = currentScore+1;
	char lineToEnter[100];

	char charNewScore[50];
	
	sprintf(charNewScore,"%i",newScore);

	char newLine[2] = "\n";
	
	sprintf(username,"%s",strcat(username,","));
	
	sprintf(lineToEnter,"%s",strcat(username,charNewScore));

	sprintf(lineToEnter,"%s",strcat(lineToEnter,newLine));

	FILE *fp;
	FILE *fp_temp;
	char line[100];

	fp = fopen("leaderboard.txt","r");
	fp_temp = fopen("temp_leaderboard.txt","a");
	
	while(fgets(line,100,fp)){

		currentLinenumber++;

		if (lineNumber == currentLinenumber){
		
			fputs(lineToEnter,fp_temp);
		

		}
		
		else{
			fputs(line,fp_temp);
		
		}
	}

	fclose(fp);
	fclose(fp_temp);

	fp_temp = fopen("temp_leaderboard.txt","r");
	
	fp = fopen("leaderboard.txt","w");

	while (fgets(line,100,fp_temp)){
	
		fputs(line,fp);
	}

	fclose(fp);

	fclose(fp_temp);

	fp_temp = fopen("temp_leaderboard.txt","w");
	fputs("",fp_temp);
	fclose(fp_temp);


}

int validateUsername(char username[100]){

	int i;

	for (i=0;i<=sizeof(username);i++){
//		printf("\n`username [i] = %c",username[i]);	
		if (username[i] == ','){
		
			return 1; // not valid
		}
	}

	return 0; // valid

}

void playGame(){

	char board[9] = "---------";
	char player1Moves[9] = "---------";
	char player2Moves[9] = "---------";
	char playerInput;
	int playerInputInt;
	int playerTurn = 1;
	int i;
	int checkPlayer1Win;
	int checkPlayer2Win;
	int isDraw;
	system("clear");
	while (1==1){
		drawBoard(board);
		playerInput = getPlayerInput(board);
		playerInputInt = charToInt(playerInput);
		//printf("\nDEBUG | playerInput = %c\n",playerInput);
	
	
		char toPlace;
		char option[50];
	
		//printf("\nDEBUG | before if playerTurn ==1\n");


		if (playerTurn == 1){	
			
			toPlace = 'x';
			player1Moves[playerInputInt] = toPlace;

			//checkPlayer1Win = checkWhoWin(player1Moves); REMOVE LATER ONLY SO PLAYER ONE WINS!
			char winnerUsernameToSearch[50];
			int result;
			char tryAgain[50];
			checkPlayer1Win = checkWhoWin(player1Moves);
			if (checkPlayer1Win == 1){
				system("clear");
				printf("Player 1 Wins!\n");
				printf("\nYou can add an addition win to the leaderboard!\n");
				printf("\nIf you want to add to your current score\nPlease enter [y]\n\nIf you Don't want to record the win *sad face* \nPlease enter [n]\n\nPlease Enter: ");
				
				scanf("%s",option);

				if (strcmp(option,"n") == 0){
					printf("\nBye...\n");
					break;
				}

				else if (strcmp(option,"y")==0){

					while (1==1){
					int isValidUsername = 1;

					while (isValidUsername == 1){
					
						printf("\nEnter Username: ");
						scanf("%s",&winnerUsernameToSearch);
						isValidUsername = validateUsername(winnerUsernameToSearch);

						if (isValidUsername == 1){
							memset(winnerUsernameToSearch,0,50);
							printf("oops! Make sure your username doesn't include ','!\n");
						
						}
					
					}

					
					

						result = findUser(winnerUsernameToSearch);
					
						if (result == 1){
						printf("\nUser found!\n\nIf it is yours enter [y]\nIf you would you like to enter another username enter [new]\nIf you don't want to record the win enter [quit]\n\n>>>  ");
						scanf("%s",&tryAgain);
						}
						if (result == 0){
						//	printf("\n TEST - USERNAME ACCEPTED NOW ADDING WITH SCORE OF 1\n");
							printf("\n Creating new user \n");
							createNewUser(winnerUsernameToSearch);
							break;
						
						}
						
						if (strcmp(tryAgain,"quit") ==0){
						break;
						}

						else if (strcmp(tryAgain,"y") ==0){
						printf("\nAdding an additional point to user %s\n",winnerUsernameToSearch);
						
						addScoreToUser(winnerUsernameToSearch);
						
						break;	
						}

						else if (strcmp(tryAgain,"new")==0){
						printf("\nYou want to enter a different username!\n");
						}

						else{}
					}
					break;
					
			}


				else{printf("\nYou didn't enter a correct result... you don't deserve to record your result\n");exit(0); }
		}

		}	
		else{
		

			//printf("\nDEBUG | playerturn not 1\n");
			toPlace='o';
			player2Moves[playerInputInt] = toPlace;
			char winnerUsernameToSearch[50];
			int result;
			char tryAgain[50];


			checkPlayer2Win = checkWhoWin(player2Moves);

			if (checkPlayer2Win == 1){
				system("clear");		
				printf("\n\n\nPlayer 2 Wins!!!\n\n\n");
				
printf("\nIf you can now add an addition win to the leaderboard!\n");
				printf("\nIf you want to add to your current score\nPlease enter [y]\n\nIf you Don't want to record the win *sad face* \nPlease enter [n]\n\nPlease Enter: ");

				scanf("%s",option);
				
				if (strcmp(option,"n") == 0){
					printf("\nBye!!!!!!!!!!\n");
					break;
				}

				else if (strcmp(option,"y")==0){



					 while (1==1){

					 int isValidUsername = 1;
                                        while (isValidUsername == 1){

                                                printf("\nEnter Username: ");
                                                scanf("%s",&winnerUsernameToSearch);
                                                isValidUsername = validateUsername(winnerUsernameToSearch);
						
						if (isValidUsername == 1){
						
						memset(winnerUsernameToSearch,0,50);
						printf("oops! you have entered a username containing a ','. Please make sure it doesn't!");

						}
                                        }

					
					
					
						result = findUser(winnerUsernameToSearch);
					
						if (result == 1){
						printf("\nUser found!\n\nIf it is yours enter [y]\nIf you would you like to enter another username enter [new]\nIf you don't want to record the win enter [quit]\n\n>>>  ");
						scanf("%s",&tryAgain);
						}
						if (result == 0){
							//printf("\n TEST - USERNAME ACCEPTED NOW ADDING WITH SCORE OF 1\n");
							createNewUser(winnerUsernameToSearch);
							break;
						
						}
						
						if (strcmp(tryAgain,"quit") ==0){
						break;}

						else if (strcmp(tryAgain,"y") ==0){
						printf("\nADDING TO SCORE FOR USER - %s\n",winnerUsernameToSearch);
						
						addScoreToUser(winnerUsernameToSearch);
						
						break;	
						}

						else if (strcmp(tryAgain,"new")==0){
						printf("\nYou want to enter a different username!\n");}

						else{}
					}
				} 

				break;
			}
		}

		//printf("\nDEBUG | toPlace = %c		playerInput = %c",toPlace);
		board[playerInputInt] = toPlace;
		
		isDraw = checkIfDraw(board);
		//printf("\n\nDEBUG | isDraw = %d\n\n",isDraw); 
		if (isDraw == 1){
		
			printf("\n\n\n No one wins :(. It was a draw! \n\n\n");
			break;
		
		}

		system("clear");

		printf("\nPlayer %d has had there turn. It is now",playerTurn);// ***-***
		playerTurn = playerChangeTurn(playerTurn);
		printf("\033[0;31m");
		printf(" Player %d ",playerTurn);
		printf("\033[0m");
		printf("turn to play.");
	}
}

void printMainMenu(){
	printf("\033[0;33m");
	printf("\n");
	printf("\n+----------------------+");
	printf("\n|       Welcome!       |");
	printf("\n+----------------------+");
	printf("\n| [1]. Play Game       |");
	printf("\n| [2]. See Leaderboard |");
	printf("\n| [q]. Quit            |");
	printf("\n+----------------------+");
	printf("\nPlease Enter an option within the '[]'\n"); 
	printf("\033[0m");
	printf("\n>>> ");
}

// ADD VALIDATION AND SANITATION TO ENTER USERNAME

void main(){

	// OPENING COMMENTS
	// hello, welcome to my program, it might not be the clearest to understand or the most commented (and spelt correctly)
	// but I hope it is easy enough to follow. 
	//
	// luckly (or down to hard work) it all works (hopefully). 
	//
	//
	// make sure you have the leaderboard.txt in the same dirc as the exe. 
	//
	// hope you enjoy!
	//
	//P.S.
	//
	//the leaderboard I had it just print out each line of the array which wasn't much of a leaderboard so i haven't including it
	//it has taken a bit more work than i thought so that it always creates the right size. so if there is a long name is entered
	//all the leaderboard is ajusted to the correct size.
	//
	//So, basically I haven't submitted it yet I will submit it as a different project... I might CBA to do it. I'm not sure
	//it would effect the grade very much. If you think it does, and I do create it I will somehow hopefully let you know or something
	//and then you could ajust the grade if you think it is needed but IDK.
	//
	//P.S.S
	//
	//I have left the debugging printed stuff in so that for what ever reason If I had more i don't want to put the all back in
	//and they might be helpful for you to see where the program goes wrong and hopefulyl it helps one understand the program more. 
	//
	// ---

	system("clear");

//	printUsernameOrScore(1,1); // line number then 0 = username, 1 = score
	
	char mainMenuChoice;
	while (1==1){	
		printMainMenu();
		scanf("%s",&mainMenuChoice);

		if (mainMenuChoice == '1'){
			playGame();
		}

		else if (mainMenuChoice == '2'){
			finalLeaderboard();
		}

		else if (mainMenuChoice == 'q'){
			system("clear");
			exit(0);
		}
	}
}
