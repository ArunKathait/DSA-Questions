****************************************************************************************************************************
NOTES:
Version 1 (Combined condition)
if (n == 0 || m == 0) {
    return n + m;
}

What it means

If either string is empty

The SCS length is simply the length of the other string

Version 2 (Separate conditions)
if (n == 0) {
    return m;
}

if (m == 0) {
    return n;
}

What it means

If s1 is empty → take all of s2

If s2 is empty → take all of s1

✔ Same logic, just written explicitly


************************************************APPROACH 1st(USING RECURSION)***********************************************

class Solution {// TC ---> O(2^(n + m))                              SC ---> O(n + m)
  public:

    // This function returns the length of the
    // Shortest Common Supersequence (SCS)
    // for prefixes s1[0..n-1] and s2[0..m-1]
    int solve(int n, int m, string &s1, string &s2)
    {
        // Base case:
        // If either string is empty,
        // we must take all remaining characters of the other string
        // Hence length = n + m
        if(n == 0 || m == 0)
        {
            return n + m;
        }

        // If last characters of both strings are equal
        // we include this character once in SCS
        // and move both pointers backward
        if(s1[n-1] == s2[m-1])
        {
            return 1 + solve(n-1, m-1, s1, s2);
        }

        // If last characters are different:
        // Option 1: take last character from s1
        // Option 2: take last character from s2
        // Add 1 for the chosen character and
        // take the minimum length possible
        int takeFromS1 = 1 + solve(n-1, m, s1, s2);
        int takeFromS2 = 1 + solve(n, m-1, s1, s2);

        return min(takeFromS1, takeFromS2);
    }
    
    // Wrapper function
    int minSuperSeq(string &s1, string &s2) {
        int n = s1.length();
        int m = s2.length();

        // Start recursion from full lengths of both strings
        return solve(n, m, s1, s2);
    }
};

*************************************************APPROACH 2nd(USING MEMOIZATION)***************************************

class Solution {// TC ---> O(N*M)                              SC ---> O(N*M)
  public:

    // Returns the length of the Shortest Common Supersequence (SCS)
    // for s1[0..n-1] and s2[0..m-1] using memoization
    int solve(int n, int m, string &s1, string &s2, vector<vector<int>>& dp)
    {
        // Base case:
        // If one string is empty, the SCS is simply the remaining
        // characters of the other string
        if(n == 0 || m == 0)
        {
            return n + m;
        }

        // If this subproblem has already been solved,
        // return the stored result to avoid recomputation
        if(dp[n][m] != -1)
        {
            return dp[n][m];
        }

        // If last characters of both strings are the same,
        // include this character once and move both pointers
        if(s1[n-1] == s2[m-1])
        {
            return dp[n][m] = 1 + solve(n-1, m-1, s1, s2, dp);
        }

        // If last characters are different:
        // Option 1: take character from s1 and move n
        // Option 2: take character from s2 and move m
        // Add 1 for the chosen character and take minimum length
        int takeFromS1 = 1 + solve(n-1, m, s1, s2, dp);
        int takeFromS2 = 1 + solve(n, m-1, s1, s2, dp);

        // Store and return the minimum of the two options
        return dp[n][m] = min(takeFromS1, takeFromS2);
    }
    
    // Driver function
    int minSuperSeq(string &s1, string &s2) {
        int n = s1.length();
        int m = s2.length();

        // DP table where dp[i][j] stores the SCS length
        // for s1[0..i-1] and s2[0..j-1]
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        // Start recursion with full lengths
        return solve(n, m, s1, s2, dp);
    }
};

***********************************************APPROACH 3rd(TABULATION)*********************************************

class Solution {// TC ---> O(n × m)                           SC ---> O(n × m)
  public:
    int minSuperSeq(string &s1, string &s2) {

        // Lengths of both strings
        int n = s1.length();
        int m = s2.length();
        
        // dp[i][j] = length of the Shortest Common Supersequence (SCS)
        // for prefixes s1[0..i-1] and s2[0..j-1]
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        
        // Build the DP table in bottom-up manner
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= m; j++)
            {
                // Base case:
                // If one string is empty, SCS is the length of the other string
                if(i == 0 || j == 0)
                {
                    dp[i][j] = i + j;
                }

                // If last characters of both prefixes are equal
                // Include the character once and move diagonally
                else if(s1[i-1] == s2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }

                // If last characters are different
                // Try taking character from s1 or s2
                // and take the minimum length
                else
                {
                    int takeFromS1 = 1 + dp[i-1][j];
                    int takeFromS2 = 1 + dp[i][j-1];
                    
                    dp[i][j] = min(takeFromS1, takeFromS2);
                }
            }
        }

        // dp[n][m] contains the length of the SCS for full strings
        return dp[n][m];
    }
};

**************************************************(PRINT SCS --> LEETCODE QUESTION)************************************

// NOTE : In above code we are finding SCS but here we have to print LCS which is asked in leetcode question.
