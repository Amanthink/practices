//User function Template for C++

/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};

*/
class Solution{
    public:
    bool isCircular(Node * head)
    {
       //Your code here
       Node *curr=head;
       while(curr!=NULL){
           if(curr->next==head&&head->prev==curr) return true;
           curr=curr->next;
       }
       return false;
    }
};
