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
    ListNode* sortList(ListNode* head) {
        int i=1;
        if(head==NULL||head->next==NULL) return head;
        ListNode*curr=head;
        vector<int> reo;

        while(curr!=NULL){
            i++;
            reo.push_back(curr->val);
            curr=curr->next;
            
        }
        sort(reo.begin(),reo.end());
        int p=0;
        ListNode*c=head;
        while(c!=NULL&&p<i){
            c->val=reo[p++];
            c=c->next;
        }
        return head;
    }
};
