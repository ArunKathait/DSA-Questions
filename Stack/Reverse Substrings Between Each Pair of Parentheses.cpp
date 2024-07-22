***************************************************************APPROACH 1st(BRUTE FORCE)****************************************************************************

class Solution {// TC--->O(N^2)                 SC--->O(N)
public:
    string reverseParentheses(string s) {
         // This will hold the final result after processing the string
        string ans;
        
        // This stack will store the positions of '(' to help with reversing
        stack<int>skipLength;
        
        // Iterate through each character in the input string 's'
        for(auto x:s)
        {
            // If the character is '(', push the current length of 'ans' onto the stack
            if(x == '(')
            {
                skipLength.push(ans.length());
            }
            // If the character is ')', it indicates the end of a segment to reverse
            else if(x == ')')
            {
                // Get the position of the corresponding '(' from the stack
                int l = skipLength.top();
                
                // Remove the position from the stack as it's no longer needed
                skipLength.pop();

                // Reverse the segment of 'ans' from the position 'l' to the end
                reverse(ans.begin() + l ,ans.end());
            }
            else
            {
                // If the character is not a parenthesis, simply add it to 'ans'
                ans += x;
            }
        }
        // Return the final processed string
        return ans;
    }
};

******************************************************************APPROACH 2nd(LINEAR APPROACH)*****************************************************************

class Solution {// TC--->O(N)                  SC--->O(N)
public:
    string reverseParentheses(string s) {
        // Get the length of the input string
        int n = s.length();
        
        // Stack to store the indices of open parentheses
        stack<int>openBracketIndex;
        
        // Vector to store the corresponding indices of matching parentheses
        vector<int>door(n);
        
        // First pass: Identify and store the indices of matching parentheses
        for(int i=0;i<n;i++)
        {
            if(s[i] =='(')
            {
                // Push the index of '(' onto the stack
                openBracketIndex.push(i);
            }
            else if(s[i] == ')')
            {
                // Get the index of the last unmatched '('
                int j = openBracketIndex.top();
                
                // Remove the index from the stack
                openBracketIndex.pop();
                
                // Store the index of ')' corresponding to this '('
                door[j] = i;
                
                // Store the index of '(' corresponding to this ')'
                door[i] = j;
            }
        }
        
         // This will hold the final result after processing the string
        string ans;
        
        // This flag determines the direction of traversal (forward or backward)
        int flag = 1;
      
        for(int i=0;i<n;i += flag)
        {
            // If the character is a parenthesis
            if(s[i] == '(' || s[i] == ')')
            {
                // Jump to the matching parenthesis
                i = door[i];
                
                // Reverse the direction of traversal
                flag = -flag;
            }
            else
            {
                // Add the character to the result
                ans += s[i];
            }
        }
        
        // Return the final processed string
        return ans;
    }
};
