
/*class Node {
public:
    int data;
    Node* next;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};*/

class Solution {
  public:
    Node* constructLL(vector<int>& arr) {
        if (arr.empty()) return NULL; 
        
        
        Node* head = new Node(arr[0]);
        Node* tail = head;

        for (int i = 1; i < arr.size(); i++) {
            tail->next = new Node(arr[i]); 
            tail = tail->next; 
        }

        return head;
    }
};
