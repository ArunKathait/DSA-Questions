*********************************************************APPROACH 1st(USING RECURSION)*******************************************************

class Solution {// TC--->O(2^N)                            SC--->O(N+M*K)
public:

    // Recursive function to check if string s can be segmented starting from 'index'
    int solve(int index, int n, string &s, unordered_set<string>& set) {
        // Base case: if index reaches end of string, return true (successful segmentation)
        if (index == n) {
            return true;
        }

        // This condition is redundant here and can be removed.
        // It's checking if the entire remaining string s is in the set, but it's not using the index.
        if (set.find(s) != set.end()) 
        {
            return true;
        }

        // Try every possible substring starting from current index
        for (int length = 1; length <= n; length++) 
        {
            // Get the substring of 'length' starting from 'index'
            string temp = s.substr(index, length);

            // If the substring is in the dictionary and the rest of the string can also be segmented
            if (set.find(temp) != set.end() && solve(index + length, n, s, set)) 
            {
                return true; // If successful, return true
            }
        }

        // If no valid segmentation found, return false
        return false;
    }

    // Main function
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length(); // Length of the input string

        // Convert wordDict vector to unordered_set for fast lookup
        unordered_set<string> set(wordDict.begin(), wordDict.end());

        // Start checking from index 0
        return solve(0, n, s, set);
    }
};


**************************************************APPROACH 2nd(USING MEMOIZATION)***************************************************************

class Solution {// TC--->O(N^2)                                    SC--->O(N+M*K)
public:

    // Helper function using recursion + memoization to check if substring starting at `index` can be segmented
    bool solve(int index, int n, string &s, unordered_set<string>& set, vector<int>& dp) {
        
        // ✅ Base case: if index reaches end of string, it means successful segmentation
        if(index == n) 
        {
            return true;
        }

        // ✅ If result for current index is already computed, return it (memoization)
        if(dp[index] != -1) 
        {
            return dp[index];
        }

        // ❌ This condition is incorrect and can be removed, 
        // because it checks entire string 's' instead of substring from current index
        if(set.find(s) != set.end()) 
        {
            return dp[index] = true;
        }

        // 🔁 Try every possible substring starting from current index
        for(int length = 1; length <= n; length++) 
        {
            
            // Get substring of `length` starting from `index`
            string temp = s.substr(index, length);

            // ✅ If the substring is in dictionary and rest of the string can also be segmented
            if(set.find(temp) != set.end() && solve(index + length, n, s, set, dp)) 
            {
                return dp[index] = true; // Store result and return true
            }
        }

        // ❌ No valid segmentation found — store and return false
        return dp[index] = false;
    }

    // Main function called with the input string and dictionary
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length(); // Length of input string

        // Convert wordDict to unordered_set for O(1) lookups
        unordered_set<string> set(wordDict.begin(), wordDict.end());

        // dp[i] stores whether s[i...n-1] can be segmented (initialized to -1)
        vector<int> dp(n, -1);

        // Start recursion from index 0
        return solve(0, n, s, set, dp);
    }
};

**************************************************APPROACH 3rd(USING TABULATION)*********************************************************

class Solution {
public:
    // Main logic using bottom-up DP (tabulation)
    bool solve(string s, vector<string>& wordDict) {

        // Convert wordDict into unordered_set for O(1) lookups
        unordered_set<string> st(begin(wordDict), end(wordDict));

        int n = s.length();

        // Create a DP table of size n+1, where t[i] = true means
        // the substring s[0...i-1] can be broken into dictionary words
        vector<bool> t(n + 1, false);

        /*
            t[i] = true;
            Means: the first i characters of s (i.e., s[0...i-1])
            can be broken into valid words from the dictionary
        */

        t[0] = true; // Empty string is always valid

        // Loop through all lengths from 1 to n
        for (int i = 1; i <= n; i++) 
        {
            // Try every possible break point j for s[0...i-1]
            for (int j = 0; j < i; j++) 
            {
                // Get the substring s[j...i-1]
                string temp = s.substr(j, i - j);

                // Check:
                // 1. If s[j...i-1] is in dictionary
                // 2. If s[0...j-1] can be broken correctly (t[j] == true)
                if (st.count(temp) && t[j]) 
                {
                    // If both conditions are met, then s[0...i-1] is also valid
                    t[i] = true;
                    break; // No need to check further j's for this i
                }
            }
        }

        // Final result: Can the whole string s[0...n-1] be broken?
        return t[n];
    }

    // Wrapper function
    bool wordBreak(string s, vector<string>& wordDict) {
        return solve(s, wordDict);
    }
};
