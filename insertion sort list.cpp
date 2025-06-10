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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode(0);  // Dummy node for sorted list
        ListNode* curr = head;

        while (curr) {
            ListNode* prev = dummy;         // Start from beginning of sorted list
            ListNode* nextNode = curr->next;

            // Find the correct place to insert current node
            while (prev->next && prev->next->val < curr->val) {
                prev = prev->next;
            }

            // Insert current between prev and prev->next
            curr->next = prev->next;
            prev->next = curr;

            // Move to next node
            curr = nextNode;
        }

        return dummy->next;
    }
};
