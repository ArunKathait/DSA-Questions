******************************************APPROACH 1st(USING RECURSION)************************************

class Solution {// TC--->O(2^N)                                    SC--->O(N)
public:
    // Helper recursive function to find max money from index to end
    int solve(int index, int end, vector<int>& nums) {
        // Base case: if index goes beyond the end of the array, no house to rob
        if (index > end) 
        {
            return 0;
        }

        // Option 1: Rob the current house and skip the next one
        int take = nums[index] + solve(index + 2, end, nums);
        
         // Option 2: Skip the current house and move to the next one
        int not_take = solve(index + 1, end, nums);         

        // Return the maximum of taking or not taking the current house
        return max(take, not_take);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        // If there's only one house, rob it
        if (n == 1) 
        {
            return nums[0];
        }

        // If there are two houses, rob the one with more money
        if (n == 2) 
        {
            return max(nums[0], nums[1]);
        }

        // Case 1: Rob from house 0 to house n-2 (exclude last)
        int case1 = solve(0, n - 2, nums);

        // Case 2: Rob from house 1 to house n-1 (exclude first)
        int case2 = solve(1, n - 1, nums);

        // Return the maximum money you can rob from both cases
        return max(case1, case2);
    }
};


*******************************************APPROACH 2nd(USING MEMOIZATION)*********************************

class Solution {// TC--->O(N)                           SC--->O(N)
public:
    // Recursive function with memoization to calculate the max amount that can be robbed
    int solve(int index,int n,vector<int>&dp,vector<int>&nums)
    {
        // Base case: if index goes beyond bounds, return 0
        if(index > n)
        {
            return 0;
        }

        // If already computed, return from dp array
        if(dp[index] != -1)
        {
            return dp[index];
        }

        // Option 1: Rob current house and move to index+2 (since we can't rob adjacent houses)
        int take = nums[index] + solve(index+2,n,dp,nums);

        // Option 2: Skip current house and move to next one
        int not_take = solve(index+1,n,dp,nums);

        // Store and return the maximum of both choices
        return dp[index] = max(take,not_take);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();

        // Edge case 1: Only one house, rob it
        if(n == 1)
        {
            return nums[0];
        }

        // Edge case 2: Two houses, rob the one with more money
        if(n == 2)
        {
            return max(nums[0],nums[1]);
        }

        // Case 1: Consider houses from index 0 to n-2 (exclude last house)
        vector<int>dp1(n,-1);

        int case1 = solve(0,n-2,dp1,nums);

        // Case 2: Consider houses from index 1 to n-1 (exclude first house)
        vector<int>dp2(n,-1);

        int case2 = solve(1,n-1,dp2,nums);

        // Return the maximum of both cases
        return max(case1,case2);
    }
};


********************************************APPROACH 3rd(USING TABULATION)***********************************

