*********************************************APPROACH 1st(USING RECURSION)************************************

class Solution {// TC--->O(N^3)                              SC--->O(N)--->Recursion stack
public:
    // Helper function to check if the substring s[left...right] is a palindrome
    int check(int left, int right, string &s)
    {
        // Base case: If left index crosses right, it means all characters matched
        if (left >= right)
        {
            return true;
        }

        // If characters at left and right are not same, not a palindrome
        if (s[left] != s[right])
        {
            return false;
        }

        // Move one step closer from both ends and check again
        return check(left + 1, right - 1, s);
    }

    // Function to find the longest palindromic substring in 's'
    string longestPalindrome(string s) {
        // Length of the input string
        int n = s.length();

        // To store starting index of longest palindrome   
        int startingPoint = -1; 

        // To store maximum length found
        int maxLength = 0;      

        // Iterate through all possible substrings
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                // Check if substring from i to j is a palindrome
                if (check(i, j, s) == true)
                {
                    // If it's a palindrome and longer than previously found ones
                    if ((j - i + 1) > maxLength)
                    {
                        // Update maxLength
                        maxLength = j - i + 1; 

                        // Update startingPoint'
                        startingPoint = i;      
                    }
                }
            }
        }
        // Return the longest palindromic substring
        return s.substr(startingPoint, maxLength);
    }
};

*****************************************APPROACH 2nd(USING MEMOIZATION)***************************************

class Solution {// TC--->O(N^2)                     SC--->O(N^2)
public:
    // Helper function to check if s[left...right] is a palindrome using memoization
    int check(int left, int right, string &s, vector<vector<int>>& dp)
    {
        // Base case: If left index crosses or equals right, it's a palindrome (single char or empty)
        if (left >= right)
        {
            return true;
        }

        // If already computed before, directly return the stored result
        if (dp[left][right] != -1)
        {
            return dp[left][right];
        }

        // If characters at current left and right don't match, not a palindrome
        if (s[left] != s[right])
        {
            return dp[left][right] = false; // Store and return false
        }

        // Characters match, so check the inner substring (left+1, right-1)
        return dp[left][right] = check(left + 1, right - 1, s, dp);
    }

    // Main function to find the longest palindromic substring
    string longestPalindrome(string s) {
        // Length of input string
        int n = s.length();      

        // Stores maximum length of palindrome found
        int maxLength = 0;        

        // Stores starting index of longest palindrome
        int startingPoint = -1;   

        // Initialize dp table with -1, meaning "not computed yet"
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        // Try every possible substring
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                // If substring s[i...j] is palindrome
                if (check(i, j, s, dp) == true)
                {
                    // Update maximum length and starting point if longer palindrome found
                    if ((j - i + 1) > maxLength)
                    {
                        maxLength = j - i + 1;
                        startingPoint = i;
                    }
                }
            }
        }

        // Return the longest palindromic substring
        return s.substr(startingPoint, maxLength);
    }
};

