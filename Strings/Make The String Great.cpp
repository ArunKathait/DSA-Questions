class Solution {//TC--->O(N)        SC--->O(N)
public:
    string makeGood(string s) {
        // Create a stack to store characters
        stack<char>st;
        
        // Iterate through each character of the string
        for(int i=0;i<s.length();i++)
        {
            // If stack is not empty and the top of the stack is equal to current character with a case difference of 32
            // ASCII difference between lowercase and uppercase letters is 32
            if(!st.empty() && abs(st.top() - s[i]) == 32)
            {
                 // Pop the character from the stack as it's considered "bad"
                st.pop();
            }
            else
            {
                // Otherwise, push the character onto the stack
                st.push(s[i]);
            }
        }
        
        // Create a string to store the answer
        string ans;
        
        // Pop characters from the stack and append to the answer string
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        
         // Reverse the answer string as characters were pushed in reverse order
        reverse(ans.begin(),ans.end());
    
        // Return the final "good" string
        return ans;
    }
};
