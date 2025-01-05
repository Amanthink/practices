// the problem is time complexity of n2 using brute force;
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Your code here
         int count=0;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                if(arr[i]+arr[j]<target){
                    count++;
                }
            }
        }
        return count;
    }
};
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\    \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        
  int count = 0;  // Initialize count to 0
        sort(arr.begin(), arr.end());  // Sort the array
        
        int start = 0, end = arr.size() - 1;  // Initialize two pointers
        
        // Loop until the two pointers cross
        while (start < end) {
            int sum = arr[start] + arr[end];
            
            // If the sum is less than target, increment count
            if (sum < target) {
                count += (end - start);  // All pairs between start and end are valid
                start++;  // Move the start pointer to the right
            } else {
                end--;  // If sum >= target, move the end pointer to the left to reduce the sum
            }
        }
        
        return count;
    }
};
