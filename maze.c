#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void mainMenu(){

	printf("\nWelcome");
	printf("\n1. Play Game");


}


int getPlayerMoveDirection(){

	char direction;

	printf("\n ! UNDER CONSTRUCTION !\n");
	printf(" u is UP\nd is DOWN\nl is LEFT\nr is RIGHT\n");
	printf(">>> ");
	scanf("%c"&direction);

	if (direction == 'u'){
		return 1;
	}

	if (direction == 'l'){
		return 2;
	}

	if (direction == 'd'){
		return 3;
	}

	if (drection == 'r'){
		return 4;
	}

}

void makeLevel(int* level){

	int boarder[80] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,39,59,79,99,119, 139, 159, 179,199,219,239,259,279,299,319,339,359,379,399,380,381,382,383,384,385,386,387,388,389,390,391,392,393,394,395,396,397,398, 20,40,60,80,100,120,140,160,180,200,220,240,260,280,300,320,340,360}

	// above is the boarder around the end load that into the levels array in the correct location. 

}


int makeMove(){

	int playerPos =21;
        int level[400];
	level[1]=1;
	level[21]=1;






}

void playGame(){}

void main(){
	
	char mainMenuOption;

	system("clear");
	mainMenu();

	printf("\n>>> ");
	scanf("%c",&mainMenuOption);
	printf("\nYou have selected %c\n",mainMenuOption);



}
