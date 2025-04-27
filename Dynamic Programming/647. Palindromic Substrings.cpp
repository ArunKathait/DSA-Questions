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

class Solution {// TC--->O(N^2)                         SC--->O(N^2)
public:
    int countSubstrings(string s) {
        int n = s.length();
        int ans = 0;

        // Create a 2D DP table of size n x n, initialized with false.
        // dp[i][j] = true if the substring s[i..j] is a palindrome
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // L is the length of the substring
        for (int L = 1; L <= n; L++) {
            // Iterate over all possible starting points i
            for (int i = 0; i + L - 1 < n; i++) 
            {
                // Ending point j based on starting i and length L
                int j = i + L - 1; 

                // Case 1: Substring of length 1 is always a palindrome
                if (i == j) 
                {
                    dp[i][j] = true;
                }
                // Case 2: Substring of length 2 is a palindrome if both characters are the same
                else if (i + 1 == j) 
                {
                    dp[i][j] = (s[i] == s[j]);
                }
                // Case 3: Substring of length more than 2
                // It's a palindrome if:
                //  - First and last characters are same (s[i] == s[j])
                //  - The middle part (i+1 to j-1) is also a palindrome (dp[i+1][j-1] == true)
                else 
                {
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
                }

                // If current substring s[i..j] is a palindrome, increment ans
                if (dp[i][j] == true) 
                {
                    ans++;
                }
            }
        }
        
        // Return total count of palindromic substrings
        return ans;
    }
};

*****************************************************APPROACH 4th(OPTIMISED)***********************************************************
class Solution {// TC--->O(N^2)                          SC--->O(1)
public:
    // Helper function to expand around the center and count palindromic substrings
    void check(int i, int j, string &s, int n, int &ans)
    {
        // Expand as long as the characters match and we stay inside bounds
        while(i >= 0 && j < n && s[i] == s[j])
        {
            // Found a palindrome substring, increment count
            ans++;

            // Expand to the left   
            i--;     

            // Expand to the right
            j++;     
        }
    }

    int countSubstrings(string s) {
        int n = s.length();
        int ans = 0; // Variable to store the total number of palindromic substrings

        // Iterate through each character in the string
        for(int i = 0; i < n; i++)
        {
            // Check for odd length palindromes (center at i)
            check(i, i, s, n, ans);

            // Check for even length palindromes (center between i and i+1)
            check(i, i+1, s, n, ans);
        }
        
        // Return the total count
        return ans; 
    }
};

