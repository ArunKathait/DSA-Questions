*************************************************APPROACH 1st(MEMOIZATION)*******************************************

class Solution {// TIME COMPLEXITY:  O(n^2)                   SPACE COMPLEXITY: O(n)
public:
    int solve(int n, vector<int>& dp)
    {
        // BASE CASE:
        // If there are 0 or 1 nodes, only 1 unique BST is possible.
        // 0 nodes -> Empty tree
        // 1 node  -> Only one possible tree
        if(n <= 1)
        {
            return 1;
        }

        // If the answer is already calculated, return it.
        // This avoids recalculating the same subproblem.
        if(dp[n] != -1)
        {
            return dp[n];
        }

        // Stores the total number of unique BSTs possible
        // using n nodes.
        int ans = 0;

        // Try every node from 1 to n as the root node.
        for(int i = 1; i <= n; i++)
        {
            // If i is selected as the root:
            //
            // Left subtree  = i - 1 nodes
            // Right subtree = n - i nodes
            //
            // Number of BSTs with root i =
            // (Number of left subtree possibilities) *
            // (Number of right subtree possibilities)
            //
            // Multiply because every left subtree can be
            // combined with every right subtree.

            ans += solve(i - 1, dp) * solve(n - i, dp);
        }

        // Store the calculated answer in DP array
        // and return it.
        return dp[n] = ans;
    }

    int numTrees(int n) {

        // Initialize DP array with -1.
        // -1 means the subproblem has not been calculated yet.
        vector<int> dp(n + 1, -1);

        // Calculate the number of unique BSTs using n nodes.
        return solve(n, dp);
    }
};

/*

┌──────────────────────────────────────────────┐
│ Problem: Unique Binary Search Trees          │
├──────────────────────────────────────────────┤
│ • Approach: Top-Down DP (Memoization)        │
│ • Key Idea: Try every node as root.          │
│   Multiply left & right subtree possibilities│
│   and add results for all possible roots.    │
│ • Recurrence:                                │
│   dp[n] = Σ dp[i-1] × dp[n-i]                │
├──────────────────────────────────────────────┤
│ • Time Complexity:  O(n²)                    │
│ • Space Complexity: O(n)                     │
│ • Extra Space:      O(n)                     │
└──────────────────────────────────────────────┘

*/

*************************************************APPROACH 2nd(TABULATION)*********************************************

class Solution {// TIME COMPLEXITY:  O(n^2)                  SPACE COMPLEXITY: O(n)
public:
    int numTrees(int n) {

        // Create a DP array of size n + 1.
        // dp[i] stores the number of unique BSTs possible
        // using i nodes.
        vector<int>dp(n + 1, 0);

        // BASE CASE:
        // 0 nodes -> 1 possible BST (empty tree)
        // 1 node  -> 1 possible BST
        dp[0] = dp[1] = 1;

        // Calculate the number of unique BSTs
        // for every number of nodes from 2 to n.
        for(int i = 2; i <= n; i++)
        {
            // Try every node from 1 to i as the root.
            for(int j = 1; j <= i; j++)
            {
                // If j is selected as the root:
                //
                // Left subtree  = j - 1 nodes
                // Right subtree = i - j nodes
                //
                // Number of possible BSTs =
                // (Left subtree possibilities) *
                // (Right subtree possibilities)
                //
                // Multiply because every left subtree
                // can be combined with every right subtree.

                dp[i] += dp[j - 1] * dp[i - j];
            }
        }

        // Return the number of unique BSTs
        // that can be formed using n nodes.
        return dp[n];
    }
};

/*

┌──────────────────────────────────────────────┐
│ Problem: Unique Binary Search Trees          │
├──────────────────────────────────────────────┤
│ • Approach: Bottom-Up DP (Tabulation)        │
│ • Key Idea: Try every node as root.          │
│   Multiply left & right subtree possibilities│
│   and add results for all possible roots.    │
│ • Recurrence:                                │
│   dp[i] += dp[j-1] × dp[i-j]                 │
│ • Base Case: dp[0] = dp[1] = 1               │
├──────────────────────────────────────────────┤
│ • Time Complexity:  O(n²)                    │
│ • Space Complexity: O(n)                     │
│ • Extra Space:      O(n)                     │
└──────────────────────────────────────────────┘

*/

***************************************************APPROACH 3rd***************************************************

class Solution {
public:
    int numTrees(int n) {
        long long ans = 1;

        for(int i = 0; i < n; i++)
        {
            ans = ans * 2 * (2 * i + 1) / (i + 2);
        }

        return ans;
    }
};

/*

┌──────────────────────────────────────────────┐
│ Problem: Unique Binary Search Trees          │
├──────────────────────────────────────────────┤
│ • Approach: Catalan Number                   │
│ • Key Idea: Count unique BSTs using          │
│   the Catalan Number formula.                │
│ • Formula:                                   │
│   Cn = (2n)! / ((n+1)! × n!)                 │
│ • Optimized Recurrence:                      │
│   ans = ans × 2 × (2i+1) / (i+2)             │
├──────────────────────────────────────────────┤
│ • Time Complexity:  O(n)                     │
│ • Space Complexity: O(1)                     │
│ • Extra Space:      O(1)                     │
└──────────────────────────────────────────────┘

*/
