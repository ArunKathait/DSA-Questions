********************************************APPROACH 1st(USING STACK)****************************************************

class Solution {// TC--->O(N)                             SC--->O(N)
public:
    int minAddToMakeValid(string s) {
        // Initialize a stack to keep track of parentheses
        stack<char>st;
        
        // Iterate through each character in the input string
        for(auto &x:s)
        {
            // If the stack is not empty, and the top of the stack is '('
            // and the current character is ')', then we have a valid pair
            if(!st.empty() && st.top() == '(' && x == ')')
            {
                 // Pop the '(' from the stack, because this pair is valid
                st.pop();
            }
            else
            {
                // If there is no valid pair, push the current character to the stack
                st.push(x);
            }
        }
        
        // The size of the stack will represent the number of unmatched parentheses
        // This is because all valid pairs are removed from the stack
        // The remaining elements in the stack are the parentheses that need to be added to balance the string
        return st.size();
    }
};


************************************************APPROACH 2nd*********************************************************

class Solution {// TC--->O(N)                            SC--->O(1)
public:
    int minAddToMakeValid(string s) {
        // Tracks the number of unmatched ')' parentheses
        int open = 0;
        
        // Tracks the number of unmatched '(' parentheses
        int size = 0;
        
        // Iterate through each character in the input string
        for(auto &x:s)
        {
            if(x == '(')
            {
                // If we encounter an opening parenthesis, we increase the 'size'
                // because we have one more '(' that needs to be matched
                size++;
            }
            else if(size > 0)
            {
                // If we encounter a closing parenthesis ')' and there is already an unmatched '(',
                // we can match this pair, so we decrease the 'size' count
                size--;
            }
            else
            {
                // If we encounter a closing parenthesis ')' but there's no unmatched '(' to match it with,
                // we increase the 'open' count, as this ')' is unmatched
                open++;
            }
        }
        
        // 'size' now contains the number of unmatched '(' parentheses
        // 'open' contains the number of unmatched ')' parentheses
        // The total number of parentheses that need to be added to balance the string is the sum of these two values
        return size + open;
    }
};
