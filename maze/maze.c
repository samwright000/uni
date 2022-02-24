#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h>
#include <time.h>
#include <signal.h>

//void signal_handler(int signal){}

void mainMenu(){
	
	displayMaseHeader();


	printf("\n\n1. Play Game (default level)");
	printf("\n2. See Level Names");
	printf("\n3. Select Custom Level");
	printf("\n4. Play A Play List of All The Levels (\033[0;32mTimed\033[0m)");
	printf("\n5. Settings");
	printf("\n6. Change Directory");
	printf("\nq.");
	displayError(" Quit");
	
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

int makeLevel(int level[400], char levelName[100], int levelSettings[100], char dir[400]){
	
	//printf("start make level");

	int maze[324];
	memset(maze,0,1296);
	int boarder[76] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,39,59,79,99,119, 139, 159, 179,199,219,239,259,279,299,319,339,359,379,399,380,381,382,383,384,385,386,387,388,389,390,391,392,393,394,395,396,397,398, 20,40,60,80,100,120,140,160,180,200,220,240,260,280,300,320,340,360};
	char fileName[104];
	char fileNameSettings[104];

	char endFile[504];
	char endFileSettings[504];
	
	//printf("\ndir1 = %s\n",dir);
	
	//printf("\nendfile = '%s'\n",dir);
	
	sprintf(endFile,"%s/%s.txt",dir,levelName);
	
	sprintf(endFileSettings,"%s/.%s.config",dir,levelName);
	
	//strtok(endFile,"\n");
	
	//printf("\nendfile = '%s'\n",endFile);
	
	//printf("\nendfilesettings = '%s'\n",endFileSettings);
	
	int intLine;
	
	//sprintf(fileName,"/home/sam/wm145/maze/levels/%s.txt",levelName);//home/sam/wm145/maze/levels/level1.txt
	//printf("%s",fileName);
	//sprintf(fileNameSettings,"/home/sam/wm145/maze/levels/.%s.config",levelName);
	
	//printf("\nDEBUG - Level Loaded = %s\n",fileName);
	
	FILE *fp;

	
	char line[100];

	fp = fopen(endFile,"r");

	int i = 0;


	while (fgets(line,100,fp) && fgets != 0){
		intLine = atoi(line);
	//	printf("\nline int %d",intLine);
		
		if (intLine == 0){break;}
		
		maze[i] = intLine;
		
		i++;
		
		memset(line,0,100);
		
		}
		
	//printf("\n next \n");
	
	fclose(fp);
	
	fp = fopen(endFileSettings,"r");

	i = 0;
	
	//printf("\n next\n");

	while (fgets(line,100,fp) && fgets != 0){
		//printf("\n next in \n");
		intLine = atoi(line);
		//printf("\nline int %d",intLine);
		
		if (intLine == 0){break;}
		
		levelSettings[i] = intLine;
		
		i++;
		
		memset(line,0,100);
		
		}
		
		//printf("levelsetting 0 = %d",levelSettings[0]);
		//printf("levelsettings 1 = %d",levelSettings[1]);
		
	//printf("\n next\n");
		
	for (i=0;i<=324;i++){
		
		if (maze[i]==0){break;}
		
		//printf("\nmaze[%d] = %d",i,maze[i]);
		
		}
		
	for (i=0; i<=76; i++){

		level[i] = boarder[i];
		
		}
	
	int x = 0;	
	
	for (i=77; i<=400; i++){
		
		level[i]=maze[x];
		
		x++;
		
		} 
		
		//printf("\nhello\n");
		
	for (i=0; i<=400; i++){
		
		//printf("\nlevel[%d] = %d",i,level[i]);
		
		}
		
			
	fclose(fp);

	
	return 0;

	// above is the boarder around the end load that into the levels array in the correct location. 

}

int checkIfValidMove(){
	
	
	
	}

int makeMove(int up, int right, int down, int left, int level[400], int playerPos, int endPos){
	
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
			
			displayLevel(level, playerPos,endPos);
			
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
		
		displayMaseHeader();

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

int getAllLevelNames(char fileNames[50][100],char dir[400]){

	// help from https://c-for-dummies.com/blog/?p=3246

	DIR *folder;
	struct dirent *entry;
	int files = 0;

	folder = opendir(dir);
	

	
	if(folder == NULL)
	{
		perror("Unable to read directory");
		return 0;
    	}

    	while((entry=readdir(folder)) )
    	{		
		if (entry->d_name[0] != '.'){
			strcpy(fileNames[files],entry->d_name);
			//printf("\n%s",entry->d_name);
			files++;
		}
    	}

    	closedir(folder);
    	
    	int i;
    	
    	for (i=0;i<files;i++){
			
		//	printf("\nDEBUG FILE = %s\n",fileNames[i]);
			
			}

	//scanf("%s");
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
	int i;

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
		//printf("\nlevel[%d] = %d",i, level[i]); 
		}
	
	}
	
void displayMaseHeader(){
	
	// Yes i know it spelt wrong... its meant to be quirky >:)
	
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

void displayLevel(int level[400], int playerPos, int endPos){
	
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
			
			displayValidEntry("██");
			}
			
		else if (endPos==i){
			printf("\033[0;35m");
			printf("██");
			printf("\033[0m");
			
			}
		
		else if (found == 1){
			
			displayError("██");
			
			}
			
		else if (found == 0&&i!=0&&i<=399){
			
			printf("\033[0;37m");
			printf("██");
			printf("\033[0m");
			
			
			
			}
		
		if (i==19 || i == 39 || i==59 || i==79 || i==99 || i==119 || i==139 || i==159 || i==179 || i==199 || i==219 || i==239 || i==259 || i==279 || i==299 || i==319 || i==339 || i==359 || i==379 || i==399){
			printf("\n");
			
		}
		
		
	
	}
	
	printf("\nTo Play use WSAD, if you would like to quit just press 'q'\n");
	
}

void displayOverAllGameSettings(int overallGameSettings[2]){
	
	
	displayMaseHeader();
	
	printf("\n Welcome to the settings the current settings are:");
	
	printf("\n\n	1. Should the player length of time be recorded is ");
	
	if (overallGameSettings[0] == 0){
		
		printf("off.\n");
		
		}
		
	else{
		printf("on.\n");
		}
		
	printf("\n	2. Should the number of moved made be counted is ");
	
	if (overallGameSettings[1] == 0){
		
		printf("off.\n");
		
		}
		
	else{
		printf("on.\n");
		}		
	
	
	
	}
	
void changeOverallSettings(int overallGameSettings[2]){
	
	char shouldChangeSettings[100];
	
	while(true){
	
		while (true){
			
		displayOverAllGameSettings(overallGameSettings);
		
		
		printf("\nWould you like to edit the settings? (y/n)\n\n>>> ");
		scanf("%s",&shouldChangeSettings);
		
		if (strcmp(shouldChangeSettings,"y")==0){
			
			break;	
			
			}
			
		else if (strcmp(shouldChangeSettings,"n")==0){
			system("clear");
			
			return;
			
			}
			
		else{
				system("clear");
				printf("\033[0;31m");
				printf("\n'%s' is an invalid option, please enter 'y' for yes or 'n' for no!\n",shouldChangeSettings);
				printf("\033[0m");
			
			}
		
	}
	
	
	
	while (true){
	
		printf("\nEnter the number of the setting you want to change (this will toggle it on or off)\n\n>>> ");
		
		char change[100];
		
		scanf("%s",&change);
		
		if (strcmp(change,"1")==0){
			system("clear");
			
			if (overallGameSettings[0] == 1){overallGameSettings[0]=0;}
			else{overallGameSettings[0] = 1;}
			break;
		}
		
		if (strcmp(change,"2")==0){
				system("clear");
				if (overallGameSettings[1] == 1){overallGameSettings[0]=0;}
				else{overallGameSettings[1] = 1;}
				break;

		}
			
		else{
			
			system("clear");
			
			displayError("\nInvalid Setting Input, Please Enter From The Numbers Below!\n");
			displayOverAllGameSettings(overallGameSettings);
				
			}
			// fix here that is works just run it and you will see it doesn't work
		}
	}
}

void playGame(int up, int right, int down, int left, int level[400], int playerPos, int endPos, int numberOfMoves[1]){
	
	int play = 1;
	
	while (true){
		
		system("clear");
		//printf("\n POS = %d", playerPos);
		
	
		int directionValue;
		
		
		displayLevel(level, playerPos,endPos);
		
		if (playerPos == endPos){return 0;}
		
		directionValue = makeMove(up, right, down, left, level, playerPos, endPos);
		numberOfMoves[0]=numberOfMoves[0]+1;
		
		if (directionValue==5){break;}
		
		
		
		//printf("direcvalue = %d",directionValue);
		
		//printf("\nBPOS = %d",playerPos);
		
		playerPos = playerPos+directionValue;
		
		//printf("\nAPOS = %d",playerPos);
	
}
}

void main(){

	system("clear");
	
	//signal(SIGINT,  signal_handler);
	
	char fileNames[50][100];
	char fileNames2[50][100];
	char currentLevelName[100] = "level_default";
	int level[400];
	int levelSettings[100];
	char dir[400] = "/home/sam/wm145/maze/levels";
	
	int numberOfLevels;
	char mainMenuOption[1];
	int playAgain = 1;
	int playerPos = 21;
	int endPos = 378;
	
	int overallGameSettings[2]; // time, count
	overallGameSettings[0] = 0;
	overallGameSettings[1] = 0;
	
	int up = -20;
	int right = 1;
	int down = +20;
	int left = -1;
	
	time_t timeStart=time(&timeStart);
	time_t timeEnd;
	time_t timeTaken;
	int numberOfMoves[1];

	char message[100];
	
	while (numberOfLevels < 1){
		
		printf("Please Enter the Directory of where the level files are located (this can be done by using the 'pwd' command in the terminal)\nUsally Looks like ❝/home/'computer user'/'then the path'❞ \n>>> ");
		
		numberOfLevels = getAllLevelNames(fileNames,dir);
		
		int i;

		for (i=0;i<numberOfLevels;i++){
			strcpy(fileNames2[i],fileNames[i]);
		}

		if (numberOfLevels == 0){
			displayError("\nERROR - THERE ARE NO NUMBER OF LEVELS\n\n");
			}
	}
	
	int makeOne = 0;

	makeLevel(level,currentLevelName,levelSettings,dir);
	
	while (1==1){
		
	//	printf("\nin while true\n");

		mainMenu();
		printf("\n\n>>> ");
		scanf("%s",&mainMenuOption);

		if (strcmp(mainMenuOption,"1") == 0){
			system("clear");

			displayValidEntry("\nThat is a valid entry!\n"); 
			playerPos = levelSettings[0];
			endPos = levelSettings[1];
			

			time(&timeStart);
			playGame(up, right, down, left, level, playerPos,endPos,numberOfMoves);
			time(&timeEnd);
			system("clear");
			timeTaken = timeEnd-timeStart;
			
			if (overallGameSettings[0] == 1){
			
				printf("\n\nIt took you %ld seconds to complete the level, well done!!! :)\n\n",timeTaken);
			}
			
			if (overallGameSettings[1] == 1){
				
				printf("\n\nIt took %d number of moves to get to the exit!\n\n",numberOfMoves[0]);
				
			}
			
			timeTaken = 0;
			numberOfMoves[0]=0;
	
		}

		else if  (strcmp(mainMenuOption,"2") == 0){
			system("clear");
			displayValidEntry("\nThat is a valid entry!\n");
			
			displayLevelNames(fileNames2, numberOfLevels);
			}
		
		

		else if (strcmp(mainMenuOption,"3") == 0){
			system("clear"); 
			displayValidEntry("\nThat is a valid entry!\n"); 		
					
				levelSelection(fileNames2,numberOfLevels,currentLevelName);
			
				printf("\n\033[0;32m You have selected level ");                        
				printf("%s",currentLevelName);
            	printf("\033[0m\n");
            	memset(level,0,400);
            	makeLevel(level,currentLevelName,levelSettings,dir);
					
			}
		
		else if (strcmp(mainMenuOption,"4") == 0){
			
			
			DIR *folder;
			struct dirent *entry;
			int files = 0;

			folder = opendir(dir);
			

			
			if(folder == NULL)
			{
				perror("Unable to read directory");
				return 0;
				}

				while((entry=readdir(folder)) )
				{		
				if (entry->d_name[0] != '.'){
					strcpy(fileNames[files],entry->d_name);
					//printf("\n%s",entry->d_name);
					files++;
				}
				}

				closedir(folder);
				
				int i;
				
				for (i=0;i<files;i++){
					
					//printf("\nDEBUG FILE = %s\n",fileNames[i]);
					
					//printf("\nlevlename2 = %s",fileNames[i]);
					
					char * filenameForDisplay = strtok(fileNames[i],".");
					
					
					
					makeLevel(level,filenameForDisplay,levelSettings,dir);
					playerPos = levelSettings[0];
					endPos = levelSettings[1];
					playGame(up, right, down, left, level, playerPos,endPos,numberOfMoves);
					
					}
					
				
				system("clear");
				
			}
			
		else if (strcmp(mainMenuOption,"5") == 0){
			
			system("clear");
			
			changeOverallSettings(overallGameSettings);
			
			}
			
		else if (strcmp(mainMenuOption,"6")==0){
			
			printf("\nin 6\n");
			numberOfLevels = 0;
			int i=0;
			memset(fileNames,0,100);
			memset(fileNames2,0,100);
			
			while (numberOfLevels < 1){
		
				printf("Please Enter the Directory of where the level files are located (this can be done by using the 'pwd' command in the terminal)\nUsally Looks like ❝/home/'computer user'/'then the path'❞ \n>>> ");
				scanf("%s",&dir);
				
				numberOfLevels = getAllLevelNames(fileNames,dir);
				


				for (i=0;i<numberOfLevels;i++){
					strcpy(fileNames2[i],fileNames[i]);
				}

				if (numberOfLevels == 0){
					displayError("\nERROR - THERE ARE NO NUMBER OF LEVELS\n\n");
					}
			}

			//makeLevel(level,currentLevelName,levelSettings,dir);
		
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
// 1. add to be able to change directory while in main menu
// 2. make a file with all times and moves 

//Next time tips
//    - make a set up function then were the main menu so then u can use ctrl c to go
//      back to the menu rather than quit
