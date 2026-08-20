***********************************************APPROACH 1st(MEMOIZATION)**********************************************

class Solution {// TC ---> O(n³)                                         SC ---> O(n²)
public:

    // Returns the maximum score that can be obtained
    // from the subarray [left ... right]
    int solve(int left, int right, vector<int>& cumulativeSum,
              vector<vector<int>>& dp)
    {
        // If there is only one element, we cannot split it,
        // so no more score can be obtained.
        if(left >= right)
        {
            return 0;
        }

        // If this state is already calculated,
        // return the stored result.
        if(dp[left][right] != -1)
        {
            return dp[left][right];
        }

        int score = 0;

        // Try every possible partition point.
        //
        // Example:
        // [left ........ mid | mid+1 ........ right]
        //
        // We divide the current range into two parts.
        for(int mid = left; mid <= right - 1; mid++)
        {
            // Calculate sum of the left part [left ... mid].
            //
            // Prefix sum formula:
            // sum(left, mid) = prefix[mid] - prefix[left-1]
            //
            // If left == 0, there is no prefix[-1],
            // so we subtract 0.
            int leftSum = cumulativeSum[mid] - (left - 1 >= 0 ? cumulativeSum[left - 1] : 0);

            // Calculate sum of the right part [mid+1 ... right].
            //
            // prefix[right] contains sum from 0 to right.
            // prefix[mid] contains sum from 0 to mid.
            //
            // Therefore:
            // rightSum = prefix[right] - prefix[mid]
            int rightSum = cumulativeSum[right] - cumulativeSum[mid];

            // If left part has smaller sum,
            // we keep the left part and continue the game
            // on [left ... mid].
            if(leftSum < rightSum)
            {
                score = max(score,leftSum + solve(left, mid, cumulativeSum, dp));
            }

            // If right part has smaller sum,
            // we keep the right part and continue the game
            // on [mid+1 ... right].
            else if(leftSum > rightSum)
            {
                score = max(score,rightSum + solve(mid + 1, right, cumulativeSum, dp));
            }

            // If both parts have equal sum,
            // we are allowed to choose either part.
            //
            // So we try both possibilities and take
            // the maximum score.
            else
            {
                score = max({score,

                    // Keep left part
                    leftSum + solve(left, mid, cumulativeSum, dp),

                    // Keep right part
                    rightSum + solve(mid + 1, right, cumulativeSum, dp)
                });
            }
        }

        // Store the result for this [left, right] state
        // so that we don't calculate it again.
        return dp[left][right] = score;
    }

    int stoneGameV(vector<int>& stoneValue)
    {
        int n = stoneValue.size();

        // cumulativeSum[i] stores the sum of elements
        // from index 0 to i.
        //
        // Example:
        // stoneValue = [6, 2, 3, 4]
        // cumulativeSum = [6, 8, 11, 15]
        vector<int> cumulativeSum(n, 0);

        cumulativeSum[0] = stoneValue[0];

        for(int i = 1; i < n; i++)
        {
            cumulativeSum[i] = cumulativeSum[i - 1] + stoneValue[i];
        }

        // dp[left][right] stores the maximum score
        // possible from the range [left ... right].
        //
        // -1 means this state has not been calculated yet.
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        // Start with the complete array.
        return solve(0, n - 1, cumulativeSum, dp);
    }
};

************************************************APPROACH 2nd(TABULATION)************************************************

class Solution {// Time: O(n³)                                        Space: O(n²)
public:

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        // cumulativeSum[i] stores the sum of elements
        // from index 0 to i.
        //
        // Example:
        // stoneValue   = [6, 2, 3, 4]
        // cumulativeSum = [6, 8, 11, 15]
        //
        // This allows us to calculate any range sum in O(1).
        vector<int> cumulativeSum(n, 0);

        cumulativeSum[0] = stoneValue[0];

        for(int i = 1; i < n; i++)
        {
            cumulativeSum[i] = cumulativeSum[i - 1] + stoneValue[i];
        }


        // dp[left][right] represents:
        //
        // Maximum score that can be obtained
        // from the subarray [left ... right].
        //
        // Initially all values are 0.
        //
        // dp[i][i] = 0 because a single element
        // cannot be split further.
        vector<vector<int>> dp(n + 1,vector<int>(n + 1, 0));


        // We process the intervals from smaller ranges
        // to larger ranges.
        //
        // left goes from right to left.
        //
        // This is important because when calculating
        // dp[left][right], we need:
        //
        // dp[left][mid]
        // dp[mid + 1][right]
        //
        // Both of these represent smaller intervals
        // and should already be calculated.
        for(int left = n - 1; left >= 0; left--)
        {
            // right starts from left + 1 because
            // a range with one element needs no split.
            for(int right = left + 1; right < n; right++)
            {
                int score = 0;


                // Try every possible partition point.
                //
                // [left ........ mid | mid+1 ........ right]
                //
                // Example:
                // [6, 2, 3, 4]
                //      ^
                //     mid
                //
                // We try every possible mid.
                for(int mid = left; mid <= right - 1; mid++)
                {
                    // Calculate sum of the left part:
                    //
                    // [left ... mid]
                    //
                    // Formula:
                    // prefix[mid] - prefix[left - 1]
                    //
                    // If left == 0, there is no
                    // prefix[left - 1], so subtract 0.
                    int leftSum = cumulativeSum[mid] - (left - 1 >= 0 ? cumulativeSum[left - 1] : 0);


                    // Calculate sum of the right part:
                    //
                    // [mid + 1 ... right]
                    //
                    // Formula:
                    // prefix[right] - prefix[mid]
                    int rightSum = cumulativeSum[right] - cumulativeSum[mid];


                    // If leftSum is smaller,
                    // we must keep the LEFT part.
                    //
                    // We get leftSum points and then
                    // continue the game on [left ... mid].
                    if(leftSum < rightSum)
                    {
                        score = max(score,leftSum + dp[left][mid]);
                    }


                    // If rightSum is smaller,
                    // we must keep the RIGHT part.
                    //
                    // We get rightSum points and then
                    // continue the game on [mid+1 ... right].
                    else if(leftSum > rightSum)
                    {
                        score = max(score,rightSum + dp[mid + 1][right]);
                    }


                    // If both sums are equal,
                    // we can choose either side.
                    //
                    // Therefore, try both possibilities
                    // and take the maximum.
                    else
                    {
                        score = max({
                            score,

                            // Keep the left part
                            leftSum + dp[left][mid],

                            // Keep the right part
                            rightSum + dp[mid + 1][right]
                        });
                    }
                }


                // Store the best score for this interval.
                dp[left][right] = score;
            }
        }


        // dp[0][n-1] represents the maximum score
        // obtainable from the complete array.
        return dp[0][n - 1];
    }
};


/* 

                    [left ........ right]
                              |
                         try every mid
                              |
                  ┌───────────┴───────────┐
                  ↓                       ↓
             [left...mid]          [mid+1...right]
              leftSum                  rightSum
                  |                       |
        ┌─────────┼─────────┐             |
        ↓         ↓         ↓             |
     left <     left >    equal           |
     right      right                     |
        ↓         ↓         ↓             |
      keep      keep      choose          |
      LEFT      RIGHT     either          |

*/
