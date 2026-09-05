************************************************APPROACH 1st(USING RECURSION)***************************************

class Solution {// TC ---> O(2^(n+amount))                                        SC ---> O(amount)
public:

    // Recursive function to find minimum coins needed
    // index  -> current coin index we are considering
    // n      -> total number of coins
    // coins  -> list of coin denominations
    // amount -> remaining amount to be formed
    int solve(int index, int n, vector<int>& coins, int amount)
    {
        // ✅ Base Case 1:
        // If amount becomes 0, we have successfully formed the amount
        // No more coins are needed
        if (amount == 0)
        {
            return 0;
        }

        // ❌ Base Case 2 (Invalid cases):
        // 1) index >= n  → no coins left to use
        // 2) amount < 0  → amount exceeded (invalid path)
        // Return a very large number (INF) to mark this path as impossible
        if (index >= n || amount < 0)
        {
            return 1e9;
        }

        // 🔹 Choice 1: TAKE the current coin
        // - We stay on the same index (unbounded coins allowed)
        // - Reduce the amount by coins[index]
        // - Add 1 because we used one coin
        int take = 1 + solve(index, n, coins, amount - coins[index]);

        // 🔹 Choice 2: DO NOT TAKE the current coin
        // - Move to the next coin (index + 1)
        // - Amount remains the same
        int notTake = solve(index + 1, n, coins, amount);

        // 🔹 Return the minimum coins required between the two choices
        return min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        // Total number of coins
        int n = coins.size();

        // Call recursive function starting from index 0
        int ans = solve(0, n, coins, amount);

        // If answer is very large, it means forming amount is impossible
        // Return -1 as per problem statement
        return ans >= 1e9 ? -1 : ans;
    }
};

**************************************************APPROACH 2nd(USING MEMOIZATION)*************************************

class Solution {// TC ---> O(n × amount)                                    SC ---> O(n × amount)
public:

    // Recursive function with memoization
    // index  -> current coin index
    // n      -> total number of coins
    // coins  -> coin denominations
    // amount -> remaining amount to be formed
    // dp     -> memoization table
    int solve(int index, int n, vector<int>& coins, int amount, vector<vector<int>>& dp)
    {
        // ✅ Base Case 1:
        // If amount becomes 0, we have successfully formed the target
        // No more coins are needed
        if (amount == 0)
        {
            return 0;
        }

        // ❌ Base Case 2 (Invalid cases):
        // 1) index >= n  → no coins left to use
        // 2) amount < 0  → amount exceeded (invalid path)
        // Return a very large value (INF) to mark this path as impossible
        if (index >= n || amount < 0)
        {
            return 1e9;
        }

        // 🔁 Memoization check:
        // If this state (index, amount) is already computed,
        // return the stored answer to avoid recomputation
        if (dp[index][amount] != -1)
        {
            return dp[index][amount];
        }

        // 🔹 Choice 1: TAKE the current coin
        // - Add 1 because we use one coin
        // - index remains same (unlimited supply of coins allowed)
        // - amount is reduced by coins[index]
        int take = 1 + solve(index, n, coins, amount - coins[index], dp);

        // 🔹 Choice 2: DO NOT TAKE the current coin
        // - Move to next coin (index + 1)
        // - amount remains unchanged
        int notTake = solve(index + 1, n, coins, amount, dp);

        // 🧠 Store the minimum of both choices in dp table
        // dp[index][amount] represents:
        // minimum coins needed to form 'amount' using coins from index to n-1
        return dp[index][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        // Total number of coins
        int n = coins.size();

        // Create DP table
        // dp[index][amount] = minimum coins needed to form 'amount'
        // using coins starting from 'index'
        // Initialized with -1 meaning "not calculated yet"
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));

        // Start recursion from index 0 and full amount
        int ans = solve(0, n, coins, amount, dp);

        // If answer is INF, it means forming the amount is impossible
        // Return -1 as per problem statement
        return ans >= 1e9 ? -1 : ans;
    }
};

/*

┌─────────────────────────────────────────┐
│          COIN CHANGE — DP               │
├─────────────────────────────────────────┤
│ Approach : Top-Down DP / Memoization    │
│                                         │
│ State : dp[index][amount]               │
│                                         │
│ TAKE:                                   │
│   1 + solve(index, amount - coin)       │
│   → Same index (coin can repeat)        │
│                                         │
│ NOT TAKE:                               │
│   solve(index + 1, amount)              │
│   → Move to next coin                   │
│                                         │
│ Base Cases:                             │
│   amount == 0 → 0                       │
│   index >= n / amount < 0 → INF         │
│                                         │
│ Answer = min(TAKE, NOT TAKE)            │
│                                         │
│ Time  : O(n × amount)                   │
│ Space : O(n × amount)                   │
│                                         │
│ KEY: TAKE → same index                  │
│      NOT TAKE → index + 1               │
└─────────────────────────────────────────┘

*/

*************************************************APPROACH 3rd(USING TABULATION)**************************************

class Solution {// TC ---> O(n × amount)                                           SC ---> O(amount)
public:
    int coinChange(vector<int>& coins, int amount) {

        // Number of different coin denominations
        int n = coins.size();

        // dp[i] will store the minimum number of coins
        // required to make amount = i
        // Initialize all values with a very large number (INF)
        vector<int> dp(amount + 1, 1e9);

        // Base case:
        // To make amount = 0, we need 0 coins
        dp[0] = 0;

        // Build the dp array from amount = 1 to amount
        for (int i = 1; i <= amount; i++)
        {
            // Try every coin denomination
            for (auto coin : coins)
            {
                // Check if current coin can be used
                // (amount should not become negative)
                if (i - coin >= 0)
                {
                    // If we use this coin:
                    // 1 coin is used + dp[i - coin] coins needed for remaining amount
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }

        // If dp[amount] is still INF, it means amount cannot be formed
        // Return -1 as per problem statement
        return dp[amount] >= 1e9 ? -1 : dp[amount];
    }
};

/*

┌─────────────────────────────────────────┐
│       COIN CHANGE — TABULATION          │
├─────────────────────────────────────────┤
│ Approach : Bottom-Up 1D DP              │
│                                         │
│ State:                                  │
│ dp[i] = minimum coins to make i         │
│                                         │
│ Base:                                   │
│ dp[0] = 0                               │
│                                         │
│ Transition:                             │
│ dp[i] = min(dp[i], dp[i-coin] + 1)      │
│                                         │
│ Loop:                                   │
│ i = 1 → amount                          │
│ Try every coin                          │
│                                         │
│ If impossible → -1                      │
│                                         │
│ Time  : O(n × amount)                   │
│ Space : O(amount)                       │
│                                         │
│ KEY:                                    │
│ "Current amount = smaller amount        │
│  + 1 coin"                              │
└─────────────────────────────────────────┘

*/
