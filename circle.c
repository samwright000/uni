#include <stdio.h>
int main()
{	
	int radius;
        float  area = 3.14159 * (radius * radius);
	
	printf("Please Enter a Radius: ");
	scanf("%i", &radius); //scanf is the input from python. is it telling its an interger then we pass the var of what we are going to change

	printf("The area of a circle with a radius of %i is %f!\n",radius,area);
}
