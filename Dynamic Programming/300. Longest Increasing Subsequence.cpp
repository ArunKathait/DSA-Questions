***********************************************APPROACH 1st(USING RECURSION)******************************

class Solution {// TC--->O(2^N)                       SC--->O(N)--->Recursion Stack
public:

    // Recursive function to find the length of LIS starting from index `index`,
    // with the last element included in the LIS being at index `prevIndex`.
    // If prevIndex == -1, it means we haven't included any element yet.
    int solve(int index, int prevIndex, int n, vector<int>& nums) 
    {
        // Base case: If we reach the end of the array, no more elements can be taken.
        if (index >= n) 
        {
            return 0;
        }

        int take = 0;
        // If we can include the current element in the increasing subsequence
        if (prevIndex == -1 || nums[index] > nums[prevIndex]) 
        {
            // We include nums[index] and move to the next index,
            // updating prevIndex to current index
            take = 1 + solve(index + 1, index, n, nums);
        }

        // Option to not include the current element
        int notTake = solve(index + 1, prevIndex, n, nums);

        // Return the maximum of both choices
        return max(take, notTake);
    }

    // Main function that initializes the recursion
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        // Start the recursion from index 0 with no element included yet (-1)
        return solve(0, -1, n, nums);
    }
};


************************************************APPROACH 2nd(USING MEMOIZATION)********************************

class Solution {// TC--->O(N^2)                     SC--->O(N^2)
public:
    // Recursive function to find the length of the Longest Increasing Subsequence (LIS)
    // `index` is the current position in the array.
    // `prevIndex` is the index of the last number included in the LIS (or -1 if none taken).
    // `dp` is the memoization table to avoid recomputation.
    int solve(int index, int prevIndex, int n, vector<int>& nums, vector<vector<int>>& dp) 
    {
        // Base case: reached the end of the array
        if (index >= n) 
        {
            return 0;
        }

        // Memoization check: we only store and reuse when prevIndex is not -1
        if (prevIndex != -1 && dp[index][prevIndex] != -1) 
        {
            return dp[index][prevIndex];
        }

        int take = 0;
        // If we can take the current element (increasing condition)
        if (prevIndex == -1 || nums[index] > nums[prevIndex]) 
        {
            // Include current element and move forward
            take = 1 + solve(index + 1, index, n, nums, dp);
        }

        // Option to skip the current element
        int notTake = solve(index + 1, prevIndex, n, nums, dp);

        // If prevIndex is not -1, store the result in dp table
        if (prevIndex != -1) 
        {
            return dp[index][prevIndex] = max(take, notTake);
        }

        // If prevIndex is -1 (can't be stored in dp), return the result without memoization
        return max(take, notTake);
    }

    // Entry function to solve the problem
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        // Create dp table initialized to -1
        // dp[i][j] stores result of LIS starting from index i with previous index j
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        // Start from index 0 with no previous element included yet (-1)
        return solve(0, -1, n, nums, dp);
    }
};

******************************************************APPROACH 3rd(USING TABULATION)*************************************************************

class Solution {// TC--->O(N^2)                         SC--->O(N)
public:
    int lengthOfLIS(vector<int>& nums) {
        // Get the size of the input array
        int n = nums.size(); 

        // Initialize a DP array where dp[i] represents
        // the length of the longest increasing subsequence ending at index i.
        // Each element is initially 1 because each number is an LIS of at least length 1 by itself.
        vector<int> dp(n, 1); 
        
        // Variable to store the overall maximum LIS found.
        int maxLIS = 1; 

        // Loop through each element in the array
        for (int i = 0; i < n; i++) 
        {
            // Check all previous elements before the current element nums[i]
            for (int j = 0; j < i; j++) 
            {
                // If nums[j] < nums[i], it means we can extend the increasing subsequence ending at j
                if (nums[j] < nums[i]) 
                {
                    // Update dp[i] to be the maximum of its current value or dp[j] + 1
                    dp[i] = max(dp[i], dp[j] + 1);

                    // Update maxLIS if needed
                    maxLIS = max(maxLIS, dp[i]);
                }
            }
        }

        // Return the length of the longest increasing subsequence found
        return maxLIS;
    }
};
