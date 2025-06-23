class Solution {
public:
    bool isKPal(string str,int k){
        long long num = stoll(str);
        string kNum = "";
        while(num){
            kNum += to_string(num%k);
            num/=k;
        }
        for(int i=0;i<kNum.size()/2;i++){
            if(kNum[i]!=kNum[kNum.size()-1-i]){
                return false;
            }
        }
        return true;
    }
    long long kMirror(int k, int n) {
        long long ans = 0;
        int cnt = 0;
        int num = 1;
        int prev = 1;
        while(cnt<n){
            for(int x = 0 ; x <=1 ; x++){
                int it = 10*num - num;
                while(cnt<n && it--){
                    string s1 = to_string(num);
                    string s2 = s1;
                    s2.pop_back();
                    reverse(s2.begin(),s2.end());
                    if(x==0){
                        string odd = s1 + s2;
                        // cout << odd << endl;
                        if(isKPal(odd,k)){
                            cnt++; ans += stoll(odd);
                        }
                    }else{
                        string even = s1 + s1[s1.size()-1] + s2;
                        // cout << even << endl;
                        if(isKPal(even,k)){
                            cnt++; ans += stoll(even);
                        }                        
                    }
                    num++;
                    
                }
                if(x==0) num = prev;
                else{
                    prev = num;
                }
            }
        }
        return ans;
    }
};
