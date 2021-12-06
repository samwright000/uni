#include <stdio.h>

int string(){

	char strUsername[50] = "sam";
	int intUsername = strUsername;
//	printf("\nstrUsername: %s\n",strUsername);
//	printf("\nintUsername: %d\n",intUsername);
	
	int intArray[5] = {67,67,67,67,67};

	return intArray;
}

int main(){
	//string();
	//char username[50];
	
	int intUsername;
	intUsername = string();

	char strUsername[50];
	
	//strUsername = intUsername;
	
	int intArray = string();

	int i;

	for (i=0; i<sizeof(intArray);i++){
	
		printf("%c",intArray);
	
	}
}
