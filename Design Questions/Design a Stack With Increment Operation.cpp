
class CustomStack {// TC--->O(1)                     SC--->O(N)
public:
    // Stack to store elements
    vector<int>stack;
    
    // Increment values to be applied later
    vector<int>increments;
    
    // Maximum size of the stack
    int n;
    
    // Constructor to initialize the stack with a given maximum size
    CustomStack(int maxSize) {
        // Assign maxSize to 'n' (maximum size of the stack)
        n = maxSize;
    }
    
    // Method to push an element into the stack
    void push(int x) {
        // Only push if the current size of the stack is less than the maximum size
        if(stack.size() < n)
        {
            // Add the new element to the stack
            stack.push_back(x);
            
            // Initially, no increment for the newly pushed element
            increments.push_back(0);
        }
    }
    
    // Method to pop the top element from the stack
    int pop() {
        // If the stack is empty, return -1
        if(stack.size() == 0)
        {
            return -1;
        }
        
        // Get the index of the top element
        int index = stack.size() - 1;
        
        // If there are more than one element, propagate the increment to the previous element
        if(index > 0)
        {
            // Add current increment to the previous one
            increments[index - 1] += increments[index];
        }
        
        // The value to return is the top element plus its associated increment
        int topValue = stack[index] + increments[index];
        
        // Remove the top element and its increment
        stack.pop_back();
        increments.pop_back();
        
        // Return the popped value (after applying the increment)
        return topValue;
    }
    
    // Method to increment the bottom 'k' elements by a value 'val'
    void increment(int k, int val) {
        // Find the index of the k-th element or the last element (whichever is smaller)
        int index = min(k,(int)stack.size()) - 1;
        
        // If the index is valid, apply the increment
        if(index >= 0)
        {
            // Add the increment value to the k-th element
            increments[index] += val;
        }
    }
};

