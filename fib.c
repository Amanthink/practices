#include<stdio.h>
int fcn(int x){
    
    if(x<=2){
        return 1;
    }
    else{
        return fcn(x-1)+fcn(x-2);
    }
    
}

void main(){
    int x,y;
    printf("enter the term of fibonacci sequence \n");
    scanf("%d",&x);
    for(int i=1;i<=x;i++){
   int p=fcn(i);
   printf("%d\n",p);
    }

}

   