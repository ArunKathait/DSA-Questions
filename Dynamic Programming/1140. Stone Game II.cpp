
class Solution {// TC ---> O(n³)                                  SC ---> O(n²)
public:
    // dp[person][index][M]
    //
    // person = 1 -> Alice's turn
    // person = 0 -> Bob's turn
    //
    // index -> current pile
    // M -> maximum value used to determine how many piles
    //      the current player can take (1 to 2*M)
    //
    // dp stores the maximum number of stones Alice can collect
    // from the current state.
    int dp[2][101][101];

    int solveForAlice(int index, int n, int person, vector<int>& piles, int M)
    {
        // No piles left.
        if(index >= n)
        {
            return 0;
        }

        // If this state is already calculated, return it.
        if(dp[person][index][M] != -1)
        {
            return dp[person][index][M];
        }

        // Alice wants to maximize her stones.
        // Bob wants to minimize Alice's stones.
        int ans = (person == 1) ? -1 : INT_MAX;

        // Stores the total stones taken in the current move.
        int stones = 0;

        // Current player can take from 1 to 2*M piles.
        for(int x = 1; x <= min(2 * M, n - index); x++)
        {
            // Add the current pile to the total stones taken.
            stones += piles[index + x - 1];

            // Alice's turn.
            if(person == 1)
            {
                // Alice gets 'stones' and then Bob plays.
                // Alice wants to maximize her final number of stones.
                ans = max(ans, stones + solveForAlice(index + x, n, 0, piles, max(M, x)));
            }

            // Bob's turn.
            else
            {
                // Bob's stones are not added because we are calculating
                // Alice's total stones.
                // Bob wants to minimize Alice's final result.
                ans = min(ans, solveForAlice(index + x, n, 1, piles, max(M, x)));
            }
        }

        // Store and return the answer for this state.
        return dp[person][index][M] = ans;
    }

    int stoneGameII(vector<int>& piles)
    {
        int n = piles.size();

        // Initialize DP with -1.
        memset(dp, -1, sizeof(dp));

        // Start from index 0, Alice's turn, M = 1.
        return solveForAlice(0, n, 1, piles, 1);
    }
};
