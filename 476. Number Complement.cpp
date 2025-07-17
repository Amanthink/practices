class Solution {
public:
    string intToBin(int n) {
    if (n == 0) return "0";
    string res = "";
    while (n > 0) {
        res = char('0' + (n % 2)) + res;
        n /= 2;
    }
    return res;
}
int binToInt(const string& bin) {
    int res = 0;
    for (char c : bin) {
        res = res * 2 + (c - '0');
    }
    return res;
}
string complement(const string& bin) {
    string res = "";
    for (char c : bin) {
        res += (c == '0' ? '1' : '0');
    }
    return res;
}

    int findComplement(int num) {
        string s=intToBin(num);
        return binToInt(complement(s));
    }
};
