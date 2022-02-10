#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int charToInt(char locationchar){

	return locationchar - '0';

}

char getPlayerInput(char board[9]){
	int validInput = 0;
	int validInputPart1 = 0;
	int validInputPart2 = 0;
	int validInputPart3 = 0;
	char cordLocation[2];
	int i;

	char location;
	int intlocation;

	while (validInput < 3){
		printf("\nPlease Enter location: ");
		scanf("%s",&cordLocation);
		//printf("\nDEBUG | cordLocation = %s\n",cordLocation);
	
		if (cordLocation[0] == 'a' || cordLocation[0] == 'b' || cordLocation[0] == 'c'){
			
			validInputPart1 = 1;
		//	printf("\nDEBUG | cordLocation[0] is a b or c\n");
		} 
			
// add the statement to validate an in put fo the first bit saying if the first bit is a or b or c good then do second bit if 1 or 2 or 3 it is good. then after that do the switch player then do player make move then do who wins 	
					
		if (cordLocation[1] == '1' || cordLocation[1] == '2' || cordLocation[1] == '3'){
		
			validInputPart2 = 1;
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
			if (board[intlocation]=='-'){validInputPart3 = 1;i=10;
			//	printf("\nDEBUG | validinputpart3 = %d\n",validInputPart3);
			}
		
		//	printf("\nDEBUG | after if\n");
		}

		validInput = validInputPart1 + validInputPart2 + validInputPart3;
		//printf("\n\n\n%d\n\n\n",validInput);	
		if (validInput == 3){
			
			//printf("\nDEBUG | validInput = %d	part1 = %d part2 = %d part3 = %d \n",validInput,validInputPart1, validInputPart2, validInputPart3);
			
			break;}
	
	}
	
	return location;		

}
void drawBoard(char board[9], char player1Moves[9], char player2Moves[9]){

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

void main(){

	char board[9] = "---------";
	char player1Moves[9] = "---------";
	char player2Moves[9] = "---------";
	int winner = 0; // 0 = no one | 1 = player1 | 2 = player2 | player 3 = draw 
	char playerInput;
	int playerInputInt;
	int playerTurn = 1;
	int i;
	int checkPlayer1Win;
	int checkPlayer2Win;
	int isDraw;
	system("clear");
	while (1==1){
		drawBoard(board,player1Moves,player2Moves);
		playerInput = getPlayerInput(board);
		playerInputInt = charToInt(playerInput);
		//printf("\nDEBUG | playerInput = %c\n",playerInput);
	
	
		char toPlace;
	
		//printf("\nDEBUG | before if playerTurn ==1\n");

		if (playerTurn == 1){	
			
			toPlace = 'x';
			player1Moves[playerInputInt] = toPlace;

		//	printf("\nPlayer 1 Moves:\n\n");
			

			/*
			for (i=0; i<=9; i++){
				printf("%c\n",player1Moves[i]);
			}
			*/
			
			checkPlayer1Win = checkWhoWin(player1Moves);

			if (checkPlayer1Win == 1){
			
				printf("\n\n\nPlayer 1 Wins!!!\n\n\n");
				break;
			
			}

		}
		
		else{
			
			//printf("\nDEBUG | playerturn not 1\n");
			toPlace='o';
			player2Moves[playerInputInt] = toPlace;
			
			/*
			printf("\nPlayer 2 Moves:\n\n");
			for (i=0; i<=9; i++){
				printf("%c\n",player2Moves[i]);
			}
			*/

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

