***********************************************APPROACH 1st(USING RECURSION)*********************************

class Solution {// TC--->O(3^(N + M))                               SC--->O(N + M)
public:
    // A helper function that recursively calculates the minimum number of operations
    // required to convert word1[i:] to word2[j:]
    int solve(int i,int j,int n,int m,string &word1,string &word2)
    {
        // Base Case 1: If we reach the end of word1, we need to insert the remaining characters of word2
        if(i == n)
        {
            return m - j;
        }

        // Base Case 2: If we reach the end of word2, we need to delete the remaining characters of word1
        if(j == m)
        {
            return n - i;
        }

        // If characters at current positions are equal, move to next characters in both strings
        if(word1[i] == word2[j])
        {
            return solve(i + 1,j + 1,n,m,word1,word2);
        }
 
        // If characters are different, consider all three operations:

        // 1. Insert a character into word1 -> Move forward in word2
        int insertOperation = 1 + solve(i,j + 1,n,m,word1,word2);

        // 2. Delete a character from word1 -> Move forward in word1
        int deleteOperation = 1 + solve(i + 1,j,n,m,word1,word2);

        // 3. Replace character in word1 with word2[j] -> Move forward in both strings
        int replaceOperation = 1 + solve(i + 1,j + 1,n,m,word1,word2);

        // Return the minimum of the three operations
        return min({insertOperation,deleteOperation,replaceOperation});
    }

    // Main function that initializes the recursive process
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // Start recursion from index 0 of both words
        return solve(0,0,n,m,word1,word2);
        
    }
};

****************************************APPROACH 2nd(USING MEMOIZATION)*****************************************

// NOTE : Here we are starting from (0,0)index(i.e Left to Right Traversal) of both strings. 

class Solution {// TC--->O(N * M)                              SC--->O(N * M)
public:
    // Recursive function with memoization to calculate edit distance
    int solve(int i, int j, int n, int m, string &word1, string &word2, vector<vector<int>> &dp)
    {
        // If word1 is fully traversed, insert all remaining characters of word2
        if (i == n) {
            return m - j;
        }

        // If word2 is fully traversed, delete all remaining characters of word1
        if (j == m) {
            return n - i;
        }

        // If the result for current state is already calculated, return it (Memoization)
        if (dp[i][j] != -1) 
        {
            return dp[i][j];
        }

        // If characters match, move to next characters in both strings
        if (word1[i] == word2[j]) 
        {
            return dp[i][j] = solve(i + 1, j + 1, n, m, word1, word2, dp);
        }

        // If characters do not match, consider all 3 operations:
        
        // 1. Insert: pretend to insert word2[j] into word1 at i
        int insertOperation = 1 + solve(i, j + 1, n, m, word1, word2, dp);

        // 2. Delete: delete word1[i] and move forward in word1
        int deleteOperation = 1 + solve(i + 1, j, n, m, word1, word2, dp);

        // 3. Replace: replace word1[i] with word2[j] and move forward in both
        int replaceOperation = 1 + solve(i + 1, j + 1, n, m, word1, word2, dp);

        // Store and return the minimum of the three operations
        return dp[i][j] = min({insertOperation, deleteOperation, replaceOperation});
    }

    // Main function
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        // Initialize DP table with -1 (unvisited states)
        vector<vector<int>> dp(n, vector<int>(m, -1));

        // Start solving from the beginning of both strings
        return solve(0, 0, n, m, word1, word2, dp);
    }
};

*****************************************APPROACH 3rd(USING index(n,m))***************************************

// NOTE : Here we are traversing from index(n,m)(i.e Right To Left Traversal) of both strings.

class Solution {// TC--->O(N*M)                                     SC--->O(N*M)
public:

    // Recursive function with memoization to calculate the minimum edit distance
    int solve(int n, int m, string &word1, string &word2, vector<vector<int>> &dp)
    {
        // Base Case 1: If word1 is empty, we need to insert all remaining characters of word2
        if(n == 0)
        {
            return m;
        }

        // Base Case 2: If word2 is empty, we need to delete all remaining characters of word1
        if(m == 0)
        {
            return n;
        }

        // If already computed for state (n, m), return stored result to avoid recomputation
        if(dp[n][m] != -1)
        {
            return dp[n][m];
        }

        // If current characters are the same, move both pointers back without any cost
        if(word1[n - 1] == word2[m - 1])
        {
            return dp[n][m] = solve(n - 1, m - 1, word1, word2, dp);
        }

        // Otherwise, try all three operations and take the minimum

        // 1. Insert word2[m-1] into word1 → move j (m) back by 1
        int insertOperation = 1 + solve(n, m - 1, word1, word2, dp);

        // 2. Delete word1[n-1] → move i (n) back by 1
        int deleteOperation = 1 + solve(n - 1, m, word1, word2, dp);

        // 3. Replace word1[n-1] with word2[m-1] → move both back by 1
        int replaceOperation = 1 + solve(n - 1, m - 1, word1, word2, dp);

        // Store and return the minimum of the three operations
        return dp[n][m] = min({insertOperation, deleteOperation, replaceOperation});
    }

    // Main function to be called
    int minDistance(string word1, string word2) {
        int n = word1.length(); // Length of first word
        int m = word2.length(); // Length of second word

        // DP table initialized with -1 to indicate uncomputed states
        // Size is (n+1) x (m+1) to include base cases for empty strings
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        // Start solving from full length of both strings
        return solve(n, m, word1, word2, dp);
    }
};


******************************************APPROACH 4th(USING TABULATION)************************************

class Solution {// TC--->O(N*M)                         SC--->O(N*M)
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        // Create a 2D DP table of size (n+1) x (m+1)
        // dp[i][j] will store the minimum number of operations
        // required to convert word1[0..i-1] to word2[0..j-1]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Base case: converting word1[0..i-1] to an empty string
        // requires i deletions
        for (int row = 0; row <= n; row++) 
        {
            dp[row][0] = row;
        }

        // Base case: converting an empty string to word2[0..j-1]
        // requires j insertions
        for (int col = 0; col <= m; col++) 
        {
            dp[0][col] = col;
        }

        // Fill the DP table
        for (int i = 1; i <= n; i++) 
        {
            for (int j = 1; j <= m; j++) 
            {
                // If current characters match, no operation needed
                if (word1[i - 1] == word2[j - 1]) 
                {
                    dp[i][j] = dp[i - 1][j - 1];
                } 
                else 
                {
                    // Otherwise, take the minimum of the three operations:

                    // Insert: insert word2[j-1] into word1
                    // So, we move j back (because we handled word2[j-1])
                    int insertOperation = 1 + dp[i][j - 1];

                    // Replace: replace word1[i-1] with word2[j-1]
                    // So, both i and j move back
                    int replaceOperation = 1 + dp[i - 1][j - 1];

                    // Delete: delete word1[i-1]
                    // So, i moves back
                    int deleteOperation = 1 + dp[i - 1][j];

                    // Take the minimum of the three options
                    dp[i][j] = min({insertOperation, deleteOperation, replaceOperation});
                }
            }
        }

        // Final answer is the minimum operations to convert full word1 to word2
        return dp[n][m];
    }
};

********************************************************APPROACH 5th(TABULATION MINOR CHANGE)******************************

class Solution {
  public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        
        // dp[i][j] = minimum operations to convert word1[0..i-1] to word2[0..j-1]
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        // Fill DP table bottom-up
        for(int i = 0; i <= n; i++) 
        {
            for(int j = 0; j <= m; j++) 
            {
                // Base case: first string is empty → need j insertions
                if(i == 0) 
                {
                    dp[i][j] = j;
                }
                // Base case: second string is empty → need i deletions
                else if(j == 0) 
                {
                    dp[i][j] = i;
                }
                // If last characters match → no operation needed
                else if(word1[i-1] == word2[j-1]) 
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                // If characters differ → consider insert, delete, replace
                else 
                {
                    int insertOp = 1 + dp[i][j-1];    // Insert last char of word2
                    int deleteOp = 1 + dp[i-1][j];    // Delete last char of word1
                    int replaceOp = 1 + dp[i-1][j-1]; // Replace last char

                    dp[i][j] = min(insertOp, min(deleteOp, replaceOp));
                }
            }
        }

        // dp[n][m] = minimum operations to convert word1 → word2
        return dp[n][m];
    }
};
