****************************************************APPROACH 1st(BETTER APPROACH)*****************************************

// TC ---> O(1)                       SC ---> O(2 * N)
// This class implements a stack that supports the following operations in O(1) time:
// 1. push(x) – Push an element onto the stack
// 2. pop() – Remove the top element
// 3. top() – Get the top element
// 4. getMin() – Retrieve the minimum element in the stack at any point
class MinStack {
public:
    // We use a stack of pairs.
    // Each element in the stack is stored as {value, current_minimum}
    stack<pair<int,int>> st;

    // Constructor – initializes an empty stack
    MinStack() { }

    // Pushes a new value 'val' onto the stack
    void push(int val) {
        if(st.empty()) 
        {
            // If the stack is empty, the current element is also the minimum
            st.push({val, val});
        } 
        else 
        {
            // Get the minimum value so far (from the top of the stack)
            // Compare it with the new value to find the new current minimum
            int currentMin = min(val, st.top().second);

            // Push both the value and the updated minimum as a pair
            st.push({val, currentMin});
        }
    }

    // Removes the top element from the stack
    void pop() {
        // Simply pop the top element (both value and its associated min)
        st.pop();
    }

    // Returns the top element's value (without removing it)
    int top() {
        // The actual value is stored in the 'first' part of the pair
        return st.top().first;
    }

    // Retrieves the minimum element in the stack at this moment
    int getMin() {
        // The current minimum is always stored in the 'second' part of the top pair
        return st.top().second;
    }
};

*************************************************APPROACH 2nd(OPTIMAL APPROACH)****************************************

