#include<stdio.h>
void fcn(int x, int y){
    int p;
    p=x;
    x=y;
    y=p;
    printf("after swaping\nX=%d\nY=%d",x,y);
}
void main(){
    int x,y;
    printf("enter two numbers");
    scanf("%d %d",&x,&y);
    printf("before swaping\nX=%d\nY=%d\n",x,y);
    fcn(x,y);
}
