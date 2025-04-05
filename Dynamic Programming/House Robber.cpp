**********************************************APPROACH 1st(USING RECURSION)*******************************

class Solution {// TC--->O(2^N)                       SC--->O(N)
public:
    // Recursive function to solve the House Robber problem in a linear street
    int solve(int index,int n,vector<int>&nums)
    {
        // Base case: if index is out of bounds, return 0 (no money to rob)
        if(index >= n)
        {
            return 0;
        }

        // Option 1: Rob the current house and move to index + 2
        int take = nums[index] + solve(index + 2,n,nums);

        // Option 2: Skip the current house and move to index + 1
        int not_take = solve(index + 1,n,nums);

        // Return the maximum of robbing or skipping the current house
        return max(take,not_take);
    }

    int rob(vector<int>& nums) {
        // Total number of houses
        int n = nums.size();

        // Call the recursive solve function starting from house 0
        return solve(0,n,nums);
        
    }
};

***************************************APPROACH 2nd(USING MEMOIZATION)************************************

class Solution {// TC--->O(N)                   SC--->O(N)
public:
    // Recursive function with memoization to calculate the maximum amount that can be robbed
    int solve(int index,int n,vector<int>&nums,vector<int>&dp)
    {
        // Base case: if index goes beyond or equals total number of houses, return 0 (no money to rob)
        if(index >= n)
        {
            return 0;
        }

        // If we have already computed the result for this index, return it to avoid recomputation
        if(dp[index] != -1)
        {
            return dp[index];
        }

        // Option 1: Rob the current house and skip the next one
        int take = nums[index] + solve(index + 2,n,nums,dp);

        // Option 2: Skip the current house and check the next one
        int not_take = solve(index + 1,n,nums,dp);

        // Store the result in dp array and return the maximum of the two options
        return dp[index] = max(take,not_take);
    }

    int rob(vector<int>& nums) {
        // Total number of houses
        int n = nums.size();

        // Initialize a dp array of size 'n' with all values as -1 (meaning not yet computed)
        vector<int>dp(n,-1);

        // Call the recursive function starting from house index 0
        return solve(0,n,nums,dp);
        
    }
};

*************************************APPROACH 3rd(USING TABULATION)*****************************************

class Solution {// TC--->O(N)                              SC--->O(N)
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        // Edge case: If there's only one house, rob it and return its value
        if(n == 1)
        {
            return nums[0];
        }

        // Create a dp array of size (n + 1), initialized to -1
        // dp[i] will represent the maximum money that can be robbed from the first i houses
        vector<int>dp(n+1,-1);
 
        // Base case: robbing 0 houses → 0 money
        dp[0] = 0;

        // Base case: robbing 1st house → rob it (only option)
        dp[1] = nums[0];

        // Fill the dp array from 2 to n (1-based indexing)
        for(int i=2;i<=n;i++)
        {
            // Rob current house (i-1), skip previous
            int take = nums[i-1] + dp[i-2];

            // Don't rob current, take previous max
            int not_take = dp[i-1];

            // Take the better option
            dp[i] = max(take,not_take);
        }
      
      // The answer is stored in dp[n] — max money from robbing up to n houses
      return dp[n];
    }
};

***************************************APPROACH 4th(TABULATION--->Better then above)******************************

class Solution {// TC--->O(N)                           SC--->O(N)
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        // Edge case: If there's only one house, rob it and return its value
        if(n == 1)
        {
            return nums[0];
        }

        // Create a dp array of size 'n' to store the maximum amount that can be robbed up to each house
        vector<int>dp(n,-1);

        // Base case 1: If there's only one house, rob it
        dp[0] = nums[0];

        // Base case 2: For the second house, choose the maximum between robbing the first or second house
        dp[1] = max(nums[0],nums[1]);

        // Fill the dp array from the third house onward
        for(int i=2;i<n;i++)
        {
            // Option 1: Rob current house → add its money to dp[i-2] (because adjacent houses can't be robbed)
            // Option 2: Skip current house → take dp[i-1]
            dp[i] = max(nums[i] + dp[i-2],dp[i-1]);
        }

        // The last element of dp[] contains the maximum money that can be robbed from all houses
        return dp[n-1];    
    }
};

/*

We can also do like this in above 4th approach Tabulation
        for(int i=2;i<n;i++)
        {
            int take = nums[i] + dp[i-2];
            int not_take = dp[i-1];

            dp[i] = max(take,not_take);
        }

*/
