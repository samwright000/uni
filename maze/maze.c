#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h>

void mainMenu(){

	printf("\nWelcome");
	printf("\n1. Play Game (default level)");
	printf("\n2. See Level Names");
	printf("\n3. Select Custom Level");


}


int getPlayerMoveDirection(){

	char direction;

	printf("\n ! UNDER CONSTRUCTION !\n");
	printf(" u is UP\nd is DOWN\nl is LEFT\nr is RIGHT\n");
	printf(">>> ");
	scanf("%c",&direction);

	if (direction == 'u'){
		return 1;
	}

	if (direction == 'l'){
		return 2;
	}

	if (direction == 'd'){
		return 3;
	}

	if (direction == 'r'){
		return 4;
	}

}

void loadLevelFromFile(char levelName[100] ){

	int maze[324];

	FILE *fp;
	char line[3];

	printf("\nEnter level name you want to load: ");
	scanf("%s",&levelName);

	strcat(levelName,".txt");

	printf("level name = %s",levelName);


}

void makeLevel(int* level){

	int boarder[80] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,39,59,79,99,119, 139, 159, 179,199,219,239,259,279,299,319,339,359,379,399,380,381,382,383,384,385,386,387,388,389,390,391,392,393,394,395,396,397,398, 20,40,60,80,100,120,140,160,180,200,220,240,260,280,300,320,340,360};


	// above is the boarder around the end load that into the levels array in the correct location. 

}


int makeMove(){

	int playerPos=21;
        int level[400];




	return 0;

}

int levelSelection(char fileNames[50][100], int numberOfLevels){

	char levelName[100];

	int found = 0;
	
	while (found!=1){

		displayLevelNames(fileNames, numberOfLevels);


		printf("\nPlease enter level you would like to play: ");
		scanf("%s",&levelName);

		int i;
		for (i=0;i<numberOfLevels; i++){
			
			if (strcmp(fileNames[i],levelName) == 0){
				
				found = 1;
                        }

                }


        	printf("\n");	
		if (found!=1){system("clear"); displayError("\nThat is an invalid level name\n");}

		else{
		
			system("clear");

			printf("\n\033[0;32m You have selected level ");
			printf("%s",levelName);
			printf("\033[0m\n");
		
		}

	}


	return 0;

}

int getAllLevelNames(char fileNames[50][100]){

	// help from https://c-for-dummies.com/blog/?p=3246

	DIR *folder;
	struct dirent *entry;
	int files = 0;

	folder = opendir("/home/csc/wm145/maze/levels");
	
	if(folder == NULL)
	{
		perror("Unable to read directory");
    	}

    	while( (entry=readdir(folder)) )
    	{		
		if (entry->d_name[0] != '.'){
			strcpy(fileNames[files],entry->d_name);
			files++;
		}
    	}

    	closedir(folder);
	
	return files;

}

void displayError(char message[100]){

	printf("\033[0;31m");
	printf("%s",message);
	printf("\033[0m");

}

void displayValidEntry(char message[100]){

	printf("\033[0;32m");
	printf("%s",message);
	printf("\033[0m");

}

void displayLevelNames(char fileNames[50][100], int numberOfLevels){

	int i;
	 
	printf("\n");
	for (i=0;i<numberOfLevels; i++){

		char * filenameForDisplay = strtok(fileNames[i],".");

                printf("\nFileName = %s",filenameForDisplay);

        }
	printf("\n");


}

void endGame(){

	printf("\n BYE! \n");
	exit("bye");
}

void playGame(){}

void main(){

	system("clear");
	
	char fileNames[50][100];
	int numberOfLevels;
	char mainMenuOption[1];
	int playAgain = 1;

	char message[100];

	numberOfLevels = getAllLevelNames(fileNames);
	
	while (true){
		mainMenu();

		printf("\n>>> ");
		scanf("%s",&mainMenuOption);

		if (strcmp(mainMenuOption,"1") == 0){system("clear"); displayValidEntry("\nThat is a valid entry!\n"); printf("*plays game*");}

		else if  (strcmp(mainMenuOption,"2") == 0){
			system("clear");
			displayValidEntry("\nThat is a valid entry!\n");
			displayLevelNames(fileNames, numberOfLevels); 
		}

		else if (strcmp(mainMenuOption,"3") == 0){system("clear"); displayValidEntry("\nThat is a valid entry!\n"); levelSelection(fileNames,numberOfLevels);}

		else if (strcmp(mainMenuOption,"q") == 0){system("clear"); displayValidEntry("\nThat is a valid entry!\n"); endGame();}

		else{

			system("clear");
		
			displayError("\nInvalid option\n");
		
		}




/*
		char playAgainMenu;
		printf("Would you like to play again? (y/n): ");
	
		scanf("%s",&playAgainMenu);
	
		if (playAgainMenu == 'n'){
		
			playAgain = 0;
		}
*/	
	}





	printf("\n");

	printf("\nEND\n");
}
