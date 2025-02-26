/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

class Solution {
  public:
    // Function to remove duplicates from sorted linked list.
    Node* removeDuplicates(Node* head) {
        if (head == NULL) return NULL; // Edge case: Empty list
        
        Node *curr = head;
        while (curr != NULL && curr->next != NULL) {
            if (curr->data == curr->next->data) {
                Node *temp = curr->next;
                curr->next = temp->next; 
                delete temp; 
            } else {
                curr = curr->next; 
            }
        }
        return head;
    }
};
