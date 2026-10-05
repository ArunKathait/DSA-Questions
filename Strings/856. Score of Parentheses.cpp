**********************************************APPROACH 1st********************************************************

class Solution {// Time: O(n)                                   Space: O(n)
public:
    int scoreOfParentheses(string s) {

        // Store the length of the string.
        int n = s.length();

        // vec acts like a stack.
        // It stores the score of the previous/outer level.
        vector<int> vec;

        // score stores the score of the current level.
        int score = 0;

        for(int i = 0; i < n; i++)
        {
            // If we see '(',
            // we are starting a new nested level.
            if(s[i] == '(')
            {
                // Save the score of the outer level
                // before starting the new level.
                vec.push_back(score);

                // Start calculating the score
                // for the new inner level.
                score = 0;
            }
            // If we see ')',
            // the current parentheses level is complete.
            else if(s[i] == ')')
            {
                // Case 1: We have "()"
                // Example: "()" has score = 1.
                //
                // If the previous character is '(',
                // there is nothing inside the parentheses.
                if(s[i - 1] == '(')
                {
                    // Add 1 to the score of the outer level.
                    //
                    // vec.back() = score before entering '('
                    // + 1       = score of "()"
                    score = vec.back() + 1;
                }
                // Case 2: We have "(A)"
                // Example: "(())"
                //
                // The inner expression already has some score.
                else
                {
                    // According to the rule:
                    // (A) = 2 * A
                    //
                    // vec.back() = score of the outer level
                    // score      = score inside current brackets
                    score = vec.back() + (2 * score);
                }

                // We have finished this level,
                // so remove the saved outer-level score.
                vec.pop_back();
            }
        }

        // After processing the complete string,
        // score contains the final answer.
        return score;
    }
};

/*

┌──────────────────────────────────────┐
│  SCORE OF PARENTHESES — LC 856       │
├──────────────────────────────────────┤
│ RULES:                               │
│ ()     → 1                           │
│ (A)    → 2 × A                       │
│ AB     → A + B                       │
│                                      │
│ VARIABLES:                           │
│ score → current level's score        │
│ vec   → saves outer level's score    │
│                                      │
│ '(' → push current score             │
│       score = 0                      │
│                                      │
│ ')' → if previous is '('             │
│          score = vec.back() + 1      │
│       else                           │
│          score = vec.back() + 2*score│
│       pop outer score                │
│                                      │
│ KEY:                                 │
│ vec = outer score                    │
│ score = inner/current score          │
│                                      │
│ TC: O(n)                             │
│ SC: O(n)                             │
└──────────────────────────────────────┘

*/

**********************************************APPROACH 2nd(OPTIMAL)***********************************************

class Solution {// Time: O(n)                                   Space: O(1)
public:
    int scoreOfParentheses(string s) {

        // Length of the string.
        int n = s.length();

        // depth tells us how deeply nested we currently are.
        //
        // Example:
        // "("       -> depth = 1
        // "(("      -> depth = 2
        // "((("     -> depth = 3
        int depth = 0;

        // Stores the final score.
        int score = 0;

        for(int i = 0; i < n; i++)
        {
            // Opening bracket means we are entering
            // one more level of nesting.
            if(s[i] == '(')
            {
                depth++;
            }
            // Closing bracket means we are leaving
            // the current level.
            else if(s[i] == ')')
            {
                depth--;

                // Check if this is a primitive "()".
                //
                // If the previous character is '(',
                // then we have found an empty pair "()".
                //
                // Example:
                // "()"
                // "(()())" -> both inner "()" pairs
                if(s[i - 1] == '(')
                {
                    // A primitive "()" at depth d
                    // contributes 2^d.
                    //
                    // (1 << depth) means:
                    // 1 shifted left by 'depth' positions
                    //
                    // 1 << 0 = 1
                    // 1 << 1 = 2
                    // 1 << 2 = 4
                    // 1 << 3 = 8
                    score += (1 << depth);
                }
            }
        }

        // Return the total score.
        return score;
    }
};

/*

┌──────────────────────────────────────┐
│ SCORE OF PARENTHESES — O(1) SPACE    │
├──────────────────────────────────────┤
│ IDEA:                                │
│ Every primitive "()" contributes     │
│ 2^depth                              │
│                                      │
│ DEPTH:                               │
│ '(' → depth++                        │
│ ')' → depth--                        │
│                                      │
│ WHEN s[i-1] == '(':                  │
│ Found "()" → score += 2^depth        │
│                                      │
│ BIT TRICK:                           │
│ 1 << depth = 2^depth                 │
│                                      │
│ EXAMPLES:                            │
│ ()       → 1                         │
│ (())     → 2                         │
│ ((()))   → 4                         │
│                                      │
│ TC: O(n)                             │
│ SC: O(1)                             │
│                                      │
│ KEY: Find every "()" and add         │
│      its value based on depth.       │
└──────────────────────────────────────┘

*/
