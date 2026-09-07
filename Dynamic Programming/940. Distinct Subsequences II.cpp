************************************************APPROACH 1st(MEMOIZATION)**********************************************

class Solution {// Time  : O(n)                       Space : O(n)  
public:

    // Modulo value
    int M = 1e9 + 7;

    // dp[n] = number of distinct subsequences
    // using first n characters
    int dp[2001];

    // prev[i] = previous position of s[i-1]
    vector<int> prev;


    int solve(int n)
    {
        // Empty subsequence
        if(n == 0)
        {
            return 1;
        }

        // Return already calculated result
        if(dp[n] != -1)
        {
            return dp[n];
        }

        /*
            For current character:

            1. Don't include it
            2. Include it

            So initially we get 2 * solve(n-1)
        */
        int total = (2 * solve(n - 1)) % M;


        /*
            If current character appeared before,
            some subsequences are duplicates.

            Remove those duplicate subsequences.
        */
        if(prev[n] != 0)
        {
            // Subsequences before previous occurrence
            int duplicates = solve(prev[n] - 1);

            total = (total - duplicates + M) % M;
        }

        // Store and return answer
        return dp[n] = total;
    }


    int distinctSubseqII(string s)
    {
        int n = s.length();

        // Initialize DP with -1
        memset(dp, -1, sizeof(dp));

        // prev[1...n]
        prev.assign(n + 1, 0);

        // Last position of each character
        vector<int> lastSeen(26, 0);


        /*
            Find previous occurrence of every character.

            Example:
            s = "aba"

            prev[1] = 0
            prev[2] = 0
            prev[3] = 1
        */
        for(int i = 1; i <= n; i++)
        {
            // Convert 'a'...'z' to 0...25
            int index = s[i - 1] - 'a';

            // Previous occurrence
            prev[i] = lastSeen[index];

            // Update latest occurrence
            lastSeen[index] = i;
        }


        /*
            solve(n) includes the empty subsequence.

            Problem wants only non-empty subsequences,
            so subtract 1.
        */
        return (solve(n) - 1 + M) % M;
    }
};

********************************************APPROACH 2nd(TABULATION)*************************************************

class Solution {// Time: O(n)                         Space: O(n)
public:

    // Modulo value to avoid integer overflow
    int M = 1e9 + 7;

    // dp[i] = number of distinct subsequences
    // using the first i characters
    int dp[2001];

    // prev[i] = previous position where s[i-1] appeared
    vector<int> prev;


    int distinctSubseqII(string s) {

        int n = s.length();

        // Create prev array of size n+1
        // Position 0 is unused
        prev.assign(n + 1, 0);


        // lastSeen[c] = latest position of character c
        // There are only 26 lowercase English letters
        vector<int> lastSeen(26, 0);


        // Find previous occurrence of every character
        for(int i = 1; i <= n; i++)
        {
            // Convert character into index 0 to 25
            int index = s[i - 1] - 'a';

            // Store where this character appeared previously
            // 0 means this is its first occurrence
            prev[i] = lastSeen[index];

            // Update latest position of this character
            lastSeen[index] = i;
        }


        // Empty subsequence is counted
        dp[0] = 1;


        // Calculate number of distinct subsequences
        // using first i characters
        for(int i = 1; i <= n; i++)
        {
            /*
                For the current character we have 2 choices:

                1. Don't take current character
                2. Take current character

                Therefore:
                total = 2 * dp[i-1]
            */
            int total = (2 * dp[i - 1]) % M;


            /*
                If current character appeared before,
                some subsequences will be duplicates.

                prev[i] gives the previous occurrence.
            */
            if(prev[i] != 0)
            {
                // Count subsequences before previous occurrence
                int duplicates = dp[prev[i] - 1];

                // Remove duplicate subsequences
                total = (total - duplicates + M) % M;
            }


            // Store answer for first i characters
            dp[i] = total;
        }


        /*
            dp[n] includes the empty subsequence.

            Problem asks for non-empty subsequences,
            so subtract 1.
        */
        return (dp[n] - 1 + M) % M;
    }
};

/*

  The main idea

For every character:

                    Current character
                           |
                ┌──────────┴──────────┐
                ↓                     ↓
              Skip                  Take
                └──────────┬──────────┘
                           ↓
                    2 × dp[i-1]
                           |
                    Did it appear
                       before?
                     /         \
                   Yes          No
                    ↓            ↓
              Remove duplicate   Done

┌──────────────────────────────────────────────┐
│       DISTINCT SUBSEQUENCES II — 940         │
├──────────────────────────────────────────────┤
│ Pattern: String + DP + Last Occurrence       │
│                                              │
│ dp[i] = distinct subsequences using          │
│         first i characters                   │
│                                              │
│ dp[0] = 1                                    │
│ → empty subsequence                          │
│                                              │
│ For every character:                         │
│                                              │
│ 1. Take / Skip current char                  │
│    total = 2 × dp[i-1]                       │
│                                              │
│ 2. If char appeared before:                  │
│    duplicates = dp[prev[i]-1]                │
│                                              │
│    total -= duplicates                       │
│                                              │
│ Formula:                                     │
│ dp[i] = 2 × dp[i-1]                          │
│         - dp[prev[i]-1]                      │
│                                              │
│ prev[i] = previous occurrence of s[i-1]      │
│                                              │
│ lastSeen[char] = latest position             │
│                                              │
│ Final:                                       │
│ dp[n] - 1                                    │
│ → remove empty subsequence                   │
│                                              │
│ Time  : O(n)                                 │
│ Space : O(n)                                 │
└──────────────────────────────────────────────┘

*/
