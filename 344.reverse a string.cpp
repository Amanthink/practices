class Solution {
public:
    void reverseString(vector<char>& s) {
        int left=0,high=s.size()-1;
        while(left<=high){
            swap(s[left],s[high]);
            left++;
            high--;
        }
    }
};
