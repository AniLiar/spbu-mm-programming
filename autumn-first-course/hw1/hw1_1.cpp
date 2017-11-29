//#include <stdio.h>

int main(void) 
{
    printf("Enter an integer value for the variable\n");
    int x = 0;
    scanf("%d", &x);
    
    int sqrX = x * x;
    int result = (sqrX + 1) * (sqrX + x) + 1;
    
    printf("Result = %d", result);
    return 0;
}
