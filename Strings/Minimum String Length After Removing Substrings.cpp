*************************************************APPROACH 1st(USING STACK)************************************************

class Solution {// TC--->O(N)                        SC--->O(N)
public:
    // Function to calculate the minimum length of the string after removing pairs "AB" and "CD"
    int minLength(string s) {
        // Create a stack to simulate the removal of pairs
        stack<char>st;
        
        // Loop through each character in the input string 's'
        for(auto &x:s)
        {
            // Check if the stack is not empty and the top element forms a valid pair with the current character
            if(!st.empty() && ((st.top() == 'A' && x == 'B') || (st.top() == 'C' && x == 'D')))
            {
                // If a valid pair (either "AB" or "CD") is found, remove (pop) the top element from the stack
                st.pop();
            }
            else
            {
                // If no valid pair is found, push the current character onto the stack
                st.push(x);
            }
        }
        
        // The size of the stack at the end will represent the remaining characters after all possible pairs have been removed
        return st.size();
        
    }
};

****************************************************APPROACH 2nd********************************************************

class Solution {// TC--->O(N)                      SC--->O(1)
public:
     // Function to calculate the minimum length of the string after removing pairs "AB" and "CD"
    int minLength(string s) {
         // Get the length of the input string 's'
        int n = s.length();
        
        // 'i' is used to track the position in the reduced string
        int i = 0;
        
        // 'j' is used to traverse through the string
        int j = 1;
        
        // The loop continues as long as 'j' is within the bounds of the string
        while(j < n)
        {
            // If 'i' becomes negative, reset it to 0 and start filling from the next character
            if(i < 0)
            {
                // Increment 'i' to 0
                i++;
                
                // Place the current character from 'j' into 's[i]'
                s[i] = s[j];
            }
            // Check if the characters at 'i' and 'j' form one of the valid pairs ("AB" or "CD")
            else if((s[j] == 'B' && s[i] == 'A') || (s[j] == 'D' && s[i] == 'C'))
            {
                // Remove the pair by decrementing 'i', effectively "popping" the last character
                i--;
            }
            else
            {
                // If no pair is found, move forward by placing 's[j]' into 's[i + 1]'
                i++;                    // Move to the next position in the reduced string
                s[i] = s[j];            // Place the current character from 'j' into 's[i]'
            }
            
            // Move to the next character in the input string
            j++;
        }
        
        // Return the length of the remaining string, which is 'i + 1'
        // 'i' represents the last index of the valid string, so we return 'i + 1' for the length
        return i + 1;
    }
};
