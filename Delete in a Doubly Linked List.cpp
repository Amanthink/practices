/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        if (head==NUll) return NULL;

        Node *curr = head;
        int count = 1;

        while (count != x && curr != NULL) {
            curr = curr->next;
            count++;
        }

        if (curr==NULL) return head;

        Node *temp = curr;

        if (curr == head) {
            head = head->next;
            if (head) head->prev = NULL;
        }
        else {
            curr->prev->next = curr->next;
            if (curr->next) {
                curr->next->prev = curr->prev;
            }
        }

        delete temp;
        return head;
    }
};
