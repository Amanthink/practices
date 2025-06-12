class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        vector<int> ans;
        int sum = 0;
        ListNode* curr = head->next;

        while (curr != NULL) {
            if (curr->val != 0) {
                sum += curr->val;
            } else {
                ans.push_back(sum);
                sum = 0;
            }
            curr = curr->next;
        }

        
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        for (int val : ans) {
            tail->next = new ListNode(val);
            tail = tail->next;
        }

        return dummy->next;
    }
};
