class Solution {
public:
    string reverseChunk(string s) {
        reverse(s.begin(), s.end());
        return s;
    }

    string reverseStr(string s, int k) {
        string ans = "";
        for (int i = 0; i < s.size(); i += 2 * k) {
            string firstK = s.substr(i, k);
            string reversedFirstK = reverseChunk(firstK);
            ans += reversedFirstK;

            if (i + k < s.size()) {
                string nextK = s.substr(i + k, k);
                ans += nextK;
            }
        }
        return ans;
    }
};
