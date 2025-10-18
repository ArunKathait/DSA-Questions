********************************************APPROACH 1st(USING RECURSION)*************************************************

class Solution {//TC--->O(2^N)                          SC--->O(N + M)
public:
    // Recursive helper function to count number of distinct subsequences
    int solve(int i, int j, string &s, string &t)
    {
        // Base case 1:
        // If j < 0 → that means we have matched all characters of t successfully.
        // So, we found one valid subsequence of s that equals t.
        if (j < 0)
        {
            return 1;
        }

        // Base case 2:
        // If i < 0 → we ran out of characters in s but t still has characters left.
        // So, no possible match in this case.
        if (i < 0)
        {
            return 0;
        }

        // Recursive case:
        // If current characters match → we have two choices:
        // 1️⃣ Include s[i] in the subsequence to match t[j] → move both pointers left.
        // 2️⃣ Skip s[i] (don't include it) → move only i left.
        if (s[i] == t[j])
        {
            return solve(i - 1, j - 1, s, t) + solve(i - 1, j, s, t);
        }

        // If current characters do not match:
        // We cannot use s[i], so we skip it and move to the next character in s.
        return solve(i - 1, j, s, t);
    }
    
    int numDistinct(string s, string t)
    {
        int n = s.length(); // length of source string
        int m = t.length(); // length of target string

        // Start recursion from the last characters of both strings
        return solve(n - 1, m - 1, s, t);
    }
};

***********************************************APPROACH 2nd(USING MEMOIZATION(1))********************************************
// NOTE: Here index start from (n-1,m-1) for (i,j)

class Solution {// TC--->O(N*M)                              SC--->O(N*M)
public:
    // Recursive helper function with memoization
    int solve(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        // Base case 1:
        // If j < 0, it means we have matched all characters of t successfully.
        // So we found one valid subsequence of s that equals t.
        if (j < 0)
        {
            return 1;
        }

        // Base case 2:
        // If i < 0 but t is still not fully matched, that means
        // we’ve exhausted all characters of s but t remains unmatched.
        // So, no valid subsequence.
        if (i < 0)
        {
            return 0;
        }

        // If we have already computed this state (i, j),
        // return the stored result to avoid recomputation.
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        // Recursive case:
        // If current characters of s and t match
        if (s[i] == t[j])
        {
            // We have two options:
            // 1️⃣ Use s[i] to match t[j] → move both indices left
            // 2️⃣ Skip s[i] → move i left only
            return dp[i][j] = solve(i - 1, j - 1, s, t, dp) + solve(i - 1, j, s, t, dp);
        }

        // If current characters don't match:
        // We can’t use s[i], so just skip it and move to i - 1
        return dp[i][j] = solve(i - 1, j, s, t, dp);
    }

    int numDistinct(string s, string t)
    {
        int n = s.length(); // length of source string
        int m = t.length(); // length of target string

        // Create a 2D dp array to memoize results
        // dp[i][j] represents the number of distinct subsequences of s[0..i] that match t[0..j]
        vector<vector<int>> dp(n, vector<int>(m, -1));

        // Start recursion from the last characters of both strings
        return solve(n - 1, m - 1, s, t, dp);
    }
};

******************************************APPROACH 3rd(USING MEMOIZATION(2))*****************************************
// NOTE : Here index start from (0,0) for (i,j)

class Solution {// TC--->O(N*M)                            SC--->O(N*M)
public:
    // Recursive function with memoization
    // i -> current index in string s
    // j -> current index in string t
    // dp[i][j] -> number of distinct subsequences from s[i:] that form t[j:]
    int solve(int i, int j, string &s, string &t, vector<vector<int>> &dp) {

        // ✅ BASE CASE 1:
        // If we've matched all characters of t (j reached end of t),
        // that means we found one valid subsequence.
        if (j == t.size()) 
        {
            return 1;
        }

        // ✅ BASE CASE 2:
        // If we've reached the end of s but still have characters left in t,
        // then we cannot form t anymore → return 0.
        if (i == s.size()) 
        {
            return 0;
        }

        // ✅ If already computed, directly return stored result
        if (dp[i][j] != -1) 
        {
            return dp[i][j];
        }

        int ways = 0;

        // ✅ CASE 1: Characters match
        // When s[i] == t[j], we have TWO choices:
        //   1️⃣ Take s[i] as part of our subsequence → move both i & j forward
        //   2️⃣ Skip s[i] → move only i forward, keep j same
        if (s[i] == t[j]) 
        {
            ways = solve(i + 1, j + 1, s, t, dp)   // include s[i]
                  + solve(i + 1, j, s, t, dp);     // exclude s[i]
        }
        // ✅ CASE 2: Characters don’t match
        // We can’t use s[i], so we skip it and move only i forward.
        else 
        {
            ways = solve(i + 1, j, s, t, dp);
        }

        // ✅ Store the result before returning to avoid recomputation
        return dp[i][j] = ways;
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        // ✅ Create a 2D DP table initialized with -1
        // dp[i][j] = -1 means not yet computed
        vector<vector<int>> dp(n, vector<int>(m, -1));

        // ✅ Start recursion from index (0, 0)
        // meaning we are matching s[0:] with t[0:]
        return solve(0, 0, s, t, dp);
    }
};


********************************************APPROACH 3rd(USING TABULTION)********************************************

class Solution {// TC--->O(N*M)                             SC--->O(N*M)
public:
    int numDistinct(string s, string t) {
        int n = s.length(); // length of source string s
        int m = t.length(); // length of target string t

        // dp[i][j] = number of ways to form first j characters of t (t[0..j-1])
        //            using first i characters of s (s[0..i-1])
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(m + 1, 0));


        // ---------------- BASE CASES ----------------
        // Base Case 1:
        // If t is empty (j == 0), there is exactly 1 way to form it: by deleting all characters from s.
        for (int i = 0; i <= n; i++) 
        {
            dp[i][0] = 1;
        }

        // Base Case 2:
        // If s is empty (i == 0) but t is non-empty (j > 0),
        // then it's impossible to form t → 0 ways
        for (int j = 1; j <= m; j++) 
        {
            dp[0][j] = 0;
        }

        // ---------------- FILL DP TABLE ----------------
        // Loop through all prefixes of s and t
        for (int i = 1; i <= n; i++) 
        {
            for (int j = 1; j <= m; j++) 
            {
                if (s[i - 1] == t[j - 1]) 
                {
                    // ✅ Case 1: Characters match
                    // Two options:
                    // 1. Use s[i-1] to match t[j-1] → dp[i-1][j-1]
                    // 2. Skip s[i-1] and try matching t[j-1] with previous s → dp[i-1][j]
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } 
                else
                {
                    // ❌ Case 2: Characters do not match
                    // We cannot use s[i-1], so just skip it
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // The final answer is the number of ways to form entire t using entire s
        return dp[n][m];
    }
};
