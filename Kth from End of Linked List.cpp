/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

// Function to find the data of kth node from the end of a linked list.
class Solution {
  public:
    int getKthFromLast(Node *head, int k) {
        // Your code here
        Node *curr=head;
        
        int i=0;
        while(curr!=NULL){
            i++;
            curr=curr->next;
        }
        if(i<k) return -1;
        else{
            Node *te=head;
            for(int p=1;p<i-k+1;p++) te=te->next;
            return te->data;
        }
    }
};
