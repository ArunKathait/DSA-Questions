*******************************************APPROACH 1st(RECURSION)*****************************************************

class Solution {//TC--->O(2^(N+M))       SC--->O(N*M) + Recursive Stack space
public:
    // Recursive function to find the longest common subsequence (LCS)
    int solve(string text1,string text2,int i,int j,int n,int m)
    {
        // Base case: If we reach the end of either string, return 0
        if(i >= n || j >= m)
        {
            return 0;
        }
        
        // If characters match, include this character in LCS and move to next indices
        if(text1[i] == text2[j])
        {
            return 1 + solve(text1,text2,i+1,j+1,n,m);
        }
        
        // If characters don't match, explore two possibilities:
        // Move forward in text1 (keeping j same)
        int a = solve(text1,text2,i,j+1,n,m);

        // Move forward in text2 (keeping i same)
        int b = solve(text1,text2,i+1,j,n,m);
        
        // Return the maximum of both possibilities
        return max(a,b);

    }
   
    // Function to find the length of the longest common subsequence
    int longestCommonSubsequence(string text1, string text2) {
        // Length of first string
        int n = text1.size();

        // Length of second string
        int m = text2.size();
        
        // Call the recursive function starting from index 0 of both strings
        return solve(text1,text2,0,0,n,m);
    }
};


************************************************APPROACH 2nd(MEMOIZATION)********************************************

class Solution {// TC--->O(N*M)                 SC--->O(N*M)
public:

    // Memoization table (DP array) to store intermediate results
    int dp[1001][1001];

    // Recursive function to find the longest common subsequence (LCS)
    int solve(string text1,string text2,int i,int j,int n,int m)
    {
        // Base case: If we reach the end of either string, return 0
        if(i >= n || j >= m)
        {
            return 0;
        }
        
         // If we have already computed the result for this (i, j), return it
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        // If characters match, include this character in LCS and move to next indices
        if(text1[i] == text2[j])
        {
            return dp[i][j] =  1 + solve(text1,text2,i+1,j+1,n,m);
        }
        
        // If characters don't match, explore two possibilities:
        // Move forward in text1 (keeping j same)
        int a = solve(text1,text2,i,j+1,n,m);

        // Move forward in text2 (keeping i same)
        int b = solve(text1,text2,i+1,j,n,m);
        
        // Store the result in DP table and return the maximum of both possibilities
        return dp[i][j] = max(a,b);

    }
   
    // Function to find the length of the longest common subsequence
    int longestCommonSubsequence(string text1, string text2) {
        // Length of first string
        int n = text1.size();

        // Length of second string
        int m = text2.size();
        
        // Initialize the DP table with -1 (indicating uncomputed states)
        memset(dp,-1,sizeof(dp));

        // Call the recursive function starting from index 0 of both strings
        return solve(text1,text2,0,0,n,m);
    }
};

**********************************************APPROACH 3rd(USING TABULATION)****************************************

class Solution {// TC ---> O(n × m)                           SC ---> O(n × m)
  public:
    int longestCommonSubsequence(string &s1, string &s2) {
        int n = s1.length();
        int m = s2.length();
        
        // dp[i][j] = length of LCS for s1[0..i-1] and s2[0..j-1]
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        // Fill DP table in bottom-up manner
        for(int i = 0; i <= n; i++) 
        {
            for(int j = 0; j <= m; j++) 
            {
                // Base case: if either string is empty, LCS length = 0
                if(i == 0 || j == 0) 
                {
                    dp[i][j] = 0;
                }

                // If last characters match, include it and move diagonally
                else if(s1[i-1] == s2[j-1]) 
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }

                // If last characters don't match, take the maximum ignoring one character
                else 
                {
                    int takeFromS1 = dp[i-1][j];
                    int takeFromS2 = dp[i][j-1];
                    
                    dp[i][j] = max(takeFromS1, takeFromS2);
                }
            }
        }
        
        // dp[n][m] contains the length of LCS for full strings
        return dp[n][m];
    }
};
    
    
    
    
    
