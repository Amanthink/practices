class Solution {
public:
    string reverse(string s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
        return s;
    }

    string reverseWords(string s) {
        int left = 0;
        string l = "", ans = "";

        while (left < s.size()) {
            if (s[left] != ' ') {
                l.push_back(s[left]);
            } else {
                ans += reverse(l) + " ";
                l.clear();
            }
            left++;
        }

        if (!l.empty()) {
            ans += reverse(l);
        }

        return ans;
    }
};
