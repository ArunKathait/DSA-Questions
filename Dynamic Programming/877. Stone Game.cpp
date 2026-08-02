*****************************************************APPROACH 1st*******************************************************
  
class Solution {// TC ---> O(n²)                               SC ---> O(n²)
public:

    // Returns the maximum stones the current player can collect
    // from piles[left...right] assuming both players play optimally.
    int solve(int left, int right, vector<int>& piles,
              vector<vector<int>>& dp)
    {
        // Base case:
        // No piles left to pick.
        if (left > right)
        {
            return 0;
        }

        // If already computed, return the stored answer.
        if (dp[left][right] != -1)
        {
            return dp[left][right];
        }

        //------------------------------------------------------------
        // Option 1 : Pick the LEFT pile
        //------------------------------------------------------------

        // Alice picks piles[left].
        //
        // Remaining interval = [left+1 ... right]
        //
        // Now Bob's turn.
        //
        // Bob has two choices:
        //
        // 1. Pick left+1
        //      Remaining -> [left+2 ... right]
        //
        // 2. Pick right
        //      Remaining -> [left+1 ... right-1]
        //
        // Bob plays optimally to reduce Alice's future score,
        // therefore Alice gets the MINIMUM of these two possibilities.
        int pickLeft =
            piles[left] +
            min(
                solve(left + 2, right, piles, dp),
                solve(left + 1, right - 1, piles, dp)
            );

        //------------------------------------------------------------
        // Option 2 : Pick the RIGHT pile
        //------------------------------------------------------------

        // Alice picks piles[right].
        //
        // Remaining interval = [left ... right-1]
        //
        // Bob again has two choices:
        //
        // 1. Pick left
        //      Remaining -> [left+1 ... right-1]
        //
        // 2. Pick right-1
        //      Remaining -> [left ... right-2]
        //
        // Bob minimizes Alice's future score.
        int pickRight =
            piles[right] +
            min(
                solve(left + 1, right - 1, piles, dp),
                solve(left, right - 2, piles, dp)
            );

        // Alice chooses the better of the two options.
        return dp[left][right] = max(pickLeft, pickRight);
    }

    bool stoneGame(vector<int>& piles) {

        int n = piles.size();

        // Calculate total stones.
        int totalSum = 0;

        for (auto &num : piles)
        {
            totalSum += num;
        }

        // Memoization table.
        // dp[i][j] stores the answer for piles[i...j].
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        // Maximum stones Alice can collect.
        int AliceScore = solve(0, n - 1, piles, dp);

        // Bob gets the remaining stones.
        //
        // BobScore = totalSum - AliceScore
        //
        // Alice wins if:
        // AliceScore > BobScore
        //
        // This is equivalent to:
        // AliceScore > totalSum / 2
        //
        // Since the total sum is guaranteed to be odd in this problem,
        // using >= also works because equality is impossible.
        return AliceScore >= totalSum / 2;
    }
};

*************************************************APPROACH 2nd*************************************************************

  class Solution {// TC ---> O(N^2)                        SC ---> O(N^2)
public:

    // solve(left, right) returns the maximum score difference
    // (Current Player's Score - Opponent's Score)
    // that the current player can achieve from piles[left...right].
    int solve(int left, int right, vector<int>& piles,
              vector<vector<int>>& dp)
    {
        // Base case:
        // No piles left, so the score difference is 0.
        if (left > right)
        {
            return 0;
        }

        // If this state has already been computed,
        // return the stored answer.
        if (dp[left][right] != -1)
        {
            return dp[left][right];
        }

        //--------------------------------------------------------
        // Option 1 : Pick the LEFT pile
        //--------------------------------------------------------

        // Current player gains piles[left].
        //
        // After this move, the opponent becomes the current player
        // for the remaining interval [left+1 ... right].
        //
        // solve(left+1, right) represents the score difference
        // the opponent can achieve from that interval.
        //
        // Since that advantage belongs to the opponent,
        // subtract it from our current gain.
        int pickLeft =
            piles[left] - solve(left + 1, right, piles, dp);

        //--------------------------------------------------------
        // Option 2 : Pick the RIGHT pile
        //--------------------------------------------------------

        // Same logic as above.
        int pickRight =
            piles[right] - solve(left, right - 1, piles, dp);

        // Choose the move that gives the maximum score difference.
        return dp[left][right] = max(pickLeft, pickRight);
    }

    bool stoneGame(vector<int>& piles) {

        int n = piles.size();

        // DP table.
        // dp[i][j] stores the answer for interval [i...j].
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        // Maximum score difference Alice can achieve.
        int AliceScore = solve(0, n - 1, piles, dp);

        // If score difference >= 0,
        // Alice's score >= Bob's score.
        //
        // In LeetCode 877, the total number of stones is odd,
        // so equality is impossible.
        //
        // Therefore:
        // AliceScore >= 0  ==> Alice wins.
        return AliceScore >= 0;
    }
};
