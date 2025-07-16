class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> vals;
        while (head) {
            vals.push_back(head->val);
            head = head->next;
        }

        vector<int> result(vals.size(), 0);
        stack<int> st; // store indices

        for (int i = 0; i < vals.size(); ++i) {
            while (!st.empty() && vals[i] > vals[st.top()]) {
                result[st.top()] = vals[i];
                st.pop();
            }
            st.push(i);
        }

        return result;
    }
};
