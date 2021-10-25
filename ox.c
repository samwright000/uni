#include<stdio.h>
#include<string.h>

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

void makeMove(char board[9],int player, char player1Moves[9], char player2Moves[9]){

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


///////// ADD APPENDING MOVE TO PLAYER LIST
///////// ADD so it knows when someone wins



	if (player == 2){
	toPlace = 'y';}

	board[location] = toPlace;

}

int changePlayer(int player){
	printf("Player = %i",player);
	
	printf("In Change\n");
	if (player == 2){player = 1; printf("Change to 1\n");}
	
	else {player = 2; printf("Change to 2\n");}
	
	printf("Player = %i",player);
	return player;  

}

int main()
{
	//char board[17][3] = {{0,0,0},{0,0,0},{0,0,0}};
	//char board[17][3] = {{"-","-","-"},{"-","-","-"},{"-","-","-"}};

	char board[9] = "---------";
	int player = 1;

	char player1Moves[9];
	char player2Moves[9];

	//printBoard2D(board);
	//board[0][1] = 1;
	
	printf("Welcome");
	
	while (1){
	printBoard1D(board);
	makeMove(board,player,player1Moves,player2Moves);
	player = changePlayer(player);	

	}






}
