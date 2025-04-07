*************************************************APPROACH 1st(USING RECURSION)****************************

class Solution {// TC--->O(2^N)                                 SC--->O(N)
public:
    // Recursive function to check if a subset with sum = halfSum exists
    bool solve(int index,vector<int>&nums,int halfSum)
    {
        // Base Case 1: If halfSum becomes 0, we found a valid subset
        if(halfSum == 0)
        {
            return true;
        }

        // Base Case 2: If index goes out of bounds or we cannot take more elements
        if(index >= nums.size())
        {
            return false;
        }

        // Recursive case: try including the current element
        bool take = solve(index + 1,nums,halfSum - nums[index]);

        // Recursive case: try excluding the current element
        bool notTake = solve(index + 1,nums,halfSum);

        // If any of the two choices lead to a solution, return true
        return take || notTake;
    }

    // Main function to check if array can be partitioned into two equal subsets
    bool canPartition(vector<int>& nums) {
        // Number of elements in array
        int n = nums.size();

        int sum = 0;

        // Calculate total sum of the array
        for(auto &x:nums)
        {
            sum += x;
        }
        
        // If total sum is odd, it cannot be divided into two equal parts
        if(sum%2 != 0)
        {
            return false;
        }

        // Target sum for one subset
        int halfSum = sum/2;

        // Call the recursive function starting from index 0
        return solve(0,nums,halfSum);
        
    }
};


*****************************************APPROACH 2nd(USING MEMOIZATION)***************************************

class Solution {// TC--->O(N * sum/2)                              SC--->O(N * sum/2)
public:
    // Recursive helper function that checks if a subset starting from "index"
    // can sum up to "halfSum". The "dp" table caches results for subproblems.
    bool solve(int index,int n,vector<int>&nums,int halfSum,vector<vector<int>>&dp)
    {
        // Base Case: If we've reached exactly 0, we've found a valid subset
        if(halfSum == 0)
        {
            return true;
        }

        // Base Case: If we have no more elements to process or halfSum goes negative,
        // no valid subset can be found in this branch.        
        if(index >= n || halfSum < 0)
        {
            return false;
        }

        // Check if the current state (index, halfSum) has already been computed.
        if(dp[index][halfSum] != -1)
        {
            return dp[index][halfSum];
        }

        // Recursive case: decide to "take" the current element.
        // Subtract its value from halfSum and move to the next index.
        bool take = solve(index + 1,n,nums,halfSum - nums[index],dp);

        // Recursive case: decide to "not take" the current element.
        // Keep halfSum as is and move to the next index.
        bool notTake = solve(index + 1,n,nums,halfSum,dp);

        // Save and return the result for the current state.
        // The state is true if either taking or not taking the current element leads to a solution.
        return dp[index][halfSum] = (take || notTake);
    }

    // Main function to determine if the array can be partitioned into two subsets of equal sum.
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        // Calculate the total sum of the array.
        int sum = accumulate(nums.begin(),nums.end(),0);

        // If the total sum is odd, it's impossible to split into two equal subsets.
        if(sum % 2 != 0)
        {
            return false;
        }

        // Our target is half of the total sum.
        int halfSum = sum/2;

        // Initialize a DP table of size (n+1) x (halfSum+1) with -1.
        // dp[i][j] will store whether it's possible to get sum "j" starting from index "i".
        vector<vector<int>>dp(n + 1,vector<int>(halfSum + 1,-1));

        // Start the recursion from index 0.
        return solve(0,n,nums,halfSum,dp);

    }
};
