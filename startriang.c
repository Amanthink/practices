#include<stdio.h>
void main()
{int x,j;
    scanf("%d",&x);
    for (int i = 1; i<=x; i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("*\t");
        }
        printf("\n");
        
    }
    
}