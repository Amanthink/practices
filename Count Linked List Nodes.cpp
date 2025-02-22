class Solution {
  public:
    // Function to count nodes of a linked list.
    int getCount(struct Node* head) {

        // Code here
        if(head==NULL) return 0;
        int i=1;
        Node *curr= head;
        while(curr!=NULL){
            i++;
            curr=curr->next;
            
        }
        return i-1;
    }
};
