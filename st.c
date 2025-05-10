#include <stdio.h>  
#include <string.h>  
int main ()  
{     
    // declare variables  
    char str1[30];  
    int i, len, flag = 0;  
      
    printf (" Enter a string: ");  
    scanf ("%s", str1);  
    len = strlen( str1 ); // get the string length  
      
      
    for ( i = 0; i < len; i++)  
    {     
        // str1[i] is not equal to str1[len-i-1]  
        if (str1[i] != str1[len - i - 1])  
        {  
            flag = 1;   
            break; // exit from if statement  
        }  
    }  
    if (flag)  
    {  
        printf (" %s is not a palindrome string", str1);  
    }  
    else  
    {  
        printf (" %s is a palindrome", str1);  
    }  
    return 0;  
}  