
class Solution {// TC: O(n)                                                   SC: O(1)
public:
    int maxDepth(string s) {

        // depth = current number of open '(' brackets
        int depth = 0;

        // ans = maximum depth we have seen so far
        int ans = 0;

        // Traverse every character of the string
        for(char ch : s)
        {
            // If we find an opening bracket,
            // we are entering one more level of nesting
            if(ch == '(')
            {
                depth++;

                // Update maximum depth
                ans = max(ans, depth);
            }

            // If we find a closing bracket,
            // we are leaving the current level of nesting
            else if(ch == ')')
            {
                depth--;
            }

            // Other characters like digits, '+', '-', '*'
            // are simply ignored
        }

        // Return the maximum nesting depth
        return ans;
    }
};

/*

┌────────────────────────────────────┐
│      MAX DEPTH OF PARENTHESES      │
├────────────────────────────────────┤
│ State:                             │
│ depth = current nesting level      │
│ ans   = maximum depth reached      │
│                                    │
│ '(' → depth++                      │
│       ans = max(ans, depth)        │
│                                    │
│ ')' → depth--                      │
│                                    │
│ Other chars → ignore               │
│                                    │
│ Key: Track OPEN brackets count     │
│      and store the maximum.        │
│                                    │
│ TC: O(n)                           │
│ SC: O(1)                           │
└────────────────────────────────────┘

*/
