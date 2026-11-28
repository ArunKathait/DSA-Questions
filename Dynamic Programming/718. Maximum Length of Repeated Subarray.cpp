************************************************APPROACH 1st(MEMOIZATION)**********************************************

class Solution {// Time Complexity: O(n * m)              Total Space: O(n * m)
public:
    int solve(int i, int j, int n, int m, vector<int>& nums1, vector<int>& nums2,
              vector<vector<int>>& dp, int &ans)
    {
        // If either array goes out of bounds, no more elements can match
        if(i >= n || j >= m)
        {
            return 0;
        }

        // If this state is already calculated, return the stored result
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        // Check whether current elements of both arrays are equal
        if(nums1[i] == nums2[j])
        {
            // If they match, move diagonally to the next indices
            // and increase the common subarray length by 1
            int length = 1 + solve(i + 1, j + 1, n, m, nums1, nums2, dp, ans);

            // Update the maximum common subarray length found so far
            ans = max(ans, length);

            // Store the calculated length in the DP table
            return dp[i][j] = length;
        }
        else
        {
            // If elements don't match, the continuous subarray breaks
            // Therefore, common subarray length starting here is 0
            return dp[i][j] = 0;
        }
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        // DP table initialized with -1 (unvisited states)
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        // Stores the maximum common subarray length
        int ans = 0;

        // Try every possible starting index in nums1
        for(int i = 0; i < n; i++)
        {
            // Try every possible starting index in nums2
            for(int j = 0; j < m; j++)
            {
                // Calculate the common subarray length
                // starting from the pair of indices (i, j)
                solve(i, j, n, m, nums1, nums2, dp, ans);
            }
        }

        // Return the maximum common subarray length
        return ans;
    }
};

/*

┌──────────────────────────────────────────────┐
│ Maximum Length of Repeated Subarray          │
├──────────────────────────────────────────────┤
│ Approach: Recursion + Memoization            │
│                                              │
│ DP State:                                    │
│ dp[i][j] = Common subarray length starting   │
│ at nums1[i] and nums2[j].                    │
│                                              │
│ Base Case:                                   │
│ If i >= n || j >= m, return 0.               │
│                                              │
│ Match:                                       │
│ dp[i][j] = 1 + solve(i+1, j+1)               │
│                                              │
│ Mismatch:                                    │
│ dp[i][j] = 0                                 │
│                                              │
│ 1. Initialize DP table with -1.              │
│ 2. Check if dp[i][j] is already calculated.  │
│ 3. If elements match, move diagonally.       │
│ 4. Update ans with maximum length.           │
│ 5. Try all starting index pairs using loops. │
│                                              │
│ Time Complexity:  O(n * m)                   │
│ DP Space:         O(n * m)                   │
│ Recursion Stack:  O(min(n, m))               │
│ Total Space:      O(n * m)                   │
└──────────────────────────────────────────────┘

*/

***********************************************APPROACH 2nd(TABULATION)************************************************

class Solution {// Time Complexity: O(n * m)            Space: O(n * m)
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {

        // Get the sizes of both arrays
        int n = nums1.size();
        int m = nums2.size();

        // Stores the maximum length of the common subarray
        int ans = 0;

        // dp[i][j] represents the length of the common
        // contiguous subarray starting at nums1[i] and nums2[j].
        //
        // Initialize with 0 because if either index goes
        // out of bounds, the common subarray length is 0.
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Traverse nums1 from right to left
        for(int i = n - 1; i >= 0; i--)
        {
            // Traverse nums2 from right to left
            for(int j = m - 1; j >= 0; j--)
            {
                // If the current elements are equal,
                // we can extend the common subarray.
                if(nums1[i] == nums2[j])
                {
                    // Add 1 for the current matching element
                    // and extend using the next diagonal cell.
                    dp[i][j] = 1 + dp[i + 1][j + 1];

                    // Update the maximum common subarray length
                    ans = max(ans, dp[i][j]);
                }
                else
                {
                    // Since this is a contiguous subarray,
                    // a mismatch breaks the current sequence.
                    dp[i][j] = 0;
                }
            }
        }

        // Return the maximum length found
        return ans;
    }
};

/*

┌──────────────────────────────────────────────┐
│ Maximum Length of Repeated Subarray          │
├──────────────────────────────────────────────┤
│ Approach: Bottom-Up DP (Tabulation)          │
│                                              │
│ DP State:                                    │
│ dp[i][j] = Length of common contiguous       │
│ subarray starting at nums1[i] and nums2[j].  │
│                                              │
│ Base Case:                                   │
│ Initialize the entire DP table with 0.       │
│                                              │
│ Transition:                                  │
│ If nums1[i] == nums2[j]:                     │
│    dp[i][j] = 1 + dp[i+1][j+1]               │
│ Else:                                        │
│    dp[i][j] = 0                              │
│                                              │
│ Key Idea:                                    │
│ 1. Traverse both arrays backwards.           │
│ 2. Extend the match diagonally if equal.     │
│ 3. Reset to 0 on mismatch (contiguous rule). │
│ 4. Update ans with the maximum DP value.     │
│                                              │
│ Time Complexity:  O(n * m)                   │
│ DP Space:         O(n * m)                   │
│ Auxiliary Space:  O(1)                       │
└──────────────────────────────────────────────┘

*/
