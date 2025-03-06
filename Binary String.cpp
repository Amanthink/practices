
class Solution
{
    public:
    //Function to count the number of substrings that start and end with 1.
    long binarySubstring(int n, string a){
        
        // Your code here
        int count=0,i=0;
        while(i<n){
            if(a[i]=='1') count++;
            i++;
        }
        return count*(count-1)/2;
    }

};
