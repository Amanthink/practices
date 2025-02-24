/*
struct Node
{
    int data;
    Node * next;
    Node (int x)
    {
        data=x;
        next=NULL;
    }
        
};

*/
Node* joinTheLists(Node *head1, Node *head2)
{
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1; 

    Node *curr = head1;

    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = head2;

    return head1; 
}
