
class Solution {// Time: O(n)                              Space: O(n)
public:

    bool validateStackSequences(vector<int>& pushed,vector<int>& popped) {

        // Number of elements that need to be pushed.
        int n = pushed.size();

        // Create an empty stack.
        //
        // We will simulate the actual push and pop
        // operations using this stack.
        stack<int> st;

        // k points to the next element that we need
        // to remove according to the popped array.
        //
        // Example:
        // popped = [4, 5, 3, 2, 1]
        // k = 0 → we currently need to pop 4.
        int k = 0;


        // Process every element in the pushed array.
        for(int i = 0; i < n; i++)
        {
            // First, push the current element into the stack.
            st.push(pushed[i]);

            // Now check whether we can perform a pop.
            //
            // Two conditions:
            //
            // 1. Stack should not be empty.
            // 2. Top of stack should match the next
            //    required element in popped[].
            //
            // If both are true, we can legally pop it.
            while(!st.empty() && st.top() == popped[k])
            {
                // Remove the top element from the stack.
                st.pop();

                // Move to the next element that needs
                // to be popped.
                k++;
            }
        }


        // If the stack is empty, every element was
        // successfully popped in the required order.
        //
        // Therefore, the sequence is valid.
        //
        // If elements are still present, we could not
        // achieve the required popped sequence.
        return st.empty();
    }
};

/*

┌──────────────────────────────────────┐
│      VALIDATE STACK SEQUENCES        │
├──────────────────────────────────────┤
│ Approach: Simulate Stack             │
│                                      │
│ 1. Push pushed[i]                    │
│                                      │
│ 2. While:                            │
│    stack.top() == popped[k]          │
│       ↓                              │
│    pop()                             │
│    k++                               │
│                                      │
│ 3. At the end:                       │
│    stack.empty() → true              │
│    otherwise       → false           │
│                                      │
│ Key idea:                            │
│ PUSH → CHECK TOP → POP               │
│                                      │
│ Time  : O(n)                         │
│ Space : O(n)                         │
└──────────────────────────────────────┘

*/
