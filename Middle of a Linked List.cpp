/* Link list Node
struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}; */
class Solution {
  public:
    /* Should return data of middle node. If linked list is empty, then -1 */
    int getMiddle(Node* head) {
        // code here
        if(head==NULL||head->next==NULL) return head->data;
        Node *curr=head;
        int count=0;
        while(curr!=NULL){
            count++;
            curr=curr->next;
        }
        Node *temp=head;
            int p=(count/2)+1;
            while(p!=1){
                p--;
                temp=temp->next;
            }
            return temp->data;
    }
};
