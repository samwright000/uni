#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Colour definitions
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KRED  "\033[0;31m"
#define KBLU  "\033[0;34m"
#define KWHT  "\033[0;37m"


int counter = 0;
int position, sym, p, k, i, r, length, num, player1, player2;

void table();
void check();
void color();

int flag = 0;
int replayflag = -1;
int running = -1;

char endgame[1];

char yes[] = "y";
char no[]="n";


// DEFAULT: Board with numbers. 
char box[9]={'1','2','3','4','5','6','7','8','9'};
char box2[9]={'1','2','3','4','5','6','7','8','9'};

char* color2[9];
char* c;



int main(){

    while(running == -1){
        system("clear");

        // This for loop creates an array of "box", populating each position of an empty space.
        for(i=0; i<9; i++){
            color2[i]=KWHT;
        }
        
        for(i=0; i<9; i++){
            box[i]=box2[i];
        }
        
        while(counter < 10){


            // This if and else statement keeps track who's turn it is, by seeing whether the counter number is an odd or an even integer (due to this, unfortunately player1 always starts).
            // It also changed the necessary variables depending on who's turn it is.
            // Here you can change the colours as you like. You can define your own colours if you're feeling adventurous! (See beginning of code for example.)
            if(counter % 2 == 0 ){
                sym = 'x';
                p = 1;
                c = KRED;

            } else if (counter % 2 == 1 ) {
                sym = 'o';
                p = 2;
                c = KBLU;
            }

            
            // This section prints the board, where each position corresponds to a value within the array.
            table();


            // This section takes player input and checks whether it's an integer
            printf("\n%splayer%d%s, what's your move? (1-9): ",c, p, KWHT);
            scanf("%d", &position);
            while ((getchar()) != '\n');


            // This section checks for whether or not the inputted position number is a valid number (within 1-9).
            if (position < 1 || position > 9){
                system("clear");
                printf("Invalid position input. Please enter a valid position, which ranges from 1 to 9.\n\n");
                continue;
            }   


            // This section checks whether the position that a player chose is taken or not.
            // The if statement checks whether a "box" in a certain position already has a char value of "x" or "o".
            // It's important to remember that all arrays have 0 as the index of their first element, therefore we need to minus 1 from the position entered by a player.
            // If yes, the condition executes and returns to the beginning of the loop.
            if (box[position-1] == 'x' || box[position-1] == 'o'){
                system("clear");
                printf("Sorry big boi, that position is taken. Pick one that's open!\n\n");
                continue;
            }



            // If both of the previous conditions are not met the counter is incremented and box[position] is populated with an accurate symbol.
            box[position-1]=sym;
            counter++;
            system("clear");
        
            // Necessary colours are set and the color2 array is populated accordingly. This basically uses the array to manipulate terminal text colours.
            color();

            // Checking whether anybody has won. Look at check() function for more detail.
            check();

            if (flag == 1){
                table();
                while (replayflag == -1){
                    printf("%sWould you like to play again?\n",KWHT);
                    printf("(y/n): ");
                    scanf("%s", endgame);

                    if(strcmp(endgame,yes)==0){
                        replayflag = 0;
                    }else if (strcmp(endgame,no)==0){
                        replayflag = 1;
                    }else{
                        printf("\nInvalid input\n");
                    }
                }

                
                if(replayflag == 0){
                    counter = 0;
                    flag = 0;
                    replayflag = -1;
                    position=0;
                    break;
                }else if (replayflag == 1){
                    running = 0;
                    printf("\nThank you for playing!\n");
                    break;
                }
            }
        }
    }
}















void table(){
    // This section prints the board, where each position corresponds to a value within the array.
    // This is where the colours of the symbols gets handled by the color2 array.
    // Check the color function to see how each colours are set.
    // Colours are defined at the top of code.
    
    printf("\n  %s%c%s  │  %s%c%s  │  %s%c%s       Leaderboard:\n",             color2[0], box[0], KWHT, color2[1], box[1], KWHT, color2[2], box[2], KWHT);
    printf("─────┼─────┼─────     %sPlayer1:%s %d\n",                           KRED, KWHT, player1);
    printf("  %s%c%s  │  %s%c%s  │  %s%c%s       %sPlayer2:%s %d\n",            color2[3], box[3], KWHT, color2[4], box[4], KWHT, color2[5], box[5], KWHT, KBLU, KWHT, player2);
    printf("─────┼─────┼─────\n");
    printf("  %s%c%s  │  %s%c%s  │  %s%c%s  \n\n",                              color2[6], box[6], KWHT, color2[7], box[7], KWHT, color2[8], box[8], KWHT);
                                        
}

void check(){
    // I'm aware that there's probably a better way to implement this, but here's a very simple and straight forward way to check which player has won.
    // The computer quickly checks to see whether any of the coditions have been met and which player has won.
    // This is the function checking winning scenarios:

    // Rows 
    if ((box[0] == sym && box[1] == sym && box[2] == sym)||(box[3] == sym && box[4] == sym && box[5] == sym)||(box[6] == sym && box[7] == sym && box[8] == sym)){
        if (flag!=1){
            printf("%sPlayer%d won!%s\n\n",c, p, KWHT);
            if(sym=='x'){
                player1++;
            }else{
                player2++;
            }
            flag++;
        }   
    }

    // Collumns
    if ((box[0] == sym && box[3] == sym && box[6] == sym)||(box[1] == sym && box[4] == sym && box[7] == sym)||(box[2] == sym && box[5] == sym && box[8] == sym)){
        if (flag!=1){
            printf("%sPlayer%d won!%s\n\n",c, p, KWHT);
            if(sym=='x'){
                player1++;
            }else{
                player2++;
            }
            flag++;
        }
    }

    // Diagonals
    if ((box[0] == sym && box[4] == sym && box[8] == sym)||(box[2] == sym && box[4] == sym && box[6] == sym)){
        if (flag!=1){
            printf("%sPlayer%d won!%s\n\n",c, p, KWHT);
            if(sym=='x'){
                player1++;
            }else{
                player2++;
            }
            flag++;
        }
    }

    // Checks for Stalemate
    if (counter==9){
        if (flag!=1){
            printf("%sStalemate!\n\n%s",KYEL,KWHT);
            flag++;
        }
    }
}


// Manipulating the colour array according to the symbols.
void color(){
    if (box[position-1]=='x'){
        color2[position-1] = c;
    }else if (box[position-1]=='o'){
        color2[position-1] = c;
    }else{
        color2[position-1] = KWHT;
    }
}