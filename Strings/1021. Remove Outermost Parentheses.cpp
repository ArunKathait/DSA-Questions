
class Solution {// Time  → O(n)                                  Space → O(n) 
public:
    string removeOuterParentheses(string s) {

        // Stores the final answer after removing
        // the outermost parentheses of every primitive.
        string ans;

        // count represents the current depth/balance.
        //
        // '(' → count++
        // ')' → count--
        int count = 0;


        // Process every character of the string.
        for(auto &x : s)
        {

            // If current character is an opening parenthesis
            if(x == '(')
            {
                // If count > 0, we are already inside
                // another pair of parentheses.
                //
                // Therefore, this '(' is NOT outermost,
                // so we keep it.
                if(count > 0)
                {
                    ans += x;
                }

                // Increase the depth after processing '('.
                count++;
            }


            // Current character is a closing parenthesis ')'
            else
            {
                // Decrease the depth first.
                count--;

                // If count > 0, we are still inside
                // another pair of parentheses.
                //
                // Therefore, this ')' is NOT outermost,
                // so we keep it.
                if(count > 0)
                {
                    ans += x;
                }

                // If count == 0, this was the outermost ')',
                // so we don't add it to the answer.
            }
        }

        // Return the string without outermost parentheses.
        return ans;
    }
};

/*

┌─────────────────────────────────────┐
│       REMOVE OUTER PARENTHESES      │
├─────────────────────────────────────┤
│                                     │
│ count = current depth               │
│                                     │
│ '(' :                               │
│   if count > 0 → KEEP '('           │
│   count++                           │
│                                     │
│ ')' :                               │
│   count--                           │
│   if count > 0 → KEEP ')'           │
│                                     │
│ Outermost '(' → skipped             │
│ Outermost ')' → skipped             │
│                                     │
│ KEY TRICK:                          │
│ '(' → CHECK → count++               │
│ ')' → count-- → CHECK               │
│                                     │
│ Time  : O(n)                        │
│ Space : O(n) output                 │
│ Extra : O(1)                        │
└─────────────────────────────────────┘

*/
