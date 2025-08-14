class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mac = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > mac) return false; 
            mac = max(mac, i + nums[i]);
        }
        return true;
    }
};
