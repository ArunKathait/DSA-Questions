***********************************************APPROACH 1st(USING RECURSION)**************************************

class Solution {// TC ---> O(2^N)                             SC ---> O(N)
public:

    // Recursive function
    // Returns maximum jumps possible from current index
    int solve(int index, int n, vector<int>& nums, int target)
    {
        // ----------------------------------------
        // Base Case
        // ----------------------------------------

        // If we reached last index
        // No more jumps required
        if(index == n - 1)
        {
            return 0;
        }

        // Stores maximum jumps possible
        // from current index
        int ans = -1;

        // ----------------------------------------
        // Try jumping to every next index
        // ----------------------------------------

        for(int j = index + 1; j < n; j++)
        {
            // Check if jump is valid
            // Absolute difference should be <= target
            if(abs(nums[index] - nums[j]) <= target)
            {
                // Recursively calculate jumps from next index
                int temp = solve(j, n, nums, target);

                // If destination is reachable
                if(temp != -1)
                {
                    // Add current jump (+1)
                    // and maximize answer
                    ans = max(ans, 1 + temp);
                }
            }
        }

        // Return maximum jumps possible
        // from current index
        return ans;
    }

    int maximumJumps(vector<int>& nums, int target) {

        // Total size of array
        int n = nums.size();

        // Start recursion from index 0
        return solve(0, n, nums, target);
    }
};

*********************************************APPROACH 2nd(USING MEMOIZATION)****************************************

class Solution {

    // TC ---> O(N^2)
    // SC ---> O(N)

public:

    // Recursive function
    // Returns maximum jumps possible from current index
    int solve(int index, int n, vector<int>& nums, int target, vector<int>& dp)
    {
        // ----------------------------------------
        // Base Case
        // ----------------------------------------

        // If we reached last index
        // No more jumps required
        if(index == n - 1)
        {
            return 0;
        }

        // If already computed
        if(dp[index] != -2)
        {
            return dp[index];
        }

        // Stores maximum jumps possible
        // from current index
        int ans = -1;

        // ----------------------------------------
        // Try jumping to every next index
        // ----------------------------------------

        for(int j = index + 1; j < n; j++)
        {
            // Check if jump is valid
            if(abs(nums[index] - nums[j]) <= target)
            {
                // Recursively calculate answer
                int temp = solve(j, n, nums, target, dp);

                // If destination reachable
                if(temp != -1)
                {
                    // Add current jump
                    ans = max(ans, 1 + temp);
                }
            }
        }

        // Store and return answer
        return dp[index] = ans;
    }

    int maximumJumps(vector<int>& nums, int target) {

        int n = nums.size();

        // -2 means unvisited
        // -1 means impossible
        vector<int> dp(n + 1, -2);

        // Start recursion from index 0
        return solve(0, n, nums, target, dp);
    }
};

**********************************************APPROACH 3rd(TABULATION)**********************************************

class Solution {// TC ---> O(N^2)                                   SC ---> O(N)

public:

    int maximumJumps(vector<int>& nums, int target) {

        // Total number of elements
        int n = nums.size();

        // ------------------------------------------------
        // dp[i] = maximum jumps needed
        // to reach last index starting from index i
        //
        // -1 means unreachable
        // ------------------------------------------------
        vector<int> dp(n, -1);

        // Last index requires 0 jumps
        // because we are already there
        dp[n - 1] = 0;

        // ------------------------------------------------
        // Traverse array from back
        // ------------------------------------------------
        for(int i = n - 2; i >= 0; i--)
        {
            // Try jumping to every next index
            for(int j = i + 1; j < n; j++)
            {
                // ------------------------------------------------
                // Check if jump is valid
                //
                // Condition:
                // abs(nums[i] - nums[j]) <= target
                // ------------------------------------------------
                if(abs(nums[i] - nums[j]) <= target)
                {
                    // ------------------------------------------------
                    // If next index can reach destination
                    // ------------------------------------------------
                    if(dp[j] != -1)
                    {
                        // Take one jump from i -> j
                        // plus remaining jumps from j
                        int temp = 1 + dp[j];

                        // Store maximum jumps possible
                        dp[i] = max(dp[i], temp);
                    }
                }
            }
        }

        // Return answer from starting index
        return dp[0];
    }
};
