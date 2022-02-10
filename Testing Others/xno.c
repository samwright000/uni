#include<stdlib.h>
#include<stdio.h>


void printboard(char* start)
{
	int i,j;
	char board[]={' ','*',' ','|',' ','*',' ','|',' ','*',' ','\n',
		      '-','-','-','-','-','-','-','-','-','-','-','\n',
		      ' ','*',' ','|',' ','*',' ','|',' ','*',' ','\n',
		      '-','-','-','-','-','-','-','-','-','-','-','\n',
		      ' ','*',' ','|',' ','*',' ','|',' ','*',' ','\n','\n','\n'};
	//creates an array of the board
	for(i=0,j=1;i<9;i++,j=j+4)
	{
		board[j]=start[i];
		if(j==9)
		{
			j=21;
		}
		if(j==33)
		{
			j=45;
		}
	}
	//inputs the symbols into the board
        for(i=0;i<62;i++)
        {
		if(board[i]=='X')
		{
			printf("\33[0;34m");
		}
		else if(board[i]=='O')
                {
                        printf("\33[0;36m");
                }
                else if(board[i]>='1' && board [i]<='9')
                {
                        printf("\33[0;33m");
                }
                else
                {
                        printf("\33[0;37m");
                }
		//colours the board appropriately
		printf("%c",board[i]);//prints the board
        }
}



int checkboard(int* square)
{
        int i,j,k;
        for(i=0;i<9;i++)
        {
                for(j=0;j<9;j++)
                {
                        for(k=0;k<9;k++)
                        {
                         	if(i==k || i==j || k==j)
				{
					continue;
				}
			 	if((square[i]+square[j]+square[k])==15)
                                {
                                        return 1;
                                }
                        }
                }//compares almost all combinations of three numbers in
		//the array and if they add to fifteen then somewhere within
		//the array there must be a line of three of the same symbols
        }
        return 0;
}


void main()
{
	printf("\33[0;34m");//sets starting colour to player one's colour
	char sym='X';
	int i,move;
	int turn=1;//defines stuff
	int won=0;
	int count=0;
	char board[]={'1','2','3','4','5','6','7','8','9'};
	int square[]={8,1,6,3,5,7,4,9,2};//creates magic square for checking
        int square1[]={16,16,16,16,16,16,16,16,16};
//each player gets an empty array that is filled with the numbers from the magic square
        int square2[]={16,16,16,16,16,16,16,16,16};
//each array must be filled with numbers greater than fifteen so
//that if nine and six are placed in the array they are not compared 
//with a zero totalling fifteen and constituting a win
	while(won==0 && count<9)
	{
		if(turn==1)
		{
                        printf("\33[0;34m");
		}
		else if(turn==2)
                {
                        printf("\33[0;36m");
                }
		printf("\n\n\nIt is Player %d's turn:\n\n\n",turn);
		printboard(board);
		move=0;//display turn and board
		scanf("%d", &move);
		while((getchar())!='\n');
		if(move<1 || move>9)
		{
                       	printf("Incorrect input\n");
			continue;
		}//take input and check if input is correct
		//display appropriate message if input is incorrect
		if(board[move-1]=='X' || board[move-1]=='O')
		{
			printf("Move taken\n");
			continue;	
		}
		board[move-1]=sym;//fill display board with correct symbol
		if(turn==1)
		{
			square1[move-1]=square[move-1];//fills the players array with the equivilant number
			//from the magic square
			won=checkboard(square1);//checks if the player has won
			turn=2;
			sym='O';//changes relevant variables
			count++;//increments count for checking for a draw
		}	
		else if(turn==2)
		{
			square2[move-1]=square[move-1];
			won=checkboard(square2);
			turn=1;
			sym='X';//ditto
			count++;
		}
	}
	if(turn==1)
	{
		turn=2;
	}//when a player wins the loop will exit on the other players turn
	//so the turns must be swapped a final time
	else if(turn==2)
	{
		turn=1;
	}
	if(count==9 && won==0)
	{
		printf("\33[0;31m\n\n\nIt is a stalemate\n\n\n");
	}//checks for draw and displays appropriate message
	if(won==1)
	{
		printf("\33[0;32m\n\n\nPlayer %d has won\n\n\n",turn);
	}//displays message for the winning player
	printboard(board);//shows the board a final time
}

