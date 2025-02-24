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
    bool isSorted(Node * head)
{
    if (head == NULL || head->next == NULL) 
        return true; 

    bool increasing = true, decreasing = true;
    Node *curr = head;

    while (curr->next != NULL) {
        if (curr->data > curr->next->data) 
            increasing = false; 
        if (curr->data < curr->next->data) 
            decreasing = false; 
        curr = curr->next;
    }

    return increasing || decreasing; 
}
