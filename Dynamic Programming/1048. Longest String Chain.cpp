***********************************************APPROACH 1st(USING RECURSION)***************************************

class Solution {// TC--->O(NLogN + 2^N * L)                    SC--->O(N)
public:
     
    // Function to check if 'prev' is a valid predecessor of 'current'
    // A word is a predecessor if adding exactly one character anywhere makes it equal to 'current'
    bool isPredecessor(string &prev, string &current)
    {
        int M = prev.length();
        int N = current.length();

        // Predecessor must be exactly one character shorter
        if (M >= N || N - M != 1)
        {
            return false;
        }
        
        // Pointer for 'prev'
        int i = 0;

        // Pointer for 'current' 
        int j = 0; 

        // Traverse both strings
        while (i < M && j < N)
        {
            if (prev[i] == current[j])  // If characters match, move both pointers
            {
                i++;
                j++;
            }
            else  // Otherwise, skip one character in 'current' (simulate insertion)
            {
                j++;
            }
        }

        // If we managed to match all of 'prev' in 'current', return true
        return i == M;
    }

    // Recursive function to find the Longest Increasing Subsequence (LIS)-like chain
    int LIS(int index, int prevIndex, int n, vector<string>& words)
    {
        if (index >= n)
        {
            // Base case: reached the end of the list
            return 0;  
        }

        int take = 0;

        // Option 1: Take the current word if it can follow the previous word in the chain
        if (prevIndex == -1 || isPredecessor(words[prevIndex], words[index]))
        {
            // Include current word and move forward
            take = 1 + LIS(index + 1, index, n, words);
        }

        // Option 2: Skip the current word and try the next one
        int notTake = LIS(index + 1, prevIndex, n, words);

        // Return the best of the two options
        return max(take, notTake);
    }

    // Main function to find the longest possible string chain
    int longestStrChain(vector<string>& words) {
        // Number of words
        int n = words.size();  

        // Custom comparator to sort words by increasing length
        auto myComp = [](string &word1, string &word2)
        {
             return word1.length() < word2.length();
        };

        // Sort the words so that shorter words come before longer ones
        sort(words.begin(), words.end(), myComp);

        // Start recursion from the first word, no previous word (-1)
        return LIS(0, -1, n, words);
    }
};

**********************************************APPROACH 2nd(USING MEMOIZATION)*********************************

class Solution {// TC--->O(N^2 * L)                  SC--->O(N^2)
public:
    // Function to check if `prev` is a predecessor of `current`
    bool isPredecessor(string &prev, string &current) {
        int M = prev.length();
        int N = current.length();

        // A valid predecessor must be exactly one character shorter
        if (M >= N || N - M != 1) 
        {
            return false;
        }

        // Two-pointer technique to check if `prev` can become `current` by adding one char
        int i = 0, j = 0;
        while (i < M && j < N) {
            if (prev[i] == current[j]) 
            {
                i++;
                j++;
            } 
            else 
            {
                j++; // Try skipping one character in `current`
            }
        }

        // If we matched all characters of `prev`, it's a valid predecessor
        return i == M;
    }

    // Recursive function to find the longest increasing chain
    // `index` - current word index
    // `prevIndex` - index of the previous word in the chain
    // `dp` - memoization table
    int LIS(int index, int prevIndex, int n, vector<string>& words, vector<vector<int>>& dp) {
        if (index >= n) 
        {
            return 0; // Base case: no more words to process
        }

        // If result already computed (and prevIndex is valid), return it
        if (prevIndex != -1 && dp[index][prevIndex] != -1)
        {
            return dp[index][prevIndex];
        }

        int take = 0;

        // If it's the first word in the chain or the current word can follow the previous one
        if (prevIndex == -1 || isPredecessor(words[prevIndex], words[index])) {
            // Include the current word in the chain
            take = 1 + LIS(index + 1, index, n, words, dp);
        }

        // Option to skip the current word
        int notTake = LIS(index + 1, prevIndex, n, words, dp);

        // Store result in dp table only if prevIndex is valid
        if (prevIndex != -1) 
        {
            return dp[index][prevIndex] = max(take, notTake);
        }

        // If prevIndex is -1 (initial call), we can't store result in dp
        return max(take, notTake);
    }

    // Main function to find the longest string chain
    int longestStrChain(vector<string>& words) {
        int n = words.size();

        // Sort the words by length (small to large)
        auto myComp = [](string &word1, string &word2) 
        {
            return word1.length() < word2.length();
        };

        sort(words.begin(), words.end(), myComp);

        // Initialize dp table with -1 (n x n), where dp[i][j] means:
        // max chain length starting at i with previous index j
        vector<vector<int>> dp(n, vector<int>(n, -1));

        // Start the recursion from index 0 with no previous word (-1)
        return LIS(0, -1, n, words, dp);
    }
};

**********************************************APPROACH 3rd(TABULATION)***************************************

class Solution {// TC--->O(N^2 * L)                         SC--->O(N)
public:
     
    // Function to check if 'prev' is a valid predecessor of 'current'
    // A word is a predecessor if you can insert exactly one letter into it to get 'current'
    bool isPredecessor(string &prev, string &current) {
        int M = prev.length();
        int N = current.length();

        // A valid predecessor must be exactly one character shorter
        if (M >= N || N - M != 1) 
        {
            return false;
        }

        int i = 0, j = 0;
        // Use two pointers to compare characters in both strings
        while (i < M && j < N) 
        {
            if (prev[i] == current[j]) 
            {
                // If characters match, move both pointers
                i++; 
                j++; 
            } 
            else 
            {
                j++; // Skip one character in 'current' (only allowed once)
            }
        }

        // If we have checked all characters of 'prev', it's a valid predecessor
        return i == M;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        
        // Custom comparator to sort the words by increasing length
        auto myComp = [](string &word1, string &word2) 
        {
            return word1.length() < word2.length();
        };

        // Sort words by their length to ensure shorter words come before longer ones
        sort(words.begin(), words.end(), myComp);

        // dp[i] will store the length of the longest string chain ending at index i
        vector<int> dp(n, 1);

        // Stores the overall longest chain length found
        int maxLIS = 1;

        // Loop over all words
        for (int i = 0; i < n; i++) 
        {
            // Try all previous words to see if any of them is a predecessor
            for (int j = 0; j < i; j++) 
            {
                // If words[j] is a valid predecessor of words[i]
                if (isPredecessor(words[j], words[i])) 
                {
                    // Update dp[i] if taking words[j] extends the chain
                    dp[i] = max(dp[i], dp[j] + 1);

                    // Update the global maximum chain length
                    maxLIS = max(maxLIS, dp[i]);
                }
            }
        }

        // Return the longest chain length found
        return maxLIS;
    }
};
