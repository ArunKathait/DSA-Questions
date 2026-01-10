************************************************APPROACH 1st(USING RECURSION)*****************************************

class Solution {// TC ---> O(2(n+m))                             SC ---> O(n+m)
public:

    // Recursive function to calculate minimum ASCII delete sum
    // i -> current index in string s1
    // j -> current index in string s2
    // n -> length of s1
    // m -> length of s2
    int solve(int i, int j, int n, int m, string &s1, string &s2)
    {
        // Base Case 1:
        // If both strings are completely processed,
        // no characters left to delete
        if (i >= n && j >= m)
        {
            return 0;
        }

        // Base Case 2:
        // If s1 is finished but s2 still has characters,
        // we must delete all remaining characters of s2
        // Cost = sum of ASCII values of s2[j ... m-1]
        if (i == n)
        {
            int sum = 0;
            for (int k = j; k < m; k++)
            {
                sum += s2[k];
            }
            return sum;
        }

        // Base Case 3:
        // If s2 is finished but s1 still has characters,
        // we must delete all remaining characters of s1
        // Cost = sum of ASCII values of s1[i ... n-1]
        if (j == m)
        {
            int sum = 0;
            for (int k = i; k < n; k++)
            {
                sum += s1[k];
            }
            return sum;
        }

        // If current characters of both strings are equal,
        // no deletion is needed, move both pointers forward
        if (s1[i] == s2[j])
        {
            return solve(i + 1, j + 1, n, m, s1, s2);
        }

        // Option 1:
        // Delete current character from s1
        // Cost = ASCII value of s1[i] + cost of remaining strings
        int deleteFromS1 = s1[i] + solve(i + 1, j, n, m, s1, s2);

        // Option 2:
        // Delete current character from s2
        // Cost = ASCII value of s2[j] + cost of remaining strings
        int deleteFromS2 = s2[j] + solve(i, j + 1, n, m, s1, s2);

        // Return the minimum cost between deleting from s1 or s2
        return min(deleteFromS1, deleteFromS2);
    }

    // Main function called by LeetCode
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        // Start recursion from index 0 of both strings
        return solve(0, 0, n, m, s1, s2);
    }
};

************************************************APPROACH 2nd(USING MEMOIZATION)************************************

class Solution {// TC ---> O(N*M)                           SC ---> O(N*M)
public:

    // Recursive function with memoization (DP)
    // i  -> current index in string s1
    // j  -> current index in string s2
    // n  -> length of s1
    // m  -> length of s2
    // dp -> memo table to store results of subproblems
    int solve(int i, int j, int n, int m,
              string &s1, string &s2,
              vector<vector<int>>& dp)
    {
        // Base Case 1:
        // If both strings are fully processed,
        // no characters left to delete
        if (i >= n && j >= m)
        {
            return 0;
        }

        // If this state (i, j) was already solved,
        // return the stored answer to avoid recomputation
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        // Base Case 2:
        // s1 is exhausted, so delete all remaining characters of s2
        // Cost = sum of ASCII values of s2[j ... m-1]
        if (i == n)
        {
            int sum = 0;
            for (int k = j; k < m; k++)
            {
                sum += s2[k];
            }
            return dp[i][j] = sum;
        }

        // Base Case 3:
        // s2 is exhausted, so delete all remaining characters of s1
        // Cost = sum of ASCII values of s1[i ... n-1]
        if (j == m)
        {
            int sum = 0;
            for (int k = i; k < n; k++)
            {
                sum += s1[k];
            }
            return dp[i][j] = sum;
        }

        // If current characters of both strings match,
        // no deletion is needed, move both pointers forward
        if (s1[i] == s2[j])
        {
            return dp[i][j] = solve(i + 1, j + 1, n, m, s1, s2, dp);
        }

        // Option 1:
        // Delete the current character from s1
        // Cost = ASCII value of s1[i] + cost of remaining part
        int deleteFromS1 = s1[i] + solve(i + 1, j, n, m, s1, s2, dp);

        // Option 2:
        // Delete the current character from s2
        // Cost = ASCII value of s2[j] + cost of remaining part
        int deleteFromS2 = s2[j] + solve(i, j + 1, n, m, s1, s2, dp);

        // Store and return the minimum of both choices
        return dp[i][j] = min(deleteFromS1, deleteFromS2);
    }

    // Main function called by LeetCode
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        // DP table of size (n+1) x (m+1)
        // dp[i][j] = minimum delete sum for s1[i...] and s2[j...]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        // Start recursion from index 0 of both strings
        return solve(0, 0, n, m, s1, s2, dp);
    }
};
