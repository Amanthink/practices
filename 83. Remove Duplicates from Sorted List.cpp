class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        while (curr != nullptr && curr->next != nullptr) {
            if (curr->val == curr->next->val) {
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;  // Correct memory deallocation in C++
            } else {
                curr = curr->next;
            }
        }
        return head; // Return the start of the modified list
    }
};
