
class Solution {
public:
    string inttobin(string s) {
        int num = stoi(s); // convert string to int
        if (num == 0) return "0";

        string res = "";
        while (num > 0) {
            res.push_back((num % 2) ? '1' : '0');
            num /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    string convertDateToBinary(string date) {
        string year, month, day;
        stringstream ss(date);
        getline(ss, year, '-');
        getline(ss, month, '-');
        getline(ss, day, '-');

        string ans = inttobin(year) + "-" + inttobin(month) + "-" + inttobin(day);
        return ans;
    }
};


