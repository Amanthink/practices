class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> ans;
        ListNode* curr = head;

        // Store all node values
        while (curr != NULL) {
            ans.push_back(curr->val);
            curr = curr->next;
        }

        // Swap k-th node from beginning and end
        int n = ans.size();
        swap(ans[k - 1], ans[n - k]);

        // Reconstruct linked list from vector
        ListNode* newHead = new ListNode(ans[0]);
        ListNode* temp = newHead;

        for (int i = 1; i < n; i++) {
            temp->next = new ListNode(ans[i]);
            temp = temp->next;
        }

        return newHead;
    }
};
