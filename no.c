#include <stdio.h>  
#include <string.h>  
int main ()  
{     
    // declare variables  
    int x,y,k;  

      
    printf (" Enter a number ");  
    scanf ("%s", &x);  

int s=0;
for(int i=1;i<=10000;i++){
    if(x==0){printf("%d",s);
}
else{
s+=x%10;
x=x/10;
}
}
}