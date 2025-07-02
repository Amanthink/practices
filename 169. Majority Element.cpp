/*Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 */













||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||




class Solution {
public:
    int majorityElement(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {       
            int p = nums[i];
            int q = 0; 

            for (int j = 0; j < nums.size(); j++) {
                if (p == nums[j]) {
                    q++;
                }
            }

            if (q > nums.size() / 2) { 
                return p;
            }
        }
        return -1; 
    }
};
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
 <h3> voting algorithm</h3>
 class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;       // Counter to track majority candidate
        int candidate = 0;   // Potential majority element

        // First pass: Find the candidate
        for (int num : nums) {
            if (count == 0) {
                // If count drops to zero, we pick a new candidate
                candidate = num;
            }

            // If current number equals candidate, increment count
            // Otherwise, decrement count
            count += (num == candidate) ? 1 : -1;
        }

        // Since the problem guarantees a majority element exists,
        // we can return the candidate directly.
        return candidate;
    }
};


