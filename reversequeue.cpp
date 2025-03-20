class Solution {
  public:
    std::queue<int> reverseQueue(std::queue<int> &q) {
        std::stack<int> s;
        
        // Step 1: Push all elements of queue into stack
        while (!q.empty()) {
            s.push(q.front());
            q.pop();
        }
        
        // Step 2: Push elements back to queue from stack
        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }
        
        return q; // Return the reversed queue
    }
};
