class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        if (!head1) return head2;
        if (!head2) return head1;

        Node* dummy = new Node(-1);  
        Node* curr = dummy;

        while (head1 != NULL && head2 != NULL) {
            if (head1->data <= head2->data) {  
                curr->next = head1; 
                head1 = head1->next;
            } else {
                curr->next = head2;
                head2 = head2->next;
            }
            curr = curr->next;
        }

        
        if (head1) curr->next = head1;
        if (head2) curr->next = head2;

        return dummy->next; 
    }
};
