class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int count = 0;   
        
        int i = 0;
        int n = s.length();  
        string group = "";   
        vector<string> result;

        while (i < n) {
            group += s[i];
            count++;
            i++;

           
            if (count == k) {
                result.push_back(group);
                group = "";
                count = 0;
            }
        }

       
        if (count > 0) {
            while (count < k) {
                group += fill;
                count++;
            }
            result.push_back(group);
        }

        return result;
    }
};
