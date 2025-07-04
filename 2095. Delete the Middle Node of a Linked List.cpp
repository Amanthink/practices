class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) return nullptr; 
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* slow = dummy;
        ListNode* fast = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* temp = slow->next;
        slow->next = temp->next;
        delete temp;

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
