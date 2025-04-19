*******************************************APPROACH 1st(USING RECURSION)************************************

class Solution {// TC--->O(2^N)                               SC--->O(N)--->Recursion Stack
public: 
    // Recursive function to count decoding ways starting from a given index
    int countDecodings(int index, int length, string &s)
    {
        // Base Case: If we've reached the end of the string, it means it's a valid decoding path
        if(index == length)
        {
            return 1;
        }

        // If the current character is '0', it can't be decoded on its own
        if(s[index] == '0')
        {
            return 0;
        }

        // Take one character (s[index]) and decode it (like '1' -> 'A')
        int decodeOneChar = countDecodings(index + 1, length, s);

        // Variable to hold the result if we take two characters together
        int decodeTwoChars = 0;

        // Check if we can take two characters together (i.e., index + 1 is in bounds)
        if(index + 1 < length)
        {
            // Check if the two-digit number formed is between 10 and 26
            if(s[index] == '1' || (s[index] == '2' && s[index + 1] <= '6'))
            {
                // Take two characters and decode them (like '12' -> 'L')
                decodeTwoChars = countDecodings(index + 2, length, s);
            }
        }

        // Total ways = decoding one character + decoding two characters
        return decodeOneChar + decodeTwoChars;
    }

    int numDecodings(string s) {
        int length = s.length();

        // Start decoding from index 0
        return countDecodings(0, length, s);
    }
};


*****************************************APPROACH 2nd(USING MEMOIZATION)*****************************************

class Solution {// TC--->O(N)                                   SC--->O(N)
public:
    // Helper function to recursively count decoding ways with memoization
    int countDecodings(int index, int n, string &s, vector<int>& dp)
    {
        // Base case: if we reached the end of the string, it's a valid decoding
        if(index == n)
        {
            return 1;
        }

        // If already computed for this index, return the cached result
        if(dp[index] != -1)
        {
            return dp[index];
        }

        // If current character is '0', it can't be decoded alone → return 0
        if(s[index] == '0')
        {
            return 0;
        }

        // Decode one character (e.g., '1' -> 'A') and move to next index
        int decodeOneChar = countDecodings(index + 1, n, s, dp);

        // Initialize decodeTwoChars to 0
        int decodeTwoChars = 0;

        // If next character exists, try decoding two characters together
        if(index + 1 < n)
        {
            // Check if the 2-digit number is between 10 and 26
            if(s[index] == '1' || (s[index] == '2' && s[index + 1] <= '6'))
            {
                // Decode two characters (e.g., '12' -> 'L') and move two steps
                decodeTwoChars = countDecodings(index + 2, n, s, dp);
            }
        }

        // Store the result in dp and return the total ways
        return dp[index] = decodeOneChar + decodeTwoChars;
    }

    int numDecodings(string s) {
        int n = s.length();

        // DP array to store results of subproblems (initialized with -1)
        vector<int> dp(n, -1);

        // Start solving from index 0
        return countDecodings(0, n, s, dp);
    }
};


*****************************************APPROACH 3rd(USING TABULATION)***************************************

class Solution {// TC--->O(N)                                SC--->O(N)
public:
    int numDecodings(string s) {
        int n = s.length();

        // dp[i] stores the number of ways to decode the substring from index i to the end
        vector<int> dp(n + 1, 0);

        // Base case: an empty string has one valid decoding
        dp[n] = 1;

        // Fill the dp array from the end towards the beginning
        for (int i = n - 1; i >= 0; i--) {

            // If the current character is '0', it can't be decoded
            if (s[i] == '0') 
            {
                dp[i] = 0;
            } 
            else 
            {
                // Decode the single digit character (s[i])
                dp[i] = dp[i + 1];

                // Check if two characters (s[i] and s[i+1]) can be decoded together
                if (i + 1 < n) 
                {
                    if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')) 
                    {
                        // Add number of ways to decode remaining from i+2
                        dp[i] += dp[i + 2]; 
                    }
                }
            }
        }

        // The total number of ways to decode the entire string is stored at dp[0]
        return dp[0];
    }
};

/* 
      dp[i] = total number of ways to decode the substring starting from index i to the end of the string s.
*/
