/*Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time, return that integer.

 

Example 1:

Input: arr = [1,2,2,6,6,6,6,7,10]
Output: 6
Example 2:

Input: arr = [1,1]
Output: 1
 

Constraints:

1 <= arr.length <= 104
0 <= arr[i] <= 105*/
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
  class Solution {
public:
    int findSpecialInteger(vector<int>& nums) {
        int n = nums.size(); 

        for (int i = 0; i < n; i++) {
            int count = 1; 
            int current = nums[i]; 
            
            if (n == 1) { 
                return current; 
            }

            for (int j = i + 1; j < n; j++) { 
                if (nums[j] == current) {
                    count++;
                } else {
                    break; 
                }

                if (count > n / 4) {
                    return current;
                }
            }
        }

        return -1;
    }
};
