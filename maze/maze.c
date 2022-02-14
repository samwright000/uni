#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h>

void mainMenu(){

	printf("\n\n1. Play Game (default level)");
	printf("\n2. See Level Names");
	printf("\n3. Select Custom Level");


}


int getPlayerMoveDirection(){
	
	  int c;
	  /* use system call to make terminal send all keystrokes directly to stdin */
	  system ("/bin/stty raw");
	  
	  while((c=getchar())!= '.') {
		  
		/* type a period to break out of the loop, since CTRL-D won't work raw */
		break;
	  }
	  /* use system call to set terminal behaviour to more normal behaviour */
	  system ("/bin/stty cooked");
	  


	if (c == 'w' || c == 'W'){
		return 1;
	}

	if (c == 'd' || c == 'D'){
		return 2;
	}

	if (c == 's' || c == 'S'){
		return 3;
	}

	if (c == 'a' || c == 'A'){
		return 4;
	}
	
	if (c == 'q' || c == 'Q'){
		system("clear");
		return 5;}
	
}

int makeLevel(int level[400], char levelName[100]){

	int maze[324];
	memset(maze,0,1296);
	int boarder[76] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,39,59,79,99,119, 139, 159, 179,199,219,239,259,279,299,319,339,359,379,399,380,381,382,383,384,385,386,387,388,389,390,391,392,393,394,395,396,397,398, 20,40,60,80,100,120,140,160,180,200,220,240,260,280,300,320,340,360};
	char fileName[104];
	int intLine;
	
	//printf("SIZE = %d",sizeof(maze));

	sprintf(fileName,"/home/sam/wm145/maze/levels/%s.txt",levelName);//home/sam/wm145/maze/levels/level1.txt
	
	//printf("\nDEBUG - Level Loaded = %s\n",fileName);
	
	FILE *fp;

	
	char line[100];

	fp = fopen(fileName,"r");

	int i = 0;


	while (fgets(line,100,fp) && fgets != 0){
		intLine = atoi(line);
		printf("\nline int %d",intLine);
		
		if (intLine == 0){break;}
		
		maze[i] = intLine;
		
		i++;
		
		memset(line,0,100);
		
		}
		
	for (i=0;i<=324;i++){
		
		if (maze[i]==0){break;}
		
		printf("\nmaze[%d] = %d",i,maze[i]);
		
		}
		
	for (i=0; i<=76; i++){

		level[i] = boarder[i];
		
		}
	
	int x = 0;	
	
	for (i=77; i<=400; i++){
		
		level[i]=maze[x];
		
		x++;
		
		} 
		
		printf("\nhello\n");
		
	for (i=0; i<=400; i++){
		
		printf("\nlevel[%d] = %d",i,level[i]);
		
		}
		
			
	fclose(fp);

	
	return 0;

	// above is the boarder around the end load that into the levels array in the correct location. 

}

int checkIfValidMove(){
	
	
	
	}

int makeMove(int up, int right, int down, int left, int level[400], int playerPos){
	
	int validMove = 0;

	int attemptedMove;
	
	int direction;
	
	int i;
	
	int found = 0;
	
	int line = 0;
	
	// 1 = up, 2 = right, 3 = down, 4 = left
	
	
	
	while (validMove != 1){
		
		found = 0;
		line = 0;
		
		//printf("\n START found = %d\n",found);
		//printf("\nup = %d, right = %d , down = %d, left = %d\n",up,right,down,left);
		//printf("\nPlayer current Pos  = %d",playerPos);
		
		attemptedMove = getPlayerMoveDirection();
		direction=attemptedMove;
		
		
		
		if (attemptedMove == 1){attemptedMove = up ;}
		else if (attemptedMove == 2){attemptedMove = right;}
		else if (attemptedMove == 3){attemptedMove = down;}
		else if (attemptedMove == 4){attemptedMove = left;}
		else if (attemptedMove == 5){return 5;}
		
		
		int newPos = playerPos+attemptedMove;	
		
		
		//printf("size of level = %d",sizeof(level));
		for (i=0; i<=400; i++){
			//printf("\nnewPos = %d", newPos);
			//printf(" level[i] = %d\n",level[i]);
			
			if (newPos == level[i] && level[i]!=0){
				
				
				found = 1; 
				//printf("\nfound = %d",found);
				//printf("\nlevel = %d ,",level[i]);
				
				}
			
			else{line++;}
			
		}
		
		//printf("\n after found = %d",found);
		//printf("\n line = %d , sizeoflevel = %d",line,sizeof(level));
		
			
		if (found == 0){
			
			validMove = 1;
			
			}
		
		else{
			
			system("clear");
			
			displayLevel(level, playerPos);
			
			displayError("\nThat is not a valid move!\n");
			
			
			}
			
			
			
		}
		
	//printf("valid move = %d",validMove);
	//printf("\n\nRETURNED\n\n");
	return attemptedMove;

}

int levelSelection(char fileNames[50][100], int numberOfLevels, char currentLevel[100]){

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
        	
        char message[50];
        sprintf(message,"\n'%s' is an invalid level name\n",levelName);
		
		if (found!=1){system("clear"); displayError(message);}//"\nThat is an invalid level name\n"

		else{
		
			system("clear");

			strcpy(currentLevel,levelName);
		}
	}

	return 0;
}

int getAllLevelNames(char fileNames[50][100]){

	// help from https://c-for-dummies.com/blog/?p=3246

	DIR *folder;
	struct dirent *entry;
	int files = 0;

	folder = opendir("/home/sam/wm145/maze/levels");
	
	if(folder == NULL)
	{
		perror("Unable to read directory");
    	}

    	while( (entry=readdir(folder)) )
    	{		
		if (entry->d_name[0] != '.'){
			strcpy(fileNames[files],entry->d_name);
			printf("\n%s",entry->d_name);
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

	int a;
	 
	for (a=0;a<numberOfLevels; a++){

		char * filenameForDisplay = strtok(fileNames[a],".");

                printf("\nFile %d - '%s'",a+1,filenameForDisplay);

        }

	printf("\n");
}

void endGame(){

	printf("\n BYE! \n");
	exit(1);
}

void displayLevelArray(int level[400]){
	
	int i;
	
	for (i=0; i<=400; i++){
		printf("\nlevel[%d] = %d",i, level[i]); 
		}
	
	}
	
void displayMaseHeader(){
	printf("\n");
	printf("  ██          ██    ████     ████████ \n");
	printf("  ████      ████  ██    ██        ██        \n");
	printf("  ██  ██  ██  ██  ████████      ██        \n");
	printf("  ██    ██    ██  ██    ██    ██        \n");
	printf("  ██          ██  ██    ██   █████████ \n");
	
	/*
	printf("██          ██    ████     ████████  ████████\n");
	printf("████      ████  ██    ██        ██        ██\n");
	printf("██  ██  ██  ██  ████████      ██        ██\n");
	printf("██    ██    ██  ██    ██    ██        ██ \n");
	printf("██          ██  ██    ██   ████████  ████████ \n");
	*/
	
	}

void displayLevel(int level[400], int playerPos){
	
	//printf("\n\n DISPLAY LEVEL \n\n");
	
	//displayLevelArray(level);
	displayMaseHeader();
	
	printf("\n");

	int i;
	int levelPos;
	
	int found;
	

	displayError("██");
	for (i=0;i<=400;i++){
		
		int ii;
		
		found = 0;
		
		for (ii=0;ii<400;ii++){
		
			//printf("%d = %d",i,level[ii]);
		
			if (level[ii]==i && level[ii] != 0){
				found = 1;
				}	
			}
			
		
		
		
		//printf("\nfound = %d",found);
		
		if (playerPos == i){
			
			displayValidEntry("░░");
			}
		
		else if (found == 1){
			
			displayError("██");
			
			}
			
		else if (found == 0 && i!=0){
			
			printf("  ");
			
			}
		
		if (i==19 || i == 39 || i==59 || i==79 || i==99 || i==119 || i==139 || i==159 || i==179 || i==199 || i==219 || i==239 || i==259 || i==279 || i==299 || i==319 || i==339 || i==359 || i==379 || i==399){
			printf("\n");
			
		}
		
		
	
	}
	
	printf("\nTo Play use WSAD, if you would like to quit just press 'q'\n");
	
}

void playGame(int up, int right, int down, int left, int level[400], int playerPos){
	
	int play = 1;
	
	while (true){
		
		system("clear");
		printf("\n POS = %d", playerPos);
		
	
		int directionValue;
		
		
		displayLevel(level, playerPos);
		
		directionValue = makeMove(up, right, down, left, level, playerPos);
		
		if (directionValue==5){break;}
		
		if (playerPos == 378){printf("\nyou win\n");return 0;}
		
		//printf("direcvalue = %d",directionValue);
		
		//printf("\nBPOS = %d",playerPos);
		
		playerPos = playerPos+directionValue;
		
		//printf("\nAPOS = %d",playerPos);
	
}
}

void main(){

	system("clear");
	
	
	char fileNames[50][100];
	char currentLevelName[100] = "level_default";
	int level[400];

	int numberOfLevels;
	char mainMenuOption[1];
	int playAgain = 1;
	int playerPos = 21;
	
	int up = -20;
	int right = 1;
	int down = +20;
	int left = -1;

	char message[100];


	numberOfLevels = getAllLevelNames(fileNames);
	

	makeLevel(level,currentLevelName);
	
	while (true){

		mainMenu();
		printf("\n>>> ");
		scanf("%s",&mainMenuOption);

		if (strcmp(mainMenuOption,"1") == 0){
			system("clear"); 
			displayValidEntry("\nThat is a valid entry!\n"); 
			playGame(up, right, down, left, level, playerPos);
	
		}

		else if  (strcmp(mainMenuOption,"2") == 0){
			system("clear");
			displayValidEntry("\nThat is a valid entry!\n");
			displayLevelNames(fileNames, numberOfLevels); 
		}

		else if (strcmp(mainMenuOption,"3") == 0){
			system("clear"); 
			displayValidEntry("\nThat is a valid entry!\n"); 
			levelSelection(fileNames,numberOfLevels,currentLevelName);
			
			printf("\n\033[0;32m You have selected level ");
                        printf("%s",currentLevelName);
                        printf("\033[0m\n");
		}

		else if (strcmp(mainMenuOption,"q") == 0){
			system("clear"); 
			displayValidEntry("\nThat is a valid entry!"); 
			endGame();
		}

		else{
			char message[100];
			sprintf(message,"\n'%s' is an invalid option\n",mainMenuOption);
			system("clear");
			displayError(message);
		}

	}

}

// CURRENT ISSUES
// 1. when press play game it looks like it takes an entry then displays it to the user to enter
// 2. issue with make move might just need to do again will probs take longer to figure it out why not right than rewritting it.
