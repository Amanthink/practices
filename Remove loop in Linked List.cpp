class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        if (head == NULL || head->next == NULL) return; // No loop possible in 0 or 1 node.

        Node *slow = head, *fast = head;

        // Step 1: Detect loop using Floyd’s cycle detection
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) { // Cycle detected
                break;
            }
        }

        // If no cycle was found, return
        if (slow != fast) return;

        // Step 2: Find the starting node of the loop
        slow = head;
        if (slow == fast) { // Special case: If loop starts from the head itself
            while (fast->next != slow) { // Find the last node pointing to head
                fast = fast->next;
            }
        } else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        // Step 3: Break the cycle
        fast->next = NULL;
    }
};
