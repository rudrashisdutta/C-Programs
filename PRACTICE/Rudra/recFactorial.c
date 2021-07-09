#include <stdio.h> 
int factorial(unsigned int n)
{
	if(n==0)
		return 1;
	return n*factorial(n-1);
}
void main()
{
    int num;
    printf("Enter a number:\t");
    scanf("%d",&num);
	printf("Factorial of %d is %d",num,factorial(num));
}

//if you dont feel strong everyday, thats okay and thats normal.. and everyday something new can inspire you...
// in a small thought or idea can change the course of your day.. youre never alone and youre never stuck no matter how down you feel.