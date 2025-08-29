************************************************APPROACH 1st(USING RECURSION)****************************************

class Solution {// TC ---> O(2^N)                          SC--->O(N)
public:
    // Recursive function to compute the Longest Common Subsequence (LCS)
    // between the original string 's' and its reverse 'reverseString'
    int solve(int i, int j, int n, int m, string &s, string &reverseString)
    {
        // Base case: if we reach the end of either string,
        // there are no more characters to compare.
        if (i >= n || j >= m)
        {
            return 0;
        }

        // Case 1: If characters match, include this character in the subsequence
        // and move both pointers forward.
        if (s[i] == reverseString[j])
        {
            return 1 + solve(i + 1, j + 1, n, m, s, reverseString);
        }

        // Case 2: If characters don't match:
        //   Option A: Skip character from 's' → move i+1
        //   Option B: Skip character from 'reverseString' → move j+1
        // Take the maximum result from these two options.
        int skipFromS = solve(i + 1, j, n, m, s, reverseString);
        int skipFromReverse = solve(i, j + 1, n, m, s, reverseString);

        return max(skipFromS, skipFromReverse);
    }

    int longestPalindromeSubseq(string s)
    {
        int n = s.length();

        // Create a reversed version of 's'
        string reverseString = s;
        reverse(reverseString.begin(), reverseString.end());

        // The Longest Palindromic Subsequence is simply
        // the LCS of s and reverse(s).
        return solve(0, 0, n, n, s, reverseString);
    }
};

**********************************************APPROACH 1st(USING MEMOIZATION)************************************

class Solution {// TC--->O(N^2)                            SC--->O(N^2)
public:
    // Recursive + Memoized function to compute the LCS (Longest Common Subsequence)
    int solve(int i, int j, int n, int m, string &s, string &reverseString, vector<vector<int>> &dp)
    {
        // Base case: if we reach the end of either string
        if (i >= n || j >= m) 
        {
            return 0;
        }

        // If the result for this subproblem is already computed, return it
        if (dp[i][j] != -1) 
        {
            return dp[i][j];
        }

        // Case 1: If characters match, include this character and move both pointers forward
        if (s[i] == reverseString[j]) 
        {
            return dp[i][j] = 1 + solve(i + 1, j + 1, n, m, s, reverseString, dp);
        }

        // Case 2: If characters don't match:
        // Option A: Skip current character from 's' → move i+1
        // Option B: Skip current character from 'reverseString' → move j+1
        // Take maximum of both
        int skipFromS = solve(i + 1, j, n, m, s, reverseString, dp);
        int skipFromReverse = solve(i, j + 1, n, m, s, reverseString, dp);

        return dp[i][j] = max(skipFromS, skipFromReverse);
    }

    int longestPalindromeSubseq(string s) {
        int n = s.length();

        // Reverse the original string
        string reverseString = s;
        reverse(reverseString.begin(), reverseString.end());

        // Memoization table initialized with -1
        // dp[i][j] stores LCS result for s[i...n-1] and reverseString[j...m-1]
        vector<vector<int>> dp(n, vector<int>(n, -1));

        // Solve the problem starting from indices 0,0
        return solve(0, 0, n, n, s, reverseString, dp);
    }
};

*************************************************APPROACH 2nd(USING RECURSION)***************************************

