#include <stdio.h>
#include <math.h>

int main(void) 
{
    printf("Enter the integer value of the dividend a =\n");
    int a = 0;
    scanf("%d", &a);
        
    printf("Enter the integer value of the divisor b =\n");
    int b = 0;
    scanf("%d", &b);
    
    if(b != 0)
    {
        bool isPositive = true;
        if (((a > 0) && (b < 0)) || ((a < 0) && (b > 0)))
        {
            isPositive = false;
        }
    
        int q = abs(a);
        int absB = abs(b);
        int counter = 0;
    
        while(q > absB)
        {
            q -= absB;
            counter++;
        }
    
        if(isPositive)
        {
           printf("Result = %d", counter);	
        }
        else
        {
            printf("Result = %d", 0 - counter);
        }
    }
    else
    {
        printf("You can't divide by zero");
    }
    return 0;
}