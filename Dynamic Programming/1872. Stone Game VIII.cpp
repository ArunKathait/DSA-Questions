*************************************************APPROACH 1st(MEMOIZATION)******************************************

class Solution {// TC ---> O(N)                              SC ---> O(N)
public:

    // Recursively find the maximum score difference from index
    int solve(int index, int n, vector<int>& prefixSum, vector<int>& dp)
    {
        // If only the last prefix is left, return its value
        if(index == n - 1)
        {
            return prefixSum[n - 1];
        }

        // If this state is already calculated, return it
        if(dp[index] != -1)
        {
            return dp[index];
        }

        // Take the current prefix sum and subtract opponent's best result
        int take = prefixSum[index] - solve(index + 1, n, prefixSum, dp);

        // Skip the current prefix and move to the next index
        int skip = solve(index + 1, n, prefixSum, dp);

        // Store and return the better of take and skip
        return dp[index] = max(take, skip);
    }

    int stoneGameVIII(vector<int>& stones)
    {
        // Number of stones
        int n = stones.size();

        // Create prefix sum array
        vector<int> prefixSum(n, 0);

        // First prefix sum is the first stone
        prefixSum[0] = stones[0];

        // Calculate remaining prefix sums
        for(int i = 1; i < n; i++)
        {
            // Current prefix = previous prefix + current stone
            prefixSum[i] = stones[i] + prefixSum[i - 1];
        }

        // dp[index] stores the best score difference from this index
        vector<int> dp(n + 1, -1);

        // Start from index 1 because at least 2 stones must be taken
        return solve(1, n, prefixSum, dp);
    }
};

*************************************************APPROACH 2nd(TABULATION)******************************************

class Solution {// Time  : O(n)                           Space : O(n)
public:

    int stoneGameVIII(vector<int>& stones) {

        // Number of stones
        int n = stones.size();

        // prefixSum[i] = sum of stones from index 0 to i
        vector<int> prefixSum(n, 0);

        // Prefix sum for the first stone
        prefixSum[0] = stones[0];

        // Calculate all prefix sums
        for(int i = 1; i < n; i++)
        {
            // Add current stone to the previous prefix sum
            prefixSum[i] = stones[i] + prefixSum[i - 1];
        }

        // dp[i] = maximum score difference possible
        // starting from prefix index i
        vector<int> dp(n);

        // Base case:
        // At the last index, only the complete remaining
        // prefix sum can be taken
        dp[n - 1] = prefixSum[n - 1];

        // Calculate dp from right to left
        for(int i = n - 2; i >= 1; i--)
        {
            // Take prefixSum[i].
            // After taking it, the opponent gets the
            // best result represented by dp[i + 1]
            int take = prefixSum[i] - dp[i + 1];

            // Skip the current prefix and let the game
            // continue from the next index
            int skip = dp[i + 1];

            // Choose the option giving the maximum
            // score difference
            dp[i] = max(take, skip);
        }

        // dp[1] represents the best score difference
        // for the first player
        return dp[1];
    }
};

/* 

┌──────────────────────────────────────┐
│       STONE GAME VIII - DP           │
├──────────────────────────────────────┤
│                                      │
│ 1. Convert stones → prefix sums      │
│                                      │
│ 2. State: solve(index)               │
│    = best score difference from here │
│                                      │
│ 3. TAKE prefixSum[index]:            │
│                                      │
│    prefixSum[index]                  │
│           -                          │
│    opponent's best result            │
│                                      │
│ 4. SKIP current prefix               │
│    → solve(index + 1)                │
│                                      │
│ 5. Choose maximum                    │
│                                      │
│    dp[index] = max(take, skip)       │
│                                      │
│ Pattern:                             │
│ Prefix Sum + Game DP + Memoization   │
│                                      │
│ Time  : O(n)                         │
│ Space : O(n)                         │
└──────────────────────────────────────┘

*/
