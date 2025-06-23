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
       ListNode* reversed(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
         ListNode * slow=head;
         ListNode * fast=head;
         while(fast!=NULL&&fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;

         }
         slow=reversed(slow);
         fast=head;
         while(slow!=NULL){
            if(slow->val!=fast->val) return false;
            slow=slow->next;
            fast=fast->next;

         }
         return true;
    }
};
