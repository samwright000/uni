#include<stdio.h>
#include<string.h>
#include<stdbool.h>
void printBoard1D(char board[9]){

	int i;

	for (i=0;i<9;i++){
		
		if (i % 3==0)
		{
			printf("\n");
		}

		printf(" %d - [%c]",i,board[i]);
	
	}

	printf("\n");
}

int makeMove(char board[9],int player, char player1Moves[9], char player2Moves[9]){

	int location; 

	while (1)
	{
	
		printf("Please Enter Location Player %d: ",player);
		scanf("%i",&location);


		if (board[location] == '-' && location <= 9){
		
			break;
		
		} 
		else{ 
			
			printf("Error, you have entered an invalid location try again...\n");
		} 
	}
	
	char toPlace;
	if (player == 1){
	toPlace = 'x';}

	int i;

	for (i=0; i<=9; i++){

		if (player1Moves[i] == '-'){
		
			player1Moves[i] = location;
			break; 
		}
	}
	printf("\n%s\n",player1Moves);
	
///////// ADD APPENDING MOVE TO PLAYER LIST
///////// ADD so it knows when someone wins


	if (player == 2){
	toPlace = 'o';
	
	for (i=0; i<=9; i++){

                if (player1Moves[i] == '-'){

                        player1Moves[i] = location;
                        break;
                }
	
	}

	}


	board[location] = toPlace;
	
	bool win = false;
	int winner = 0 ;

	if (player == 1){
		win = checkIfWin(player1Moves);
		if (win==true){winner=1;printf("player 1 wins");}
	}

	if (player == 2){
		win = checkIfWin(player2Moves);
		if (win==true){winner=2;printf("player 2 wins");}


	return winner;
	}}
bool checkIfWin(char playerMoves[9]){
	
	bool win = false;
	int i;
	char across012[3] = {'0','1','2'};
	char across345[3] = {'3','4','5'};
	char across678[3] = {'6','7','8'};
	char down036[3] = {'0','3','6'};
	char down147[3] = {'1','4','7'};
	char down258[3] = {'2','5','8'};

	char dag047[3] = {'0','4','8'};
	char dag246[3] = {'2','4','6'};

	int count = 0;
	int player= 0;
	for (i=0; i<=9; i++){
		if (across012[0]==playerMoves[i]){count++;}
		if (count == 3){win=true; break;}
		}
	

	return win;
}

int changePlayer(int player){
	printf("Player = %i\n",player);
	
	printf("\nIn Change\n");
	if (player == 2){player = 1; printf("Change to 1\n");}
	
	else {player = 2; printf("Change to 2\n");}
	
	printf("Player = %i\n",player);
	return player;  

}

void  main(void)
{
	//char board[17][3] = {{0,0,0},{0,0,0},{0,0,0}};
	//char board[17][3] = {{"-","-","-"},{"-","-","-"},{"-","-","-"}};

	char board[9] = "---------";
	int player = 1;
	int win;
	char player1Moves[9] = {'-','-','-','-','-','-','-','-','-'};
	char player2Moves[9] = {'-','-','-','-','-','-','-','-','-'};
	
	//printBoard2D(board);
	//board[0][1] = 1;
	
	printf("Welcome");
	
	while (1){
	printBoard1D(board);
	win = makeMove(board,player,player1Moves,player2Moves);
	player = changePlayer(player);	
	printf("%i",win);

	printf("TESTESTETSTEST");

	if (win!=0){break;}
	}
	
	if (win==1){printf("Player 1 wins!!!");}
	if (win==2){printf("Player 2 wins!!!");}
	if (win==3){printf("No one won :( try again!");}

}
