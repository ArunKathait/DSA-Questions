********************************************APPROACH 1st(USING RECURSION)*********************************

class Solution {// TC--->O(2^N)                       SC--->O(N)
public:
    // Recursive function to count subsets that have OR equal to maxOr
    int countSubsets(int index, vector<int>& nums, int curOr, int maxOr)
    {
        // Base case: if we've considered all elements
        if(index >= nums.size())
        {
            // If the OR of this subset is equal to maxOr, count it
            if(curOr == maxOr)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        // Include current element in the subset (perform OR operation)
        int pick = countSubsets(index + 1, nums, curOr | nums[index], maxOr);
        
        // Exclude current element from the subset
        int skip = countSubsets(index + 1, nums, curOr, maxOr);

        // Total ways = include + exclude
        return (pick + skip);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();

        // Calculate the maximum possible OR value from all elements
        int maxOr = 0;

        for(auto &num : nums)
        {
            // bitwise OR with each number
            maxOr |= num; 
        }
        
        // Start with 0 OR value for the subset
        int curOr = 0;

        // Start recursive function from index 0
        return countSubsets(0, nums, curOr, maxOr);
    }
};


********************************************APPROACH 2nd(USING MEMOIZATION)*************************************

class Solution {// TC--->O(n * maxOr)                     SC--->O(n * maxOr)
public:
    // Recursive function to count subsets whose OR is equal to maxOr
    // index: current index in nums array
    // curOr: OR value of the current subset being formed
    // maxOr: maximum OR value possible from any subset
    // dp: memoization table to store already computed results
    int countSubsets(int index, vector<int>& nums, int curOr, int maxOr, vector<vector<int>>& dp)
    {
        // Base case: if we've checked all elements
        if(index >= nums.size())
        {
            // If the OR value of the current subset matches maxOr, count it
            if(curOr == maxOr)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        // If result is already computed, return from dp table
        if(dp[index][curOr] != -1)
        {
            return dp[index][curOr];
        }

        // Include current element: perform OR and move to next index
        int pick = countSubsets(index + 1, nums, curOr | nums[index], maxOr, dp);
        
        // Exclude current element: keep OR as it is and move to next index
        int skip = countSubsets(index + 1, nums, curOr, maxOr, dp);

        // Store and return the total count in dp table
        return dp[index][curOr] = (pick + skip);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Calculate the maximum possible OR value of any subset
        int maxOr = 0;
        for(auto &num : nums)
        {
            // bitwise OR with each element
            maxOr |= num; 
        }

        // Step 2: Initialize a DP table with dimensions [n+1][maxOr+1]
        // dp[i][j] = number of ways to reach OR value 'j' from index i
        vector<vector<int>> dp(n + 1, vector<int>(maxOr + 1, -1));

        // Step 3: Start recursive subset count from index 0 and OR value 0
        int curOr = 0;
        return countSubsets(0, nums, curOr, maxOr, dp);
    }
};
