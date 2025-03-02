/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        // Your code here
        vector<int> ans;
        Node *curr=head;
        while(curr!=NULL){
            ans.push_back(curr->data);
            curr=curr->next;
        }
        int n=ans.size();
        int slow=0,high=n-1;
        while(slow<=high){
            if(ans[slow]!=ans[high]){
                return false;
                break;
            }
            slow++;
            high--;
        }
        return true;
    }
};
