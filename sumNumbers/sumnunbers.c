#include <stdio.h>
#include <stdlib.h>

int sumNumbers(int x, int y);

int main (void)
{
    int x, y; 
    printf("enter the first number: ");

    scanf("%d",&x);
    printf("enter the second number: ");
    scanf("%d",&y);
    printf("The sum of %d + %d is %d\n", x, y, sumNumbers(x,y));
    return 0;
}

int sumNumbers(int x, int y)
{
    return x + y;
}