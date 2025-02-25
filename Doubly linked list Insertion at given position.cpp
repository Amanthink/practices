/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

// Function to insert a new node at given position in doubly linked list.
class Solution {
  public:
    // Function to insert a new node at given position in doubly linked list.
    Node *addNode(Node *head, int pos, int data) {
        // code here
        Node*curr=head;
        Node *temp=new Node(data);
        int count =0;
        if(head==NULL) return temp;
        // Traverse to the `pos`-th node
        for (int i = 0; i < pos && curr->next != NULL; i++) {
            curr = curr->next;
        }
        
        Node *pp=curr->next;
        curr->next=temp;
        temp->prev=curr;
        temp->next=pp;
         if (pp) {
            pp->prev = temp;
        }
        return head;
    }
};
