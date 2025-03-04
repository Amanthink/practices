/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        Node *slow = head, *fast = head;
        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) { 
                int length = 1;
                Node* temp = slow;

                
                while (temp->next != slow) {
                    length++;
                    temp = temp->next;
                }
                return length; 
            }
        }
        
        return 0;  
        }
    };
