#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int charToInt(char locationchar){
	
	// This function will returna char number to an int one
	return locationchar - '0';

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

	while (validInput < 3){
		validInput = 0;		
		
		printf("\nPlease Enter location: ");
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

	printf("\n\n   PLAYING BOARD\n");

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

}

void placeOnBoard(char board[9], char playerInput,int playerTurn){
	
	char toPlace;

	if (playerTurn == 1){toPlace = 'x';}
	else{toPlace='y';}

	board[playerInput] = toPlace;

	 	
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

	if (playerMoves[0] != '-' && playerMoves[1] != '-' && playerMoves[2] != '-'){win = 1;}
	if (playerMoves[3] != '-' && playerMoves[4] != '-' && playerMoves[5] != '-'){win = 1;}
	if (playerMoves[6] != '-' && playerMoves[7] != '-' && playerMoves[8] != '-'){win = 1;}

	if (playerMoves[0] != '-' && playerMoves[3] != '-' && playerMoves[6] != '-'){win = 1;}
	if (playerMoves[1] != '-' && playerMoves[4] != '-' && playerMoves[7] != '-'){win = 1;}
	if (playerMoves[2] != '-' && playerMoves[5] != '-' && playerMoves[8] != '-'){win = 1;}

	if (playerMoves[0] != '-' && playerMoves[4] != '-' && playerMoves[8] != '-'){win = 1;}
	if (playerMoves[2] != '-' && playerMoves[4] != '-' && playerMoves[6] != '-'){win = 1;}

	return win; 	
}

int checkIfDraw(char board[9]){

	int i;

	for (i=0;i<=9;i++){
	
		if (board[i] == '-'){
		
		
			return 0;
		
		}

	}

	return 1;

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

int findUser(char username[50]){
	int lineNumber;
	
	lineNumber = getLineNumberLeaderboard(username);
	printf("\n LineNumber: %d\n",lineNumber);
	if (lineNumber == 0){
	
		printf("\nUsername Not Found...\n");

		return 0;


	}

	if (lineNumber != 0){
	
		printf("\nUser Found!\n");

		return 1;
	}


}

int createNewUser(char newUsername[50]){

//you can assume that any username is good because it has already been changed
//so all we need to do is fine the next available line.
//and put the new line into it.



}

void main(){

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
			checkPlayer1Win = 1;
			char winnerUsernameToSearch[50];
			int result;
			char tryAgain[50];	
			if (checkPlayer1Win == 1){
			
				printf("\n\n\nPlayer 1 Wins!!!\n\n\n");
				
				printf("\nIf you can now add an addition win to the leaderboard!\n");
				printf("\nIf you want to add to your current score\nPlease enter !n to create a new user.\n\nIf you Don't want to record the win *sad face* \nPlease enter !q\n\nOr if you know you username just enter it\n\nPlease Enter: ");
				

				scanf("%s",option);
				
				


				if (strcmp(option,"!q") == 0){
					printf("\n You have entered !q. Bye!");
					break;
				}

				if (strcmp(option,"!n")==0){


					
					while(1==1){
					
					printf("\nEnter Username:  ");
					scanf("%s",&winnerUsernameToSearch);

						result = findUser(winnerUsernameToSearch);
					
						if (result == 1){
						printf("\n User found!, if it is yours enter !c, if you would you like to enter another username? enter !y  if yes, if you don't want to record the win enter !n for no: ");
						scanf("%s",&tryAgain);
						}
						if (result == 0){
							printf("\n TEST - USERNAME ACCEPTED NOW ADDING WITH SCORE OF 1\n");
							addNewUser
							break;
						
						}
						
						if (strcmp(tryAgain,"!n") ==0){
						break;}

						if (strcmp(tryAgain,"!c") ==0){
						printf("\nADDING TO SCORE FOR USER - %s\n",winnerUsernameToSearch);
						break;	
						}

						if (strcmp(tryAgain,"!y")==0){
						printf("\nYou want to enter a different username!\n");}
					}
					break;
				}

				

			}
		}
		
		else{
			
			//printf("\nDEBUG | playerturn not 1\n");
			toPlace='o';
			player2Moves[playerInputInt] = toPlace;

			checkPlayer2Win = checkWhoWin(player2Moves);

			if (checkPlayer2Win == 1){
			
				printf("\n\n\nPlayer 2 Wins!!!\n\n\n");
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

		printf("\nPlayer %d has had there turn. It is now Player ",playerTurn);
		playerTurn = playerChangeTurn(playerTurn);
		printf("%d turn to play.",playerTurn);
	}
	
}

