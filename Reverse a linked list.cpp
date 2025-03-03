
struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution {
  public:
    Node* reverseList(struct Node* head) {
        // code here
        if(head==NULL||head->next==NULL) return head;
        Node *curr=head;
        Node *prev=NULL;
        while(curr!=NULL){
            Node *temp=curr->next;//for storing the next elements 
            curr->next=prev; //changing the link
            prev=curr;//updating the prev to current;
            curr=temp; //updating the current to next variables
        }
        return prev;// returning the head or reverse list
    }
};
