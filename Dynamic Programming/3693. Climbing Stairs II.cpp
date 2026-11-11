**********************************************APPROACH 1st(MEMOIZATION)**********************************************

class Solution {// TC ---> O(N)                                    SC ---> O(N)
public:
    int solve(int index, int n, vector<int>& costs, vector<int>& dp)
    {
        // BASE CASE:
        // If we reach the destination (index == n),
        // no additional cost is required.
        if(index == n)
        {
            return 0;
        }

        // MEMOIZATION:
        // If the answer for the current index is already calculated,
        // return the stored result instead of solving it again.
        if(dp[index] != -1)
        {
            return dp[index];
        }

        // Initially, assume the minimum cost is infinity.
        int cost = INT_MAX;

        // OPTION 1: Jump 1 step
        int j = index + 1;

        // Check whether jumping 1 step is within the destination.
        if(j <= n)
        {
            // Total cost =
            // Minimum cost from the next position to destination
            // + Cost of landing on position j
            // + Square of the jump distance.
            cost = solve(j, n, costs, dp) + costs[j - 1] 
                   + (j - index) * (j - index);
        }

        // OPTION 2: Jump 2 steps
        j = index + 2;

        // Check whether jumping 2 steps is within the destination.
        if(j <= n)
        {
            // Calculate the total cost of taking a 2-step jump.
            // Update cost if this option gives a smaller cost.
            cost = min(cost, solve(j, n, costs, dp) 
                       + costs[j - 1] 
                       + (j - index) * (j - index));
        }

        // OPTION 3: Jump 3 steps
        j = index + 3;

        // Check whether jumping 3 steps is within the destination.
        if(j <= n)
        {
            // Calculate the total cost of taking a 3-step jump.
            // Select the minimum cost among all three jump options.
            cost = min(cost, solve(j, n, costs, dp) 
                       + costs[j - 1] 
                       + (j - index) * (j - index));
        }

        // Store the minimum cost for the current index in dp.
        // This avoids recalculating the same state in future calls.
        return dp[index] = cost;
    }

    int climbStairs(int n, vector<int>& costs) {

        // DP array initialized with -1.
        // -1 means the answer for that index has not been calculated.
        vector<int> dp(n + 1, -1);

        // Start from index 0 and calculate the minimum cost
        // required to reach the destination n.
        return solve(0, n, costs, dp);
    }
};

/*

┌──────────────────────────────────────────────────────┐
│       MINIMUM COST TO REACH DESTINATION              │
├──────────────────────────────────────────────────────┤
│ APPROACH: Recursion + Memoization (Top-Down DP)      │
│                                                      │
│ KEY IDEA:                                            │
│ • Start from index 0.                                │
│ • Try jumps of 1, 2 and 3 steps.                     │
│ • Calculate landing cost + squared jump distance.    │
│ • Choose the minimum cost among all choices.         │
│ • Store results in dp[index] to avoid recomputation. │
│                                                      │
│ BASE CASE:                                           │
│ • index == n → Return 0.                             │
│                                                      │
│ DP STATE:                                            │
│ • dp[index] = Minimum cost to reach n from index.    │
│                                                      │
│ TIME COMPLEXITY:  O(n)                               │
│ SPACE COMPLEXITY: O(n)                               │
│ TOTAL SPACE:      O(n)                               │
│ (DP Array + Recursion Stack)                         │
└──────────────────────────────────────────────────────┘

*/

***********************************************APPROACH 2nd(TABULATION)***********************************************

class Solution {// TIME COMPLEXITY:  O(n)                             SPACE COMPLEXITY: O(n)
public:
    int climbStairs(int n, vector<int>& costs) {

        // DP array of size n + 1.
        // dp[i] represents the minimum cost required
        // to reach the destination (index n) from index i.
        vector<int> dp(n + 1);

        // Start from the last position and move backwards.
        // We calculate the answer for every index from n-1 to 0.
        for(int i = n - 1; i >= 0; i--)
        {
            // Initially, consider the next position (1-step jump).
            int j = i + 1;

            // Initially, assume the minimum cost is infinity.
            int cost = INT_MAX;

            // OPTION 1: Jump 1 step.
            // Check whether the next position is within the destination.
            if(j <= n)
            {
                // Total cost =
                // Minimum cost from position j to destination
                // + Cost of landing on position j
                // + Square of the jump distance.
                cost = dp[j] + costs[j - 1] + (j - i) * (j - i);
            }

            // OPTION 2: Jump 2 steps.
            j = i + 2;

            // Check whether jumping 2 steps is valid.
            if(j <= n)
            {
                // Calculate the total cost of a 2-step jump.
                // Update cost if this option gives a smaller result.
                cost = min(cost, dp[j] + costs[j - 1]
                           + (j - i) * (j - i));
            }

            // OPTION 3: Jump 3 steps.
            j = i + 3;

            // Check whether jumping 3 steps is valid.
            if(j <= n)
            {
                // Calculate the total cost of a 3-step jump.
                // Select the minimum among all three jump options.
                cost = min(cost, dp[j] + costs[j - 1]
                           + (j - i) * (j - i));
            }

            // Store the minimum cost required to reach
            // the destination from the current index i.
            dp[i] = cost;
        }

        // Return the minimum cost required to reach n from index 0.
        return dp[0];
    }
};

/*

┌──────────────────────────────────────────────────────┐
│       MINIMUM COST TO REACH DESTINATION              │
├──────────────────────────────────────────────────────┤
│ APPROACH: Bottom-Up DP (Tabulation)                  │
│                                                      │
│ KEY IDEA:                                            │
│ • Create a DP array of size n + 1.                   │
│ • dp[i] stores minimum cost to reach n from index i. │
│ • Initialize dp[n] = 0 (destination reached).        │
│ • Traverse backwards from index n-1 to 0.            │
│ • Try all possible jumps: 1, 2 and 3 steps.          │
│ • Calculate landing cost + squared jump distance.    │
│ • Store the minimum cost in dp[i].                   │
│ • Return dp[0] as the final answer.                  │
│                                                      │
│ TIME COMPLEXITY:  O(n)                               │
│ SPACE COMPLEXITY: O(n)                               │
│ TOTAL SPACE:      O(n) (DP Array)                    │
└──────────────────────────────────────────────────────┘

*/
