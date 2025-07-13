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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> a;

        ListNode* curr = head;
        while (curr != nullptr) {
            a.push_back(curr->val);
            curr = curr->next;
        }

        int l = left - 1;
        int r = right - 1;
        while (l < r) {
            swap(a[l], a[r]);
            l++;
            r--;
        }

        ListNode* newHead = new ListNode(a[0]);
        ListNode* temp = newHead;
        for (int i = 1; i < a.size(); i++) {
            temp->next = new ListNode(a[i]);
            temp = temp->next;
        }

        return newHead;
    }
};
