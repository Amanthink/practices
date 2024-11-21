#include<stdio.h>
void fcn(int x){ int p,i;
    if(x<=1){
    printf("1");
    }
    else{
       
        p=1;
        for(i=x;i>=1;i--){
            p=i*p;
        } 
    }printf("%d",p);
}
void main(){
    int x;
    printf("enter number");
    scanf("%d",&x);
    fcn(x);
}