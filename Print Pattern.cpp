class Solution{
public:
    vector<int> pattern(int n){
        // code here
        vector<int> ans;
        if(n==0)
        return ans;
        int temp=n;
        ans.push_back(n);
        while(temp>=0){
        temp-=5;
        ans.push_back(temp);
        
        }
        while(temp<n){
            temp+=5;
            ans.push_back(temp);
        }
        return ans;
    }
};
