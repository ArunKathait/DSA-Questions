***********************************************APPROACH 1st(USING RECURSION)*****************************************

class Solution {// Tc ---> k^N                       Sc ---> O(N)
public:
    // This function returns the minimum number of perfect squares
    // needed to sum up to 'num'
    int solve(int num)
    {
        // Base case:
        // If the number becomes 0, no squares are needed
        if(num == 0)
        {
            return 0;
        }

        // Initialize answer with a very large value
        // This will store the minimum count of squares
        int minCount = INT_MAX;

        // Try all perfect squares less than or equal to 'num'
        for(int i = 1; i * i <= num; i++)
        {
            // Choose square i*i and solve remaining problem
            // 1 represents choosing the current square
            int result = 1 + solve(num - i * i);

            // Update minimum count
            minCount = min(minCount, result);
        }

        // Return the minimum squares required for 'num'
        return minCount;
    }
    
    // Main function called by LeetCode
    int numSquares(int n) {
        // Start recursion with the full number n
        return solve(n);
    }
};

********************************************APPROACH 2nd(USING MEMOIZATION)*****************************************

class Solution {// TC ---> O(n √n)                            Sc ---> O(n)
public:
    // This function returns the minimum number of perfect squares
    // required to sum up to 'num'
    // dp[num] stores the already computed result for 'num'
    int solve(int num, vector<int>& dp)
    {
        // Base case:
        // If number becomes 0, no squares are needed
        if (num == 0)
        {
            return 0;
        }

        // If result for this number is already computed,
        // return it to avoid recomputation
        if (dp[num] != -1)
        {
            return dp[num];
        }

        // Initialize minimum count with a large value
        int minCount = INT_MAX;

        // Try all perfect squares less than or equal to 'num'
        for (int i = 1; i * i <= num; i++)
        {
            // Choose square i*i and solve the remaining part
            // +1 represents selecting the current square
            int result = 1 + solve(num - i * i, dp);

            // Update minimum count
            minCount = min(minCount, result);
        }

        // Store the result in dp array and return it
        return dp[num] = minCount;
    }
    
    // Main function called by LeetCode
    int numSquares(int n) {
        // dp array initialized with -1 (uncomputed states)
        vector<int> dp(n + 1, -1);

        // Start solving for n
        return solve(n, dp);
    }
};

*********************************************APPROACH 3rd(USING TABULATION)*****************************************

class Solution {// TC ---> O(n √n)                             SC ---> O(n)
public:
    int numSquares(int n) {

        // dp[i] will store the minimum number of perfect squares
        // needed to make sum = i
        vector<int> dp(n + 1, INT_MAX);

        // Base case:
        // 0 can be formed using 0 perfect squares
        dp[0] = 0;

        // Build the dp table from 1 to n
        for (int i = 1; i <= n; i++)
        {
            // Try every perfect square j*j that is <= i
            for (int j = 1; j * j <= i; j++)
            {
                // If we choose square (j*j),
                // then remaining value is (i - j*j)
                // Add 1 for the current square
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
            }
        }

        // dp[n] contains the minimum number of squares for n
        return dp[n];
    }
};
