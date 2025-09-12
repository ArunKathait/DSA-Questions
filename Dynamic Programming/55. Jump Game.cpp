**************************************************APPROACH 1st(USING RECURSION)**************************************

class Solution {// Time Complexity: O(2^n)                                   Space Complexity: O(n) (recursion stack)
public:

    // Recursive function to check if we can reach the last index
    bool solve(int currentIndex, int n, vector<int>& nums) {
        // Base case: If we reach or go beyond the last index, return true
        if(currentIndex >= n - 1) 
        {
            return true;
        }

        // Try all possible jumps from 1 up to nums[currentIndex]
        // nums[currentIndex] tells the maximum jump length allowed from this index
        for(int jump = 1; jump <= nums[currentIndex]; jump++) 
        {    
            // Recursively check if jumping 'jump' steps leads to a solution
            if(solve(currentIndex + jump, n, nums) == true) 
            {
                // If any jump works, return true
                return true;  
            }
        }

        // If no jump leads to the end, return false
        return false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();  // total size of the array

        // Start recursion from index 0
        return solve(0, n, nums);
    }
};

***********************************************APPROACH 2nd(USING MEMOIZATION)***************************************

class Solution {// Time Complexity: O(n^2)                              Space Complexity: O(n)
public:
    // Recursive function with memoization
    bool solve(int currentIndex, int n, vector<int>& nums, vector<int>& dp) {
        // Base case: if we reached or crossed the last index
        if (currentIndex >= n - 1) 
        {
            return true;
        }

        // If already computed, return stored result
        if (dp[currentIndex] != -1) 
        {
            return dp[currentIndex];
        }

        // Try all possible jumps from current index
        int maxJump = nums[currentIndex];
        for (int jump = 1; jump <= maxJump; jump++) 
        {
            if (solve(currentIndex + jump, n, nums, dp)) 
            {
                // store and return true
                return dp[currentIndex] = 1; 
            }
        }

        // If no jump works, store and return false
        return dp[currentIndex] = 0;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        // initialize dp with -1
        vector<int> dp(n, -1);  
        return solve(0, n, nums, dp);
    }
};

************************************************APPROACH 3rd(TABULATION)**********************************************

class Solution {// Time Complexity: O(n^2)                           Space Complexity: O(n)
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();  

        // dp[i] = true if we can reach index i from index 0
        vector<int> dp(n, false);  
        
        // We always start at index 0, so it's reachable
        dp[0] = true;  

        // Loop through all indices from 1 to n-1
        for (int i = 1; i < n; i++) 
        {
            // Check all previous indices j < i
            for (int j = i - 1; j >= 0; j--) 
            {    
                // If index j is reachable (dp[j] = true) 
                // AND from j we can jump to i (j + nums[j] >= i),
                // then mark dp[i] = true
                if (dp[j] && (j + nums[j] >= i)) 
                {
                    dp[i] = true;

                    // No need to check further previous indices
                    break;  
                }
            }
        }

        // Finally, return whether the last index is reachable
        return dp[n - 1];
    }
};

***********************************************APPROACH 4th(GREEDY)**********************************************

class Solution {// Time Complexity: O(n)                         Space Complexity: O(1)
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        // maxReach stores the farthest index we can reach so far
        int maxReach = 0;

        // Traverse each index
        for (int currentIndex = 0; currentIndex < n; currentIndex++) 
        {    
            // If the current index is beyond the farthest reachable index,
            // it means we are stuck → cannot move forward
            if (currentIndex > maxReach) 
            {
                return false;
            }

            // Update the farthest index we can reach from here
            // i + nums[i] = max jump we can make from current index
            maxReach = max(maxReach, currentIndex + nums[currentIndex]);
        }

        // If we finished the loop, it means we can always reach the last index
        return true;
    }
};
