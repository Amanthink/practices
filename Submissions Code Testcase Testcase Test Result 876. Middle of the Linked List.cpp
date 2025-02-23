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
    ListNode* middleNode(ListNode* head) {
        int i=0;
        ListNode *curr=head;
        while(curr!=NULL){
            i++;
            curr=curr->next;
        }
        int mid=i/2;
        ListNode *temp=head;
        for(int i=0;i<mid;i++){
            temp=temp->next;
        }
        return temp;
        
    }
};
