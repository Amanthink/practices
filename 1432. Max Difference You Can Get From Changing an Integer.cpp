
class Solution {
public:
    int maxDiff(int num) {
        // Step 1: Turn number into a string like "1234"
        string s = to_string(num);

        // ----------- Make the biggest number -----------
        string maxStr = s;  // copy the original number
        char fromMax = '\0';  // the digit we will replace

        // Step 2: Look for the first digit that is not '9'
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '9') {
                fromMax = s[i];  // we want to replace this digit
                break;
            }
        }

        // Step 3: Replace all of that digit with '9'
        if (fromMax != '\0') {  // if we found one
            for (int i = 0; i < maxStr.length(); i++) {
                if (maxStr[i] == fromMax) {
                    maxStr[i] = '9';  // change it to '9'
                }
            }
        }

        // ----------- Make the smallest number -----------
        string minStr = s;  // copy the original number again
        char fromMin = '\0';
        char toMin = '\0';

        // Step 4: Try to make the number small
        if (s[0] != '1') {
            fromMin = s[0];  // if the first digit is not '1', change it to '1'
            toMin = '1';
        } else {
            // If the first digit is already '1', look for a digit after that
            for (int i = 1; i < s.length(); i++) {
                if (s[i] != '0' && s[i] != '1') {
                    fromMin = s[i];
                    toMin = '0';  // change that digit to '0'
                    break;
                }
            }
        }

        // Step 5: Replace all fromMin with toMin
        if (fromMin != '\0') {
            for (int i = 0; i < minStr.length(); i++) {
                if (minStr[i] == fromMin) {
                    minStr[i] = toMin;
                }
            }
        }

        // Step 6: Turn strings back to numbers
        int big = stoi(maxStr);
        int small = stoi(minStr);

        // Step 7: Return the difference
        return big - small;
    }
};
