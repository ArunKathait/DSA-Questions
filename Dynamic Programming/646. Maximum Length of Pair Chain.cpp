*************************************************APPROACH 1st(USING RECURSION)***********************************

class Solution {// TC--->O(2^N)                    SC--->O(N)--->Recursion Stack
public:
    // Recursive function to find the maximum length of a chain
    // index: current position in the pairs list
    // prevIndex: index of the last pair included in the chain
    // n: total number of pairs
    // pairs: vector of pairs
    int solve(int index, int prevIndex, int n, vector<vector<int>>& pairs) {
        // Base case: If we've considered all pairs, return 0
        if (index >= n) 
        {
            return 0;
        }

        int take = 0;

        // If no previous pair is selected (prevIndex == -1),
        // or the current pair can follow the previous pair in the chain
        // i.e., the end of the previous pair is less than the start of the current pair
        if (prevIndex == -1 || pairs[prevIndex][1] < pairs[index][0]) 
        {
            // Include the current pair in the chain and move to the next index
            take = 1 + solve(index + 1, index, n, pairs);
        }

        // Skip the current pair and move to the next index
        int notTake = solve(index + 1, prevIndex, n, pairs);

        // Return the maximum of including or excluding the current pair
        return max(take, notTake);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        // Sort the pairs by their first element to ensure consistent ordering
        // This helps in correctly forming chains
        sort(pairs.begin(), pairs.end());

        // Start recursion from index 0 and no previous pair selected (-1)
        return solve(0, -1, n, pairs);
    }
};

***********************************************APPROACH 2nd(USING MEMOIZATION)***********************************

class Solution {// TC--->O(N^2)                      SC--->O(N^2)
public:
    // Recursive function with memoization to find the longest chain
    // index: current index in the pairs list
    // prevIndex: index of the previous pair included in the chain
    // n: total number of pairs
    // pairs: vector of pairs
    // dp: 2D memoization table to store intermediate results
    int solve(int index, int prevIndex, int n, vector<vector<int>>& pairs, vector<vector<int>>& dp)
    {
        // Base case: if all pairs have been considered
        if(index >= n) 
        {
            return 0;
        }

        // If result is already computed and cached (for valid prevIndex), return it
        if(prevIndex != -1 && dp[index][prevIndex] != -1) 
        {
            return dp[index][prevIndex];
        }

        int take = 0;

        // If there's no previous pair, or if the current pair can follow the previous one
        if(prevIndex == -1 || pairs[prevIndex][1] < pairs[index][0]) 
        {
            // Take the current pair and recursively call for the next index
            take = 1 + solve(index + 1, index, n, pairs, dp);
        }

        // Skip the current pair and move to the next index
        int notTake = solve(index + 1, prevIndex, n, pairs, dp);
        
        // Store and return the maximum of taking or not taking the current pair
        if(prevIndex != -1) 
        {
            return dp[index][prevIndex] = max(take, notTake);
        }

        // If prevIndex is -1 (no previous pair), we can't store in dp table (invalid index), just return the result
        return max(take, notTake);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        // Sort the pairs based on the starting element to simplify chaining logic
        sort(pairs.begin(), pairs.end());

        // Initialize DP table with -1 (indicating uncomputed states)
        // dp[i][j] stores result for current index i and previous index j
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        // Start solving from index 0 and no previous pair selected (-1)
        return solve(0, -1, n, pairs, dp);
    }
};

*******************************************APPROACH 3rd(USING TABULATION)****************************************

class Solution {// TC--->O(N^2)                             SC--->O(N)
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        // Step 1: Sort the pairs by their first element to maintain consistent order
        sort(pairs.begin(), pairs.end());

        // Step 2: Initialize DP array where dp[i] represents
        // the length of the longest chain ending at index i
        vector<int> dp(n, 1); // Each pair can at least be a chain of length 1 by itself

        int maxLIS = 1; // To keep track of the overall maximum chain length

        // Step 3: Apply a nested loop similar to LIS
        for(int i = 0; i < n; i++) 
        {
            for(int j = 0; j < i; j++) 
            {
                // If the j-th pair can be chained to the i-th pair
                if(pairs[j][1] < pairs[i][0]) 
                {
                    // Update the DP value for i
                    dp[i] = max(dp[i], 1 + dp[j]);

                    // Update the global maximum chain length
                    maxLIS = max(maxLIS, dp[i]);
                }
            }
        }

        // Step 4: Return the maximum chain length
        return maxLIS;
    }
};

***********************************************APPROACH 4th(GREEDY)****************************************

class Solution {// TC--->O(NlogN)                      SC--->O(1)
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        // Step 1: Sort the pairs by their second element (end of the pair) using a lambda function.
        // This ensures we always choose the pair that finishes the earliest,
        // leaving the maximum possible space for the next pair.
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) 
        {
            return a[1] < b[1];  // Compare based on the second element of each pair (end time)
        });
        
        // Variable to track the end of the last selected pair
        int currentEnd = INT_MIN; 

        // Variable to count the maximum length of the chain 
        int count = 0;             

        // Step 2: Iterate through the sorted pairs
        for (auto &pair : pairs) 
        {
            // If the current pair's start value is greater than the end of the last selected pair
            if (currentEnd < pair[0]) 
            {
                count++;               // Increment the chain length
                currentEnd = pair[1];  // Update the end to the current pair's end
            }
            // If the current pair can't follow the previous one, we skip it
        }

        // Step 3: Return the length of the longest chain formed
        return count;
    }
};
