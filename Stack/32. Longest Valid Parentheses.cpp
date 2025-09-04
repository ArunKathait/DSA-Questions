***************************************************APPROACH 1st(STACK)************************************************

class Solution {// TC ---> O(N)                                 SC ---> O(N)
public:
    int longestValidParentheses(string s) {
        // length of input string
        int n = s.length();   
        
        // to store maximum valid parentheses length
        int maxLength = 0; 

        // stack to store indices of characters   
        stack<int> st;        

        // base index (acts as a boundary for valid substrings)
        st.push(-1);          

        // -------- Traverse the string --------
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')   
            {
                // If it's '(', push its index onto the stack
                st.push(i);
            }
            else  
            {
                // If it's ')', try to match with a '('
                st.pop();

                if(!st.empty())
                {
                    // If stack is not empty after popping:
                    // length of current valid substring = i - st.top()
                    maxLength = max(maxLength, i - st.top());
                }
                else
                {
                    // If stack becomes empty:
                    // Push current index as the new base boundary
                    st.push(i);
                }
            }
        }

        // return the maximum valid length found
        return maxLength;  
    }
};


***************************************************APPROACH 2nd(OPTIMAL)**********************************************

class Solution {// TC ---> O(n) + O(n) = O(n)                             SC--->O(1)
public:
    int longestValidParentheses(string s) {
        int n = s.length();  // store the length of the input string

        int leftBracket = 0;   // counter for '('
        int rightBracket = 0;  // counter for ')'

        int maxLength = 0;     // variable to keep track of the longest valid substring length

        // -------- First Pass (Left to Right) --------
        for(int i=0;i<n;i++)
        {
            if(s[i] == '(')   // if current char is '('
            {
                leftBracket++;
            }
            else              // if current char is ')'
            {
                rightBracket++;
            }

            // when both counts are equal → valid parentheses found
            if(leftBracket == rightBracket)
            {
                // total valid length = 2 * (number of pairs)
                maxLength = max(maxLength, 2 * leftBracket);      
            }

            // if ')' are more than '(' → reset counters (invalid state)
            if(leftBracket < rightBracket)
            {
                leftBracket = 0;
                rightBracket = 0;
            }
        }

        // -------- Second Pass (Right to Left) --------
        // why? → to handle cases like "(()" which wouldn't be caught by left-to-right pass

        leftBracket = 0;
        rightBracket = 0;

        // traverse from rightmost to leftmost
        for(int i=n-1;i>=0;i--)   
        {
            if(s[i] == '(')
            {
                leftBracket++;
            }
            else
            {
                rightBracket++;
            }

            // when both counts are equal → valid substring found
            if(leftBracket == rightBracket)
            {
                maxLength = max(maxLength, 2 * leftBracket);
            }

            // if '(' are more than ')' → reset counters (invalid state when moving right-to-left)
            if(leftBracket > rightBracket)
            {
                leftBracket = 0;
                rightBracket = 0;
            }
        }

        // return the maximum valid length found
        return maxLength;  
    }
};
