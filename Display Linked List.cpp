



//User function Template for C++

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

vector<int> displayList(Node *head)
{
    //Your code here
    Node *curr=head;
    vector<int> ans;
    while(curr!=NULL){
        ans.push_back(curr->data);
        curr=curr->next;
    }
    return ans;
}
