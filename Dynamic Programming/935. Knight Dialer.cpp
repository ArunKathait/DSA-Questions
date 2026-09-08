************************************************APPROACH 1st(MEMOIZATION)*********************************************

class Solution {// Time  : O(n × 10 × 3) ~ O(n)                Space : O(n × 10) ~ O(n)
public:
    // Modulo value given in the problem.
    // We take modulo to prevent integer overflow
    // because the number of possible phone numbers
    // can become extremely large.
    int M = 1e9 + 7;


    // dp[n][cell] means:
    //
    // Number of valid ways to make 'n' MORE moves
    // when we are currently standing on digit 'cell'.
    //
    // n can be up to 5000
    // cell can be from 0 to 9
    //
    // -1 means this state has not been calculated yet.
    int dp[5001][10];


    // Recursive DP function.
    //
    // n     = number of moves/digits still remaining
    // cell  = current digit
    // adj   = possible knight moves from each digit
    int solve(int n, int cell, vector<vector<int>>& adj)
    {

        // Base case:
        //
        // If there are no moves left, we have formed
        // one valid number.
        //
        // Example:
        // solve(0, 4) = 1
        //
        // There is exactly one way when nothing
        // remains to be chosen.
        if(n == 0)
        {
            return 1;
        }


        // If this state has already been calculated,
        // return the stored answer.
        //
        // This is MEMOIZATION.
        //
        // It prevents us from solving the same
        // state again and again.
        if(dp[n][cell] != -1)
        {
            return dp[n][cell];
        }


        // Stores the total number of valid ways
        // from the current digit.
        int res = 0;


        // Try every digit that can be reached from
        // the current digit using a knight move.
        //
        // Example:
        // If cell = 1:
        //
        // adj[1] = {6,8}
        //
        // So we can move:
        //
        // 1 → 6
        // 1 → 8
        for(auto &nextCell : adj[cell])
        {
            // We made one knight move,
            // so the remaining number of moves
            // becomes n - 1.
            //
            // Add the number of ways possible
            // from nextCell.
            res = (res + solve(n - 1, nextCell, adj)) % M;
        }


        // Store the result so that if we encounter
        // the same state again, we can directly
        // return it.
        //
        // This is the memoization step.
        return dp[n][cell] = res;
    }


    int knightDialer(int n)
    {

        // Adjacency list representing all possible
        // knight moves on the phone keypad.
        //
        // Index = current digit
        // Values = digits reachable using one
        //           knight move
        //
        // 0 → 4, 6
        // 1 → 6, 8
        // 2 → 7, 9
        // 3 → 4, 8
        // 4 → 3, 9, 0
        // 5 → nothing
        // 6 → 1, 7, 0
        // 7 → 2, 6
        // 8 → 1, 3
        // 9 → 2, 4
        vector<vector<int>> adj{
            {4,6},
            {6,8},
            {7,9},
            {4,8},
            {3,9,0},
            {},
            {1,7,0},
            {2,6},
            {1,3},
            {2,4}
        };


        // Initialize the entire DP array with -1.
        //
        // -1 means:
        // "This state has not been calculated yet."
        memset(dp, -1, sizeof(dp));


        // Stores the total number of valid phone numbers.
        int ans = 0;


        // We can start the phone number from ANY
        // digit from 0 to 9.
        for(int cell = 0; cell <= 9; cell++)
        {
            // The first digit is already selected.
            //
            // Therefore, we need to make only
            // n - 1 additional moves.
            //
            // Example:
            // n = 3
            //
            // Start:
            //     1
            //
            // Then we need 2 more digits.
            //
            // solve(2, 1)
            ans = (ans + solve(n - 1, cell, adj)) % M;
        }


        // Return total number of valid phone numbers.
        return ans;
    }
};

/*

┌──────────────────────────────────────────────────┐
│              KNIGHT DIALER — LC 935              │
├──────────────────────────────────────────────────┤
│ Pattern: DP + Graph + Memoization                │
│                                                  │
│ STATE                                            │
│ dp[n][cell] = ways to make n more moves          │
│               from digit 'cell'                  │
│                                                  │
│ BASE CASE                                        │
│ n == 0  →  return 1                              │
│                                                  │
│ TRANSITIONS                                      │
│ 0 → 4,6      1 → 6,8      2 → 7,9                │
│ 3 → 4,8      4 → 3,9,0    5 → —                  │
│ 6 → 1,7,0    7 → 2,6      8 → 1,3                │
│ 9 → 2,4                                          │
│                                                  │
│ RECURSION                                        │
│ solve(n, cell)                                   │
│      ↓                                           │
│ for every nextCell in adj[cell]                  │
│      ↓                                           │
│ solve(n-1, nextCell)                             │
│                                                  │
│ MEMOIZATION                                      │
│ If dp[n][cell] != -1 → return stored answer      │
│                                                  │
│ FINAL ANSWER                                     │
│ Try every starting digit 0 → 9                   │
│ ans += solve(n-1, cell)                          │
│                                                  │
│ WHY n-1?                                         │
│ First digit is already selected.                 │
│ Remaining digits = n - 1 moves.                  │
│                                                  │
│ TIME  : O(n)                                     │
│ SPACE : O(n)                                     │
│                                                  │
│ INTERVIEW LINE                                   │
│ "Memoize each (remaining moves, digit) state     │
│  and explore only its valid knight transitions." │
└──────────────────────────────────────────────────┘

*/

********************************************APPROACH 2nd(TABULATION)************************************************

class Solution {// Time  : O(n)                                 Space : O(n)
public:

    // Modulo value given in the problem.
    // The number of possible phone numbers can become
    // extremely large, so we take modulo 1e9 + 7.
    int M = 1e9 + 7;


    int knightDialer(int n) {

        // Adjacency list representing all possible
        // knight moves on the phone keypad.
        //
        // adj[cell] contains all digits that can be
        // reached from 'cell' using one knight move.
        //
        // 0 → 4, 6
        // 1 → 6, 8
        // 2 → 7, 9
        // 3 → 4, 8
        // 4 → 3, 9, 0
        // 5 → nothing
        // 6 → 1, 7, 0
        // 7 → 2, 6
        // 8 → 1, 3
        // 9 → 2, 4
        vector<vector<int>> adj{
            {4,6},
            {6,8},
            {7,9},
            {4,8},
            {3,9,0},
            {},
            {1,7,0},
            {2,6},
            {1,3},
            {2,4}
        };


        // dp[i][cell] means:
        //
        // Number of ways to make exactly 'i' moves
        // starting from the digit 'cell'.
        //
        // Example:
        //
        // dp[1][1]
        //
        // means:
        // Number of ways to make 1 move starting from 1.
        //
        // From 1 we can go to 6 or 8,
        // so dp[1][1] = 2.
        //
        // Size:
        // n+1 rows → moves from 0 to n
        // 10 columns → digits 0 to 9
        vector<vector<int>> dp(n + 1, vector<int>(10, 0));


        // BASE CASE
        //
        // If we have 0 moves remaining,
        // there is exactly ONE way to form the number:
        //
        // simply stay at the current digit.
        //
        // Therefore:
        // dp[0][0] = 1
        // dp[0][1] = 1
        // ...
        // dp[0][9] = 1
        for(int cell = 0; cell <= 9; cell++)
        {
            dp[0][cell] = 1;
        }


        // Build the DP table from bottom to top.
        //
        // We need n digits in total.
        // The first digit is already selected,
        // so we only need to make n-1 moves.
        //
        // Therefore, we calculate:
        //
        // i = 1 → n-1
        for(int i = 1; i <= n - 1; i++)
        {

            // Try every possible current digit.
            for(int cell = 0; cell < 10; cell++)
            {

                // Stores the number of ways to reach
                // the required length from this digit.
                int res = 0;


                // Try every digit that can be reached
                // from the current digit using a
                // knight move.
                //
                // Example:
                //
                // cell = 1
                // adj[1] = {6,8}
                //
                // Therefore:
                //
                // dp[i][1]
                //   = dp[i-1][6] + dp[i-1][8]
                for(auto &nextCell : adj[cell])
                {
                    // We make one move from 'cell'
                    // to 'nextCell'.
                    //
                    // Therefore, we look at the number
                    // of ways to make the remaining
                    // i-1 moves from nextCell.
                    res = (res + dp[i - 1][nextCell]) % M;
                }


                // Store the total number of ways
                // for this state.
                dp[i][cell] = res;
            }
        }


        // We can start the phone number from ANY
        // digit from 0 to 9.
        //
        // dp[n-1][cell] gives the number of ways
        // to make the remaining n-1 moves when
        // starting from 'cell'.
        int ans = 0;


        // Add the number of ways from all
        // possible starting digits.
        for(int cell = 0; cell <= 9; cell++)
        {
            ans = (ans + dp[n - 1][cell]) % M;
        }


        // Return the total number of valid
        // phone numbers of length n.
        return ans;
    }
};

/* 

┌──────────────────────────────────────────────────┐
│          KNIGHT DIALER — LC 935                  │
│          TABULATION / BOTTOM-UP DP               │
├──────────────────────────────────────────────────┤
│ Pattern: DP + Graph                              │
│                                                  │
│ STATE                                            │
│ dp[i][cell] = ways to make i moves starting      │
│               from digit 'cell'                  │
│                                                  │
│ BASE CASE                                        │
│ dp[0][cell] = 1                                  │
│                                                  │
│ TRANSITION                                       │
│ dp[i][cell] = Σ dp[i-1][nextCell]                │
│                                                  │
│ Example:                                         │
│ 1 → 6,8                                          │
│ dp[1][1] = dp[0][6] + dp[0][8]                   │
│           = 1 + 1 = 2                            │
│                                                  │
│ MOVES                                            │
│ Calculate i = 1 → n-1                            │
│ Why n-1?                                         │
│ First digit is already selected.                 │
│                                                  │
│ STARTING DIGITS                                  │
│ Try every digit 0 → 9                            │
│ ans += dp[n-1][cell]                             │
│                                                  │
│ KNIGHT MOVES                                     │
│ 0 → 4,6      1 → 6,8      2 → 7,9                │
│ 3 → 4,8      4 → 3,9,0    5 → —                  │
│ 6 → 1,7,0    7 → 2,6      8 → 1,3                │
│ 9 → 2,4                                          │
│                                                  │
│ TIME                                             │
│ O(n × 10 × 3) = O(n)                             │
│                                                  │
│ SPACE                                            │
│ O(n × 10) = O(n)                                 │
│                                                  │
│ INTERVIEW LINE                                   │
│ "I use bottom-up DP where each state represents  │
│  the number of ways to make i moves from a       │
│  particular digit, using the previous row to     │
│  calculate the current row."                     │
└──────────────────────────────────────────────────┘

*/
