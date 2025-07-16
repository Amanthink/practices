/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        int sum=-1;
        vector<int> test;
        ListNode* curr= head;
        while(curr!=NULL){
            test.push_back(curr->val);
            curr=curr->next;
        }
        int n=test.size();
        int left=0,right=n-left-1;
        while(left<=n/2){
            sum=max(sum,test[left]+test[right]);
            left++;
            right--;
        }
        return sum;
    }
};
