******************************************************APPROACH 1st(MEMOIZATION)**************************************

class Solution {// TC ---> O(N)                                SC ---> O(N)
public:

    // This function returns the maximum score difference
    // (Current Player's Score - Opponent's Score)
    // starting from the given index.
    int solve(int index, int n, vector<int>& stoneValue, vector<int>& dp)
    {
        // Base case:
        // If there are no stones left to pick,
        // the score difference is 0.
        if(index >= n)
        {
            return 0;
        }

        // If this state has already been computed,
        // return the stored answer.
        if(dp[index] != -1)
        {
            return dp[index];
        }

        // -------------------------------------------------------
        // Choice 1: Take only 1 stone.
        //
        // Current player gains:
        // stoneValue[index]
        //
        // After taking this stone, the opponent starts from
        // index + 1.
        //
        // solve(index + 1) represents the opponent's maximum
        // score difference from that position.
        //
        // Therefore,
        // Current player's advantage =
        // Current gain - Opponent's advantage.
        // -------------------------------------------------------
        int ans = stoneValue[index] - solve(index + 1, n, stoneValue, dp);

        // -------------------------------------------------------
        // Choice 2: Take 2 stones (only if available).
        //
        // Gain =
        // stoneValue[index] + stoneValue[index + 1]
        //
        // Opponent starts from index + 2.
        // -------------------------------------------------------
        if(index + 1 < n)
        {
            ans = max(ans,
                      stoneValue[index]
                    + stoneValue[index + 1]
                    - solve(index + 2, n, stoneValue, dp));
        }

        // -------------------------------------------------------
        // Choice 3: Take 3 stones (only if available).
        //
        // Gain =
        // stoneValue[index]
        // + stoneValue[index + 1]
        // + stoneValue[index + 2]
        //
        // Opponent starts from index + 3.
        // -------------------------------------------------------
        if(index + 2 < n)
        {
            ans = max(ans,
                      stoneValue[index]
                    + stoneValue[index + 1]
                    + stoneValue[index + 2]
                    - solve(index + 3, n, stoneValue, dp));
        }

        // Store and return the best possible score difference
        // from this index.
        return dp[index] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue)
    {
        int n = stoneValue.size();

        // dp[i] stores the maximum score difference
        // (Current Player's Score - Opponent's Score)
        // starting from index i.
        vector<int> dp(n, -1);

        // Calculate the maximum score difference
        // starting from the first stone.
        int diff = solve(0, n, stoneValue, dp);

        // Positive difference means Alice gets more points.
        if(diff > 0)
        {
            return "Alice";
        }

        // Negative difference means Bob gets more points.
        else if(diff < 0)
        {
            return "Bob";
        }

        // Difference is zero, so both players have equal scores.
        else
        {
            return "Tie";
        }
    }
};

************************************************APPROACH 2nd(TABULATION)********************************************

class Solution {// TC ---> O(N)                                 SC ---> O(N)
public:
    string stoneGameIII(vector<int>& stoneValue) {

        int n = stoneValue.size();

        // dp[i] stores the maximum score difference
        // (Current Player's Score - Opponent's Score)
        // starting from index i.
        //
        // dp[n] = 0 because when there are no stones left,
        // the score difference is 0.
        vector<int> dp(n + 1);

        // Build the answer from the end towards the beginning.
        // Since dp[i] depends on dp[i+1], dp[i+2], and dp[i+3],
        // those values must already be computed.
        for(int i = n - 1; i >= 0; i--)
        {
            // --------------------------------------------------
            // Choice 1: Take only 1 stone.
            //
            // Gain = stoneValue[i]
            //
            // Opponent starts from i+1.
            //
            // Net advantage =
            // Current gain - Opponent's advantage.
            // --------------------------------------------------
            dp[i] = stoneValue[i] - dp[i + 1];

            // --------------------------------------------------
            // Choice 2: Take 2 stones (if available).
            //
            // Gain =
            // stoneValue[i] + stoneValue[i+1]
            //
            // Opponent starts from i+2.
            // --------------------------------------------------
            if(i + 1 < n && i + 2 <= n)
            {
                dp[i] = max(dp[i],
                            stoneValue[i]
                          + stoneValue[i + 1]
                          - dp[i + 2]);
            }

            // --------------------------------------------------
            // Choice 3: Take 3 stones (if available).
            //
            // Gain =
            // stoneValue[i]
            // + stoneValue[i+1]
            // + stoneValue[i+2]
            //
            // Opponent starts from i+3.
            // --------------------------------------------------
            if(i + 1 < n && i + 2 < n && i + 3 <= n)
            {
                dp[i] = max(dp[i],
                            stoneValue[i]
                          + stoneValue[i + 1]
                          + stoneValue[i + 2]
                          - dp[i + 3]);
            }
        }

        // Maximum score difference starting from index 0.
        int diff = dp[0];

        // Positive difference means Alice gets more points.
        if(diff > 0)
        {
            return "Alice";
        }

        // Negative difference means Bob gets more points.
        else if(diff < 0)
        {
            return "Bob";
        }

        // Difference is 0, so both players have equal scores.
        else
        {
            return "Tie";
        }
    }
};
