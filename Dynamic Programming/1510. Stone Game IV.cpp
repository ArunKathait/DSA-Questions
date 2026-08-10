************************************************APPROACH 1st(MEMOIZATION)*******************************************

class Solution {// TC ---> O(n√n)                       SC ---> O(n)
public:

    // solve(num) answers:
    // "Can the current player WIN when there are 'num' stones left?"
    //
    // dp[num]:
    // -1  -> this state has not been calculated yet
    //  1  -> current player can win
    //  0  -> current player will lose
    bool solve(int num, vector<int>& dp)
    {
        // If there are 0 stones left,
        // the current player cannot make any move.
        //
        // Therefore, the current player loses.
        if(num == 0)
        {
            return false;
        }


        // Check whether we have already calculated
        // the answer for this number of stones.
        //
        // If dp[num] is not -1, it means:
        // we have already solved this state.
        if(dp[num] != -1)
        {
            // If dp[num] == 1 -> true (winning state)
            // If dp[num] == 0 -> false (losing state)
            return dp[num] == 1 ? true : false;
        }


        // Try taking every possible perfect square.
        //
        // k = 1 -> 1 * 1 = 1
        // k = 2 -> 2 * 2 = 4
        // k = 3 -> 3 * 3 = 9
        // ...
        //
        // We can only take k*k if k*k <= num.
        for(int k = 1; k * k <= num; k++)
        {
            // Suppose we take k*k stones.
            //
            // Then:
            // remaining stones = num - k*k
            //
            // Now it is the opponent's turn.
            //
            // If the opponent LOSES from that state,
            // then we can WIN by making this move.
            if(solve(num - k * k, dp) == false)
            {
                // Current player can win.
                dp[num] = true;

                return true;
            }
        }


        // We tried every possible perfect square:
        //
        // 1, 4, 9, 16, ...
        //
        // But none of them puts the opponent
        // into a losing state.
        //
        // Therefore, current player loses.
        dp[num] = false;

        return false;
    }


    bool winnerSquareGame(int n)
    {
        // We need n + 1 positions because
        // we need indices from 0 to n.
        //
        // Example:
        // n = 5
        //
        // dp[0], dp[1], dp[2], dp[3], dp[4], dp[5]
        //
        // Initially all states are unknown.
        // So we initialize them with -1.
        vector<int> dp(n + 1, -1);

        // Start the game with n stones.
        //
        // solve(n, dp) tells us whether
        // the first player can win.
        return solve(n, dp);
    }
};

***********************************************APPROACH 2nd(TABULATION)*******************************************

class Solution {// TC ---> O(n√n)                                    SC ---> O(n)
public:

    bool winnerSquareGame(int n) {

        // dp[i] tells us whether the current player
        // can WIN when there are 'i' stones remaining.
        //
        // dp[i] = true  -> current player wins
        // dp[i] = false -> current player loses
        //
        // We need indices from 0 to n,
        // so we create n + 1 elements.
        vector<bool> dp(n + 1, false);


        // Base case:
        //
        // If there are 0 stones, the current player
        // cannot make any move.
        //
        // Therefore, the current player loses.
        dp[0] = false;


        // Calculate the answer for every number
        // of stones from 1 to n.
        //
        // We calculate smaller states first because
        // dp[i] depends on dp[i - k*k].
        for(int i = 1; i < n + 1; i++)
        {

            // Try every possible perfect square
            // that can be taken from 'i' stones.
            //
            // k = 1 -> 1 * 1 = 1
            // k = 2 -> 2 * 2 = 4
            // k = 3 -> 3 * 3 = 9
            //
            // We stop when k*k becomes greater than i.
            for(int k = 1; k * k <= i; k++)
            {

                // Suppose the current player takes k*k stones.
                //
                // Remaining stones:
                // i - k*k
                //
                // Now it becomes the opponent's turn.
                //
                // If dp[i - k*k] is false,
                // that means the opponent will LOSE
                // from that state.
                //
                // Therefore, the current player can WIN.
                if(dp[i - k * k] == false)
                {
                    dp[i] = true;

                    // We found one winning move.
                    //
                    // We don't need to check any other
                    // possible squares.
                    break;
                }
            }
        }


        // dp[n] contains the answer for the
        // original game with n stones.
        //
        // true  -> first player wins
        // false -> first player loses
        return dp[n] == true ? true : false;
    }
};
