class Solution {
  public:
    // Function to find intersection point in Y-shaped Linked Lists.
    Node* intersectPoint(Node* head1, Node* head2) {
        if (!head1 || !head2) return NULL; // Edge case: if either list is empty

        // Step 1: Find the length of both lists
        int len1 = 0, len2 = 0;
        Node* temp1 = head1;
        Node* temp2 = head2;
        
        while (temp1) {
            len1++;
            temp1 = temp1->next;
        }
        while (temp2) {
            len2++;
            temp2 = temp2->next;
        }
        
        // Step 2: Move the pointer of the longer list ahead by |len1 - len2|
        int diff = abs(len1 - len2);
        temp1 = head1;
        temp2 = head2;
        
        if (len1 > len2) {
            while (diff--) temp1 = temp1->next;
        } else {
            while (diff--) temp2 = temp2->next;
        }

        // Step 3: Traverse both lists together until we find the intersection
        while (temp1 && temp2) {
            if (temp1 == temp2) return temp1; // Intersection found
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return NULL; // No intersection
    }
};
