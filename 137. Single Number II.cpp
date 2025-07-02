class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) freq[num]++;
        for (auto& [num, count] : freq) {
            if (count == 1) return num;
        }
        return -1; // If none found
    }
};
