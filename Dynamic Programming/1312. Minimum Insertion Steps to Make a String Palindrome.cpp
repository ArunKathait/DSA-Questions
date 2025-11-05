********************************************APPROACH 1st(USING RECURSION)*********************************************

class Solution {// TC ---> O(2^N)                           SC ---> O(N)
public:
    // Recursive helper function to find the minimum number of insertions 
    // needed to make the substring s[left...right] a palindrome.
    int solve(int left, int right, string &s)
    {
        // ✅ Base case 1:
        // When left >= right, the substring is either empty or a single character.
        // Both are already palindromes, so no insertion is needed.
        if (left >= right)
        {
            return 0;
        }

        // ✅ Case 2:
        // If characters at both ends are equal, 
        // we don't need any insertion for these two characters.
        // Just check the inner substring.
        if (s[left] == s[right])
        {
            return solve(left + 1, right - 1, s);
        }

        // ✅ Case 3:
        // If characters don't match, we have two choices:
        // 1️⃣ Insert a character matching s[right] at the left side
        //     → move left pointer ahead, keep right same.
        // 2️⃣ Insert a character matching s[left] at the right side
        //     → move right pointer backward, keep left same.
        // We add +1 for the insertion and take the minimum of both cases.
        int leftInsert = 1 + solve(left, right - 1, s);
        int rightInsert = 1 + solve(left + 1, right, s);

        // Return the minimum insertions required between both choices.
        return min(leftInsert, rightInsert);
    }

    // Main function
    int minInsertions(string s)
    {
        int n = s.length();

        // Start recursion from both ends of the string
        return solve(0, n - 1, s);
    }
};

********************************************APPROACH 2nd(USING MEMOIZATION)*******************************************

class Solution {  // TC → O(N²) , SC → O(N²) because of DP table and recursion stack
public:
    // Recursive helper function
    // Parameters:
    // left  → starting index of substring
    // right → ending index of substring
    // s     → input string
    // dp    → memoization table (stores already computed results)
    int solve(int left, int right, string &s, vector<vector<int>> &dp)
    {
        // ✅ Base Case 1:
        // If left >= right, substring is either empty or a single character.
        // Both are palindromes by definition → no insertions needed.
        if (left >= right)
        {
            return 0;
        }

        // ✅ Base Case 2 (Memoization):
        // If this subproblem was already solved before, return its stored answer.
        if (dp[left][right] != -1)
        {
            return dp[left][right];
        }

        // ✅ Case 3:
        // If the characters at both ends are equal,
        // we don’t need to insert anything for them.
        // We just check for the inner substring (left+1 to right-1).
        if (s[left] == s[right])
        {
            return dp[left][right] = solve(left + 1, right - 1, s, dp);
        }

        // ✅ Case 4:
        // Characters don't match — we have two possible choices:

        // 1️⃣ Insert a character equal to s[right] before s[left].
        //    That means we move the right boundary one step left.
        int leftInsert = 1 + solve(left, right - 1, s, dp);

        // 2️⃣ Insert a character equal to s[left] after s[right].
        //    That means we move the left boundary one step right.
        int rightInsert = 1 + solve(left + 1, right, s, dp);

        // ✅ Take the minimum of both choices
        // and store the result in dp table before returning.
        return dp[left][right] = min(leftInsert, rightInsert);
    }

    // 🚀 Main function
    int minInsertions(string s)
    {
        // Get the length of the string
        int n = s.length();  

        // Create DP table of size n x n initialized with -1
        // dp[i][j] will store minimum insertions needed for substring s[i...j]
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        // Start recursion for the whole string: from index 0 to n-1
        return solve(0, n - 1, s, dp);
    }
};

*********************************************APPROACH 3rd(USING TABULATION)************************************

class Solution {
public:
    int minInsertions(string s) {// TC ---> O(N^2)                           SC ---> O(N^2)
        int n = s.length();

        // ✅ Step 1: Create a 2D DP table
        // dp[i][j] will store the minimum number of insertions 
        // required to make the substring s[i...j] a palindrome.
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        // ✅ Step 2: Fill the table for substrings of increasing lengths
        // length = 2 means substrings of size 2, then 3, and so on...
        for (int length = 2; length <= n; length++) 
        {    
            // i is the starting index of the substring
            for (int i = 0; i + length - 1 < n; i++) {

                // j is the ending index of the substring
                int j = i + length - 1;

                // ✅ Case 1: If both characters are the same,
                // no insertion is required for these two characters.
                // Just take the result of the inner substring (i+1, j-1).
                if (s[i] == s[j]) 
                {
                    dp[i][j] = dp[i + 1][j - 1];
                }

                // ✅ Case 2: If characters differ,
                // we must insert one character — either match s[i] or s[j].
                // 1 + min(inserting on left side, inserting on right side)
                else 
                {
                    dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        // ✅ Step 3: dp[0][n-1] contains the result for the full string
        return dp[0][n - 1];
    }
};
