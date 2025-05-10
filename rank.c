#include<stdio.h>
vvoid main()
{
    int n,i,j,k;
    printf("enter no. of stuents");
    //to get no of students
    scanf("%d",&n);
    struct info 
    (    char name[10];
        int roll;
        int marks[3];
    ) s[n];
    for(i=1;i<=n;i++){
        printf("enter info of students %d",&n);
        scanf("%c %d",&s[i].name,&s[i].roll);
        for(j=1;j<=3;j++){
            printf("enter number ");
            scanf("%d",&s[i].marks[j]);
        }

    }// stored the appropriate details 
    float z[n];
    for(k=1;k<=n;k++){
        z[k]=(s[k].marks[1]+s[k].marks[2]+s[k].marks[3])/3;
    }
    for(i=1;i<=n;i++)
    printf("%f",z[i]);

}