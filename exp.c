#include<stdio.h>
void main()
{
    int n=4;
    for(int i=1; i<=n;i++)
    {
        if(i%2==1)
            for(int j=1; j<=i; j++)
                printf("%d",j);
        else
            for(int j=i; j>=1; j--)
                printf("%d",j);
        printf("\n");
    }
}