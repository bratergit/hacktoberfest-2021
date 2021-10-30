#include <stdio.c>
#include <stdlib.c>

int multiply(int y, int x);

int main(void)
{
    printf("Add a value for y: ");
    scanf(%d, &y);
    
    printf("Add a value for x: ");
    scanf(%d, &x);
    
    printf("The end result of %d times %d is %d\n", y, x, multiply(y, x));
    return 0;
}

int multiply(int y, int x)
{
    return (x * y);
}