class Solution {
public:
    int findLucky(vector<int>& num) {
        map<int, int> mpp;
        for (int i = 0; i < num.size(); i++) {
            mpp[num[i]]++;
        }
        int res = -1;
        for (auto &it : mpp) {
            if (it.first == it.second) {
                res = max(res, it.first);
            }
        }
        return res;
    }
};
