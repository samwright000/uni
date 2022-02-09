#include <stdio.h>
// Recursive function for the factorial operation
int factorial(int x){
	// When x (num1) is greater than or equal to 1
	if(x>=1){
		// We return num1*factorial(num1-1) - using recursion to do a factorial
		return x*factorial(x-1);
	}
	else{
		// If it is not greater than or equal to 1, just return 1
		return 1;
	}
}

int main(){
	// Printing the output to the user showing the available operations
	printf("Which operator will you use? \n");
	printf("1. Addition \n");
	printf("2. Subtraction \n");
	printf("3. Multiplication \n");
	printf("4. Division \n");
	printf("5. Powers \n");
	printf("6. Square Root \n");
	printf("7. Factorial \n");
	// Declaring  input, output, num1, num2 and i
	int input;
	float output;
	float num1;
	float num2;
	int i;
	// Taking user input and storing it into the variable input
	scanf("%d", &input);
	// New line
	printf("\n");
	
	// If the addition function is chosen (input == 1)
	if(input == 1){
		// Printing output and prompts
		printf("Addition operation \n");
		printf("Enter your first number \n");
		// Taking 2 numbers as input from the user
		scanf("%f", &num1);
		printf("Enter your second number \n");
		scanf("%f", &num2);
		// Adding the 2 numbers together
		output = num1 + num2;
		// Outputting to the screen the result of the addition
		printf("\n%.2f + %.2f = %.2f \n" ,num1 , num2, output);
	}
	
	// If the subtraction operation is chosen (input == 2)
	else if(input == 2){
		// Printing output and prompts
		printf("Subtraction operation \n");
		printf("Enter your first number \n");
		// Taking 2 numbers as input from the user
		scanf("%f", &num1);
		printf("Enter your second number \n");
		scanf("%f", &num2);
		// Subtracting the 2nd number from the first number
		output = num1 - num2;
		// Outputting the result of the subtraction to the screen
		printf("\n%.2f - %.2f = %.2f \n" ,num1 , num2, output);		
	}
	// If the multiplication operation is chosen (input == 3)
	else if(input == 3){
		// Printing output and prompts
		printf("Multiplication operation \n");
		printf("Enter your first number \n");
		// Taking 2 numbers as input from the number
		scanf("%f", &num1);
		printf("Enter your second number \n");
		scanf("%f", &num2);
		// Multiplying the 2 numbers together
		output = num1 * num2;
		// Outputting the result of the multiplication
		printf("\n%.2f x %.2f = %.2f \n" ,num1 , num2, output);		
	}
	// If the division operation is chosen (input == 4)
	else if(input == 4){
		// Printing output and prompts
		printf("Division operation \n");
		printf("Enter your first number \n");
		// Taking 2 numbers as input from the user
		scanf("%f", &num1);
		printf("Enter your second number \n");
		scanf("%f", &num2);
		// Dividing number 1 by number 2
		output = num1 / num2;
		// Printing the result of the division
		printf("\n%.2f / %.2f = %.2f \n" ,num1 , num2, output);	
	}
	// If the powers operation is chosen (input == 5)
	else if(input == 5){
		// Printing output and prompts to te user
		printf("Powers operation \n");
		printf("Enter your number \n");
		// Taking 2 nums as input from the user
		scanf("%f", &num1);
		printf("Enter your power \n");
		scanf("%f", &num2);
		// Declaring temp value for use in loop
		float temp = num1;
		// Loop from i is 0 while it is less than the power input by the user
		for(i = 0; i < num2-1 ; i++){
			// Calculation to get the num1^num2
			num1 = num1 * temp;
		}
		// Printing the result of the power operation (num1^num2)
		output = num1;
		printf("\n%.0f^%.0f = %.0f \n" ,num1 , num2, output);		
	}
	// Root operation (input == 6)
	else if(input == 6){
		printf("Square root operation \n");
		printf("Enter a whole number \n");
		// Taking one number as input
		scanf("%f", &num1);
		// Calculating the square root of num1 using a linear method
		// This is not the most efficient method but it works like a linear search
		for(i=1; i < num1; i++){
			if((i * i) == num1){
				output = i;
				// Breaking the loop when the root is found
				break;
			}
		}
		
		printf("\nThe square root of %.0f = %.0f \n" ,num1 , output);
	}
	// Factorial
	else if(input ==7){
		printf("Factorial operation \n");
		// Taking 1 input
		printf("Enter a whole number \n");
		scanf("%f", &num1);
		// Calling the factorial function with the number num1
		output = factorial(num1);
		// Result
		printf("\n%.0f! = %.0f \n" ,num1 , output);	
	}
	// If one of the assigned numbers is not chosen, an error message is displayed
	else{
		printf("Enter a number which is linked to an operation above \n");	
	}
}
