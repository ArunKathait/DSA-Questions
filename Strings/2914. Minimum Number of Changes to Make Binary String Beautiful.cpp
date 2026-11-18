
class Solution {// Time Complexity:  O(n)                      Space Complexity: O(1)
public:
    int minChanges(string s) {
        // Get the length of the string.
        int n = s.length();

        // Stores the minimum number of character changes required.
        int changes = 0;

        // Traverse the string in pairs of two characters.
        // i increases by 2 because we process two characters at a time.
        for(int i = 0; i < n; i += 2)
        {
            // Compare the two characters in the current pair.
            if(s[i] != s[i + 1])
            {
                // If they are different, change one character
                // to make both characters equal.
                changes++;
            }
        }

        // Return the total number of changes required.
        return changes;
    }
};

/*

┌──────────────────────────────────────────────┐
│ Problem: Minimum Changes                     │
├──────────────────────────────────────────────┤
│ • Approach: Greedy                           │
│                                              │
│ • Key Idea:                                  │
│   Traverse the string in pairs of 2.         │
│   If both characters are different,          │
│   change one character to make them equal.   │
│   Count the mismatched pairs.                │
│                                              │
│ • Pattern: Greedy + Pairwise Comparison      │
├──────────────────────────────────────────────┤
│ • Time Complexity:  O(n)                     │
│ • Space Complexity: O(1)                     │
└──────────────────────────────────────────────┘

*/
