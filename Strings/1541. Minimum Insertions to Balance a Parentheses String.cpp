
class Solution {// Time: O(n)                              Space: O(1) 
public:
    int minInsertions(string s) {
        int n = s.length();

        int count = 0;        // Number of unmatched '(' characters
        int insertions = 0;   // Total insertions required
        int i = 0;            // Pointer to traverse the string

        while (i < n) 
        {
            // Case 1: Current character is an opening parenthesis '('
            if (s[i] == '(') 
            {
                count++;  // This '(' needs two consecutive ')' characters
                i++;      // Move to the next character
            }
            else 
            {
                // Case 2: Current character is a closing parenthesis ')'
                // First, try to match this closing pair with an unmatched '('
                if (count > 0) 
                {
                    count--;  // One '(' is now matched
                }
                else 
                {
                    // No unmatched '(' exists.
                    // Insert one '(' before the closing pair '))'.
                    insertions++;
                }
                // Every '(' must be matched with TWO consecutive ')' characters.
                // Check whether the next character is also ')'.
                if (i + 1 < n && s[i + 1] == ')') 
                {
                    // We found the pair '))'.
                    // Both closing parentheses have been processed together.
                    i += 2;
                }
                else 
                {
                    // Only one ')' exists, so insert the missing second ')'.
                    insertions++;

                    // Move past the current ')'.
                    i++;
                }
            }
        }

        // Any unmatched '(' still needs two ')' characters.
        return insertions + (2 * count);
    }
};

/*

┌─────────────────────────────────────┐
│  MINIMUM INSERTIONS (LEETCODE 1541) │
├─────────────────────────────────────┤
│                                     │
│ count = unmatched '('               │
│ insertions = required insertions    │
│                                     │
│ '(' :                               │
│   count++                           │
│   i++                               │
│                                     │
│ ')' :                               │
│   if count > 0 → count--            │
│   else → insertions++  // Add '('   │
│                                     │
│   If next char is ')' :             │
│      i += 2  // Consume '))'        │
│   Else :                            │
│      insertions++  // Add ')'       │
│      i++                            │
│                                     │
│ Remaining '(' need 2 ')' each       │
│                                     │
│ FINAL: insertions + (2 * count)     │
│                                     │
│ KEY TRICK:                          │
│ Match '(' → Check '))' → Fix gaps   │
│                                     │
│ Time  : O(n)                        │
│ Space : O(1) auxiliary              │
└─────────────────────────────────────┘

*/
