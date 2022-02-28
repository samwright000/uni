#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h>
#include <time.h>
#include <signal.h>

//void signal_handler(int signal){} # used so that can use ctrl c to take back to menu but didn't want to do that anymroe

// display the main menu - does not take input
void mainMenu(){
	
	displayMaseHeader();


	printf("\n\n1. Play Game (default level)");
	printf("\n2. See Level Names");
	printf("\n3. Select Custom Level");
	printf("\n4. Play A Play List of All The Levels (\033[0;32mTimed\033[0m)");
	printf("\n5. Settings");
	printf("\n6. Change Directory *TODO*");
	printf("\nq.");
	displayError(" Quit");
	
}

// gets the play input and; returns 1 for up, 2 for right, 3 for down and 5 for left
// was done like this so at the start I was able to just enter w then press enter without spending the time on how i wanted to make it work in the end
// therefore using a I function which would return the same stuff no matter how the result was got  
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


// this functions makes the levels which are played
// takes in level[400] which is where the level is stored, levelname which is the file name, the level settings which is where it starts and where it ends then dir 
// which is the directory where they are stored. 
int makeLevel(int level[400], char levelName[100], int levelSettings[100], char dir[400]){
	
	//printf("start make level");

	int maze[324]; // the level which gets loaded is called maze and this is only the inner bit as the border is always the same. 
	memset(maze,0,1296); // this clears the array when the a new level is entered 
	int boarder[76] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,39,59,79,99,119, 139, 159, 179,199,219,239,259,279,299,319,339,359,379,399,380,381,382,383,384,385,386,387,388,389,390,391,392,393,394,395,396,397,398, 20,40,60,80,100,120,140,160,180,200,220,240,260,280,300,320,340,360}; // this is the boarder which is all ways the same so is stored here then is the maze and board array are both added to the level array
	char fileName[104]; // this is used to add the exection to the file the extra 4 chars. 
	char fileNameSettings[104]; // same as above but for the settings file

	char endFile[504]; // with dir too
	char endFileSettings[504];// same as above
	
	//printf("\ndir1 = %s\n",dir);
	
	//printf("\nendfile = '%s'\n",dir);
	
	sprintf(endFile,"%s/%s.txt",dir,levelName); // makes the dir and the name of the file so can be anywhere on the system
	
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

	// below gets each line of the level turns it into a int then adds it to the array. 
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


int makeMove(int up, int right, int down, int left, int level[400], int playerPos, int endPos){
	
	int validMove = 0;

	int attemptedMove;
	
	int direction;
	
	int i;
	
	int found = 0;
	
	int line = 0;
	
	// 1 = up, 2 = right, 3 = down, 4 = left
	
	//what happens is that a move is made then it checks if the move made is allowed if it is then the move direction is added to the current play position
	//if not the user is asked to enter again

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

// this allows a user to selected a different level to play 
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
	
	// returns all the files in the directory which dont start with a "."	

	
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

	return files;

}

void displayError(char message[100]){
	// changes the colour then changes back to normal
	printf("\033[0;31m");
	printf("%s",message);
	printf("\033[0m");

}

void displayValidEntry(char message[100]){
	// changes the colour of the text then changes it back
	printf("\033[0;32m");
	printf("%s",message);
	printf("\033[0m");

}

void displayLevelNames(char fileNames[50][100], int numberOfLevels){
	// prints all the avaiable levels to the user
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
	// was used for debugging 
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
	// this renders the level
	//displayLevelArray(level);
	displayMaseHeader();
	
	printf("\n");

	int i;
	int levelPos;
	
	int found;
	
// for what ever reason the top left cornor is missed out so is put here
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
	
	// displays the settings - does not change them
	
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
	// displays the settings then asks the user if they want to change them then the user enters the number of the of the setting they want to change
	// then it changes then they are displayed again and asked if they want to change or leave. 
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
		
		playerPos = playerPos+directionValue;
		
}
}

void displayLevelCreator(int level[400], int playerPos, int endPos){	
	// this renders the level
	//displayLevelArray(level);
	displayMaseHeader();
	
	printf("\n");

	int i;
	int levelPos;
	
	int found;
	
// for what ever reason the top left cornor is missed out so is put here
	//displayError("██");
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
			
			displayValidEntry(" ██|");
			}
			
		else if (endPos==i){
			printf("\033[0;35m");
			printf(" ██|");
			printf("\033[0m");
			
			}
		
		else if (found == 1){
			//if (i<100){printf(" ");}
			displayError("██");
			
			}
			
		else if (found == 0&&i!=0&&i<=399){
			if (i<100){printf(" ");}
			printf("\033[0;37m");
			printf("%d|",i);
			printf("\033[0m");

			
			
			
			}
		
		if (i==19 || i == 39 || i==59 || i==79 || i==99 || i==119 || i==139 || i==159 || i==179 || i==199 || i==219 || i==239 || i==259 || i==279 || i==299 || i==319 || i==339 || i==359 || i==379 || i==399){
			printf("\n");
			
		}
		
		
	
	}
	
	
}

void makeCustomLevel(){
	
	int playerPos = 44;
	int endPos = 45; 
	
	int makingLevelBoarder[76] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,39,59,79,99,119, 139, 159, 179,199,219,239,259,279,299,319,339,359,379,399,380,381,382,383,384,385,386,387,388,389,390,391,392,393,394,395,396,397,398, 20,40,60,80,100,120,140,160,180,200,220,240,260,280,300,320,340,360}; // this is the boarder which is all ways the same so is stored here then is the maze and board array are both added to the level array
	int makingLevelMaze[324];
	int makingLevelMazeAndBoarder[400];
	memset(makingLevelMaze,0,1296); // this clears the array when the a new level is entered 

	char makeFileName[104]; // this is used to add the exection to the file the extra 4 chars. 
	char makeFileNameSettings[104]; // same as above but for the settings file

	int editorMode = 0; // 0 = add wall, 1 = remove wall
	
	int location;
	
	while (true){
		
		int i;
		
		for (i=0;i<=324;i++){
		
		if (makingLevelMaze[i]==0){break;}
		
		//printf("\nmaze[%d] = %d",i,maze[i]);
		
		}
		
		for (i=0; i<=76; i++){

			makingLevelMazeAndBoarder[i] = makingLevelBoarder[i];
			
			}
		
		int x = 0;	
		
		for (i=77; i<=400; i++){
			
			makingLevelMazeAndBoarder[i]=makingLevelMaze[x];
			
			x++;
			
			} 
			
			
		for (i=0; i<=400; i++){
			
			printf("\nlevel[%d] = %d",i,makingLevelMazeAndBoarder[i]);
			
			}
			
		displayLevelCreator(makingLevelMaze ,playerPos, endPos);
		
		// 0 = add wall, 1 = remove wall
		
		char editingLocation[100];
		int intEditingLocation;
		
		if (editorMode == 0){
			int isValueLocation = 1;
			
			while (true){
				printf("\nPlease Enter The Value Of The Wall You Want To Add \n\n >>> ");
				scanf("%s",&editingLocation);
				intEditingLocation = atoi(editingLocation);
				printf("\n int editing location = %d\n",intEditingLocation);
				
				int a;
				for (a=0;a<=400;a++){
					
					if (intEditingLocation == makingLevelMazeAndBoarder[a] || intEditingLocation < 21 || intEditingLocation > 378){
						
						isValueLocation = 0;
						printf("1");
						
						}
					
					}
				
				if (isValueLocation == 1){printf("\nBreaking\n");break;}
				
			}
				
				int b;
				
				for (b=0;b<=400;b++){
					printf("\n in loop\n");
					
					if (makingLevelMaze[b] == 0){
						printf("\n\nsetting\n\n");
						printf("\n%d\n",intEditingLocation);
						makingLevelMaze[b] = intEditingLocation;
						printf("\n%d\n",makingLevelMaze[b]);
						break;
						
						}
					
					}
				
			}
	}




}

void main(){

	system("clear");
	
	//signal(SIGINT,  signal_handler);
	
	char fileNames[50][100]; // gets all the level names
	char fileNames2[50][100]; // then stores it in here as a save as the one above can change
	char currentLevelName[100] = "level_default"; // if a user doesn't select a level this is the default one which is loaded.
	int level[400]; // this stores the maze + boarder
	int levelSettings[100]; // the settigns of each level
	char dir[400] = "/home/csc/wm145/maze/levels"; // this is hard coded just for testing 
	
	int numberOfLevels;
	char mainMenuOption[1];
	int playAgain = 1; // if the user wants to carry on playing
	int playerPos = 21; // default start 
	int endPos = 378; // default end - both get changed when a custom level is entered 
	
	int overallGameSettings[2]; // time, count
	overallGameSettings[0] = 0; // stores the setting of the game 0 is time
	overallGameSettings[1] = 0; // 1 is number of moves use the setting menu to see 
	
	int up = -20; // this is the value which is take from the current pos when the player select up 20 because the grid is 20 blocks long
	int right = 1; // same above but right 
	int down = +20; // ''
	int left = -1;// ''
	
	time_t timeStart=time(&timeStart); // takes takes the start time so that can display to the user if they want to see how long it took for them to complete it 
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
		
		else if (strcmp(mainMenuOption,"7")==0){
			
			makeCustomLevel();
			
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

//Next time tips
//    - make a set up function then were the main menu so then u can use ctrl c to go
//      back to the menu rather than quit
