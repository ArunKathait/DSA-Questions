
class Solution {// TC ---> O(N)                                  SC ---> O(N)
public:
    int minimumDeletions(string s) {

        // This variable stores the minimum number of deletions required
        int count = 0;

        // Stack to keep track of characters processed so far
        stack<char> st;

        // Traverse each character in the string
        for (auto x : s) 
        {
            /*
             If:
             1. Stack is not empty
             2. Current character is 'a'
             3. Top of stack is 'b'

             Then we found a "ba" pattern.
             To make the string balanced (all 'a' before 'b'),
             we delete one character.

             Here, we choose to delete 'b' (pop from stack),
             and increment the deletion count.
            */
            if (!st.empty() && x == 'a' && st.top() == 'b') 
            {
                st.pop();   // Remove the 'b'
                count++;   // Count one deletion
            }
            else 
            {
                // Otherwise, keep the character by pushing it into the stack
                st.push(x);
            }
        }

        // Return total deletions required
        return count;
    }
};
