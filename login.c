#include <stdio.h> 
#include <conio.h> 
#include <string.h> 
 
void main() 
{ 
   
  char username[20]; 
  char userpwd[8]; // for storing password 
  int i; 
   
  printf("Enter your username : "); 
  //gets(username); 
  scanf("%s",username); 
   
  printf("Enter your password : "); 
  /* accept password */ 
 
  for(i=0;i<8;i++) 
  { 
   userpwd[i]=getch(); 
   printf("*");   	 
  } 
  userpwd[i]='\0'; 
 
/*------------------*/ 
 
  printf("\n\nPress any key to continue"); 
  getch(); 
 
 if(!strcmp(username,"sumitadmin") && !strcmp(userpwd,"sumit123")) 
 { 
  printf("\n\nLogged In Successful"); 
 }else 
 { 
  printf("\n\nIncorrect username or password"); 
 } 
}
