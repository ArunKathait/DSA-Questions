********************************************APPROACH 1st(MEMOIZATION)***********************************************

class Solution {// TC → O(N² × K)                              SC → O(N × K)
public:

    // Modulo value to prevent the answer from becoming too large.
    int M = 1e9 + 7;

    // dp[k][i] stores the answer for:
    //
    // k = number of sets/pairs still needed
    // i = current point/index we are considering
    //
    // -1 means this state has not been calculated yet.
    int dp[1001][1001];


    int solve(int n, int k, int i)
    {
        // --------------------------------------------------
        // BASE CASE 1:
        // We have successfully created all k sets.
        //
        // If k == 0, there is exactly 1 valid way
        // to complete the remaining process:
        // simply stop.
        // --------------------------------------------------
        if (k == 0)
        {
            return 1;
        }


        // --------------------------------------------------
        // BASE CASE 2:
        // We have reached the end of the n points,
        // but still need to create some sets.
        //
        // Therefore, it is impossible.
        // --------------------------------------------------
        if (i >= n)
        {
            return 0;
        }


        // --------------------------------------------------
        // MEMOIZATION:
        //
        // If we have already calculated the answer
        // for this (k, i) state, return it directly.
        //
        // This prevents solving the same state repeatedly.
        // --------------------------------------------------
        if (dp[k][i] != -1)
        {
            return dp[k][i];
        }


        // --------------------------------------------------
        // TAKE:
        //
        // We decide to use point 'i' as the starting point
        // of the current set/pair.
        //
        // The second point can be any point after i:
        //
        // j = i + 1 ... n - 1
        //
        // For every possible j, we create one set/pair
        // and then recursively create the remaining k - 1 sets.
        // --------------------------------------------------
        long long take = 0;

        for (int j = i + 1; j < n; j++)
        {
            // Choose i and j as the current pair/set.
            //
            // We have created one set,
            // so remaining sets = k - 1.
            //
            // j becomes the current position for the next choice.
            take = (take + solve(n, k - 1, j)) % M;
        }


        // --------------------------------------------------
        // NOT TAKE:
        //
        // We decide NOT to use point 'i' as the starting
        // point of a set.
        //
        // Move to the next point i + 1 and still need
        // to create k sets.
        // --------------------------------------------------
        long long notTake = solve(n, k, i + 1) % M;


        // --------------------------------------------------
        // TOTAL ANSWER:
        //
        // There are two possibilities:
        //
        // 1. TAKE point i
        // 2. DON'T TAKE point i
        //
        // Add both possibilities.
        //
        // Store the result in dp for future use.
        // --------------------------------------------------
        return dp[k][i] = (take + notTake) % M;
    }


    int numberOfSets(int n, int k)
    {
        // Initialize the entire DP table with -1.
        //
        // This means no state has been calculated yet.
        memset(dp, -1, sizeof(dp));

        // Start from:
        //
        // i = 0 → first point
        // k = k → need to create k sets
        //
        // Return the answer modulo M.
        return solve(n, k, 0) % M;
    }
};

/*

🧠 The main idea

At every point i, you have two choices:

                    point i
                       |
              ┌────────┴────────┐
              ↓                 ↓
            TAKE             NOT TAKE
              |                 |
       choose j > i          skip i
              |                 |
        k becomes k-1       i becomes i+1

╔════════════════════════════════════════════╗
║          RECURSION + MEMOIZATION           ║
╠════════════════════════════════════════════╣
║ State: dp[k][i]                            ║
║ → k = sets still needed                    ║
║ → i = current point                        ║
║                                            ║
║ Base:                                      ║
║ k == 0 → 1                                 ║
║ i >= n  → 0                                ║
║                                            ║
║ At point i:                                ║
║                                            ║
║ TAKE:                                      ║
║ choose every j > i                         ║
║ solve(n, k-1, j)                           ║
║                                            ║
║ NOT TAKE:                                  ║
║ solve(n, k, i+1)                           ║
║                                            ║
║ Answer = TAKE + NOT TAKE                   ║
║                                            ║
║ TC → O(N² × K)                             ║
║ SC → O(N × K)                              ║
╚════════════════════════════════════════════╝

*/

***********************************************APPROACH 2nd(TABULATION)********************************************

class Solution {// Time: O(N × K)                       Space: O(N × K)
public:

    // dp[k][i] =
    // Number of ways to create k more line segments
    // using points from index i onwards.
    //
    // k  -> number of segments still required
    // i  -> current point/index we are considering
    int dp[1001][1001];

    int M = 1e9 + 7;

    int numberOfSets(int n, int K) {

        // ---------------------------------------------------------
        // BASE CASE:
        //
        // dp[0][i] = 1
        //
        // If we need to create 0 more segments,
        // there is exactly 1 valid way:
        // choose nothing and finish successfully.
        //
        // This is the tabulation equivalent of:
        // if(k == 0) return 1;
        // ---------------------------------------------------------
        for(int i = 0; i < n; i++)
        {
            dp[0][i] = 1;
        }


        // ---------------------------------------------------------
        // Now calculate answers for:
        // k = 1, 2, 3, ... K
        //
        // Since dp[k][i] depends on dp[k-1][...],
        // we calculate smaller k first.
        // ---------------------------------------------------------
        for(int k = 1; k <= K; k++)
        {

            // -----------------------------------------------------
            // prevRowSum[x] stores:
            //
            // dp[k-1][x] + dp[k-1][x+1] + ... + dp[k-1][n-1]
            //
            // In other words, it stores the suffix sum of
            // the previous DP row.
            //
            // Why do we need this?
            //
            // In the recursive solution, we had:
            //
            // take = solve(n, k-1, i+1)
            //      + solve(n, k-1, i+2)
            //      + ...
            //
            // Instead of looping over all j every time,
            // we calculate this sum once using suffix sums.
            // -----------------------------------------------------
            vector<int> prevRowSum(n + 1, 0);


            // -----------------------------------------------------
            // Build suffix sum from right to left.
            //
            // Example:
            //
            // prevRowSum[x]
            // = dp[k-1][x] + prevRowSum[x+1]
            //
            // We use x = n-1 ... 0.
            // -----------------------------------------------------
            for(int x = n - 1; x >= 0; x--)
            {
                prevRowSum[x] = (prevRowSum[x + 1] + dp[k - 1][x]) % M;
            }


            // -----------------------------------------------------
            // Now calculate dp[k][i].
            //
            // We go from right to left because:
            //
            // dp[k][i] depends on dp[k][i+1]
            //
            // So dp[k][i+1] must already be calculated.
            // -----------------------------------------------------
            for(int i = n - 1; i >= 0; i--)
            {

                // -------------------------------------------------
                // TAKE:
                //
                // We use point i as the starting point of a segment.
                //
                // The other endpoint can be:
                //
                // i+1, i+2, ..., n-1
                //
                // Therefore we need:
                //
                // dp[k-1][i+1]
                // + dp[k-1][i+2]
                // + ...
                // + dp[k-1][n-1]
                //
                // prevRowSum[i+1] already contains exactly this sum.
                // -------------------------------------------------
                int take = prevRowSum[i + 1];


                // -------------------------------------------------
                // NOT TAKE:
                //
                // We don't use point i.
                //
                // So we simply move to the next point:
                //
                // dp[k][i+1]
                //
                // This is the tabulation equivalent of:
                //
                // solve(n, k, i+1)
                // -------------------------------------------------
                int notTake = dp[k][i + 1]%M;


                // -------------------------------------------------
                // TOTAL:
                //
                // ways = TAKE + NOT TAKE
                //
                // Take current point i
                // OR
                // Skip current point i
                // -------------------------------------------------
                dp[k][i] = (take + notTake) % M;
            }
        }


        // ---------------------------------------------------------
        // We need K segments and can start considering points
        // from index 0.
        //
        // Therefore the final answer is:
        //
        // dp[K][0]
        // ---------------------------------------------------------
        return dp[K][0];
    }
};

/*

╔════════════════════════════════════════════╗
║             TABULATION + DP                ║
╠════════════════════════════════════════════╣
║ State: dp[k][i]                            ║
║ → k = sets still needed                    ║
║ → i = current point                        ║
║                                            ║
║ Base:                                      ║
║ dp[0][i] = 1                               ║
║ → 0 sets needed → 1 valid way              ║
║                                            ║
║ Suffix Sum:                                ║
║ prevRowSum[i]                              ║
║ → sum of dp[k-1][i ... n-1]                ║
║                                            ║
║ TAKE:                                      ║
║ choose j > i                               ║
║ → prevRowSum[i+1]                          ║
║                                            ║
║ NOT TAKE:                                  ║
║ skip point i                               ║
║ → dp[k][i+1]                               ║
║                                            ║
║ Transition:                                ║
║ dp[k][i] = TAKE + NOT TAKE                 ║
║                                            ║
║ Order:                                     ║
║ k → 1 to K                                 ║
║ i → n-1 to 0                               ║
║                                            ║
║ Key Optimization:                          ║
║ Suffix Sum removes inner j loop            ║
║                                            ║
║ TC → O(N × K)                              ║
║ SC → O(N × K)                              ║
╚════════════════════════════════════════════╝

*/
