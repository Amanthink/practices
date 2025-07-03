class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int i = 0, n = s.size();

        // Step 1: Skip leading spaces
        while (i < n && s[i] == ' ') i++;

        while (i < n) {
            string word = "";

            // Step 2: Extract each word
            while (i < n && s[i] != ' ') {
                word += s[i++];
            }
            words.push_back(word);

            // Step 3: Skip spaces between words
            while (i < n && s[i] == ' ') i++;
        }

        // Step 4: Reverse the words
        reverse(words.begin(), words.end());

        // Step 5: Join with single spaces
        string result = "";
        for (int j = 0; j < words.size(); j++) {
            result += words[j];
            if (j != words.size() - 1)
                result += ' ';
        }

        return result;
    }
};
151. Reverse Words in a String
