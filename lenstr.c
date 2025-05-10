#include<string.h>
#include<stdio.h>
void main(){
    char s[20];
    int x,i;
    printf("enter your string");
    scanf("%c",s);
    x=0,i=0;
    while(s[i]!= '\0'){
        
        x++;
        i++;
    }
    printf("%d",x);
}