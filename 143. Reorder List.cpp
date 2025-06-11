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

#include <vector>
#include <algorithm> // for reverse

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) return;

        
        std::vector<ListNode*> nodes;
        ListNode* curr = head;
        while (curr != NULL) {
            nodes.push_back(curr);
            curr = curr->next;
        }

       
        int i = 0;
        int j = nodes.size() - 1;

        while (i < j) {
            nodes[i]->next = nodes[j];
            i++;
            if (i == j) break;
            nodes[j]->next = nodes[i];
            j--;
        }

        nodes[i]->next = NULL; 
    }
};

