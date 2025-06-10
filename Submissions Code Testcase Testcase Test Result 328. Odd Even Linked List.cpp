class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return nullptr;              
        if (!head->next) return head;           

        vector<int> reo;

        ListNode* temp = head;
        while (temp && temp->next) {
            reo.push_back(temp->val);
            temp = temp->next->next;
        }
        if (temp) reo.push_back(temp->val);     
        temp = head->next;
        while (temp && temp->next) {
            reo.push_back(temp->val);
            temp = temp->next->next;
        }
        if (temp) reo.push_back(temp->val);     

        temp = head;
        int i = 0;
        while (temp != nullptr) {
            temp->val = reo[i++];
            temp = temp->next;
        }

        return head; 
    }
};
