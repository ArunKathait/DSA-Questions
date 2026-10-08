********************************************APPROACH 1st****************************************************************

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

*******************************************APPROACH 2nd(OPTIMAL)*****************************************************

class Solution {// Time Complexity: O(n)                           Space Complexity: O(1)
public:
    bool validateStackSequences(vector<int>& pushed,vector<int>& popped) {

        // 'i' represents the current size of our simulated stack.
        //
        // Instead of creating a separate stack<int>,
        // we reuse the 'pushed' array itself as the stack.
        //
        // Example:
        // pushed = [1,2,3,4,5]
        //
        // If i = 3:
        // [1,2,3] → these are currently inside our stack.
        int i = 0;

        // 'k' points to the next element that we need
        // to pop according to the 'popped' sequence.
        //
        // Example:
        // popped = [4,5,3,2,1]
        // k = 0 → we need to pop 4 first.
        int k = 0;


        // Traverse all elements that need to be pushed.
        for(auto &num : pushed)
        {
            // Put the current element at position 'i'.
            //
            // This is equivalent to:
            // stack.push(num)
            //
            // We are using the pushed array as our stack.
            pushed[i] = num;

            // Increase the size of our simulated stack.
            i++;


            // Check whether we can pop the top element.
            //
            // i > 0:
            //    means the simulated stack is not empty.
            //
            // pushed[i - 1]:
            //    represents the TOP of our simulated stack.
            //
            // popped[k]:
            //    is the next element that we are required to pop.
            //
            // If they match, we can perform the pop.
            while(i > 0 && pushed[i - 1] == popped[k])
            {
                // Decrease the size of our simulated stack.
                //
                // This is equivalent to:
                // stack.pop()
                i--;

                // Move to the next element in popped.
                k++;
            }
        }


        // If i == 0, our simulated stack is empty.
        //
        // That means every pushed element was successfully
        // popped in the required order.
        //
        // Therefore, the sequence is valid.
        return i == 0;
    }
};

/*

┌─────────────────────────────────────┐
│   VALIDATE STACK SEQUENCES          │
│          IN-PLACE APPROACH          │
├─────────────────────────────────────┤
│                                     │
│ i = simulated stack size            │
│ k = popped[] index                  │
│                                     │
│ PUSH:                               │
│ pushed[i] = num                     │
│ i++                                 │
│                                     │
│ TOP:                                │
│ pushed[i - 1]                       │
│                                     │
│ POP:                                │
│ i--                                 │
│ k++                                 │
│                                     │
│ CHECK:                              │
│ while(i > 0 &&                      │
│       pushed[i-1] == popped[k])     │
│ {                                   │
│     i--;                            │
│     k++;                            │
│ }                                   │
│                                     │
│ FINAL:                              │
│ i == 0 → valid → true               │
│                                     │
│ KEY IDEA:                           │
│ PUSH → CHECK TOP → POP              │
│                                     │
│ Time  : O(n)                        │
│ Space : O(1) extra                  │
└─────────────────────────────────────┘

*/
