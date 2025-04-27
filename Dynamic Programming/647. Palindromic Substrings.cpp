*******************************************APPROACH 1st(USING RECURSION)***********************************

class Solution {// TC--->O(N^3)                                   SC--->O(N)
public:
    // Helper function to check if the substring s[left...right] is a palindrome
    bool check(int left, int right, string &s)
    {
        // Base case: If left index crosses or meets right, it's a palindrome
        if (left >= right)
        {
            return true; 
        }

        // If characters at current positions don't match, not a palindrome
        if (s[left] != s[right])
        {
            return false;
        }

        // If current characters match, check the inner substring (left+1, right-1)
        return check(left + 1, right - 1, s);
    }

    // Main function to count all palindromic substrings
    int countSubstrings(string s) {
         // Length of the input string
        int n = s.length();
        
        // To store the final count of palindromic substrings
        int ans = 0; 

        // Try every possible substring s[i...j]
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                // If the substring s[i...j] is a palindrome
                if (check(i, j, s) == true)
                {
                    // Increment the count
                    ans++; 
                }
            }
        }
        
        // Return the total number of palindromic substrings
        return ans; 
    }
};

*****************************************APPROACH 2nd(USING MEMOIZATION)***************************************

class Solution {// TC--->O(N^2)                          SC--->O(N^2)
public:
    // Helper function to check if substring s[left...right] is a palindrome
    bool check(int left, int right, string &s, vector<vector<int>>& dp)
    {
        // Base case: if left crosses or meets right, it's a palindrome
        if (left >= right)
        {
            return true; 
        }

        // If already computed, return the stored result
        if (dp[left][right] != -1)
        {
            return dp[left][right];
        }

        // If characters at left and right are not the same, not a palindrome
        if (s[left] != s[right])
        {
            return dp[left][right] = false;
        }

        // Characters match: Check inner substring (left+1, right-1) recursively
        return dp[left][right] = check(left + 1, right - 1, s, dp);
    }

    int countSubstrings(string s) {
        int n = s.length(); // Length of the input string
        
        // Create a 2D DP array initialized with -1
        // dp[i][j] will store if s[i...j] is palindrome (1 for true, 0 for false)
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
         // To store the total count of palindromic substrings
        int ans = 0;

        // Try every possible substring s[i...j]
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                // If s[i...j] is a palindrome, increment the answer
                if (check(i, j, s, dp) == true)
                {
                    ans++;
                }
            }
        }
        // Return the total number of palindromic substrings
        return ans; 
    }
};

********************************************APPROACH 3rd(TABULATION)*********************************************
