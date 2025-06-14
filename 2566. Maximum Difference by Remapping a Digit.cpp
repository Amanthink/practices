class Solution {
public:
    int minMaxDifference(int num) {
        string str = to_string(num);
        int n = str.size();
        int i = 0;
        while(str[i]=='9'){ 
            i++;
        }
        if(i==n){
         
            return num;
        }
        string mx = str, mn = str;
        for(int j=0;j<n;j++){
            if(str[j]==str[i]){
                mx[j] = '9';
            }
        }
        for(int j=0;j<n;j++){
            if(str[j]==str[0]){
                mn[j] = '0';
            }
        }
        return stoi(mx) - stoi(mn);
    }
};
