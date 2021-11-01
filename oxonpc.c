#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>



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
	char locationstring;
	
	while (1)
	{
	
		printf("Please Enter Location Player %d: \n",player);
		scanf("%c",&locationstring);
		scanf("%i",&location);	
		

		printf("\nlocation: %i",location);
		printf("\nlocationstring: %s",locationstring);

		if (board[location] == '-' && location <= 9){
		
			break;
		
		} 
		else{ 
			
			printf("Error, you have entered an invalid location try again...\n");
		} 
	}
	

	printf("RUNNNING");	

	char toPlace;
	if (player == 1){
	toPlace = 'x';}
	
	printf("location: %i",location);

	//sprintf(locationstring,"%d",location);
	
	//itoa(location,locationstring,1);

	//printf("locationstring: %c",locationstring);

	int i;

	int ii;
	if (player==1){
	
	for (i=0; i<=9; i++){

		if (player1Moves[i] == '-'){
		
			player1Moves[i] = locationstring;
			break; 
		}
	}}
	

	if (player == 2){
	toPlace = 'o';
	
	for (ii=0; ii<=9; ii++){
		
		printf("playerwmoves: %c",player2Moves[ii]);

                if (player2Moves[ii] == '-'){
			printf("Player 2 Moves: %i",player2Moves[ii]);
                        player2Moves[ii] = locationstring;
			printf("Player 2 Moves after: %i",player2Moves[ii]);
                        break;
                }}}

	board[location] = toPlace;
	
	bool win = false;
	int winner = 0 ;

	if (player == 1){
		win = checkIfWin(player1Moves);
		if (win==1){winner=1;printf("player 1 wins");}
	}

	if (player == 2){
		win = checkIfWin(player2Moves);
		if (win==1){winner=2;printf("player 2 wins");}


	return winner;
	}}
int checkIfWin(char playerMoves[9]){
	printf("\nin check if win\n");

	bool win = 0;
	int i;
	int ii;
	int iii;

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
	
	printf("check if win above for");
	
	printf("\n");
	for (iii=0; iii<=8; iii++){
		printf("%c",playerMoves[iii]);
	}
	printf("\n");


	for (i=0; i<=8; i++){
		
		for (ii=0; ii<=2; ii++){

			printf("\ncount: %i",count);
			printf("\nacross012: %c",across012[ii]);
			printf("\nplayermoves: %c\n",playerMoves[i]);

			if (across012[ii]==playerMoves[i]){
				count++;
				printf("\ncount: %i\n",count);
				printf("\nacross012: %c\n",across012[ii]);
				printf("\nplayermoves: %c\n",playerMoves[i]);
				}

			if (count == 3){win=1; break;}
		}}
	

	return win;
}

int changePlayer(int player){
	printf("\nPlayer = %i\n",player);
	
	printf("\nIn Change\n");
	if (player == 2){player = 1; printf("Change to 1\n");}
	
	else {player = 2; printf("Change to 2\n");}
	
	printf("\n\nPlayer = %i\n",player);
	return player;  

}

void  main(void)
{
	//char board[17][3] = {{0,0,0},{0,0,0},{0,0,0}};
	//char board[17][3] = {{"-","-","-"},{"-","-","-"},{"-","-","-"}};

	char board[9] = "---------";
	int player = 1;
	int win;
	char player1Moves[9] = "---------";
	char player2Moves[9] = "---------";
	
	//printBoard2D(board);
	//board[0][1] = 1;
	
	printf("Welcome");
	
	while (1){
	printBoard1D(board);
	win = makeMove(board,player,player1Moves,player2Moves);
	player = changePlayer(player);	
	printf("\nwin = %i\n",win);
	
	int i;
	
	printf("\nprinting player 1\n");

	for (i=0;i<=9;i++){
	
		printf("%c",player1Moves[i]);
	
	}

	if (win!=0){break;}
	}
	
	if (win==1){printf("Player 1 wins!!!");}
	if (win==2){printf("Player 2 wins!!!");}
	if (win==3){printf("No one won :( try again!");}

}
