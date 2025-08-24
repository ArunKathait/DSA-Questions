*********************************************APPROACH 1st(USING RECURSION)*****************************************

class Solution {// TC--->O(K^N)                     SC--->O(N)
public:
    // Recursive function to calculate max sum starting from index
    int solve(int index, int n, vector<int>& arr, int k)
    {
        // Base case: if we reached or passed end of array, no contribution
        if (index >= n) 
        {
            return 0;
        }
        
        // Track max element in current partition
        int currentMax = 0;

        // Track best answer for this index
        int maxSum = 0;

        // Try all partition lengths from 1 to k
        // j is the end index of current partition
        for (int j = index; j < min(index + k, n); j++)
        {
            // Update max element of this partition
            currentMax = max(currentMax, arr[j]);

            // Partition length
            int length = j - index + 1;

            // Total = best for current partition +
            // recursive answer from next index (j+1)
            int total = (currentMax * length) + solve(j + 1, n, arr, k);

            // Maximize the answer
            maxSum = max(maxSum, total);
        }

        // Return the best possible sum starting from this index
        return maxSum;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        // Start solving from index 0
        return solve(0, n, arr, k);
    }
};

*******************************************APPROACH 2nd(USING MEMOIZATION)*************************************

class Solution {// Time Complexity ---> O(N * K)                 Space Complexity ---> O(N)
public:
    // Recursive function with memoization (Top-Down DP)
    // index → current position in the array
    // n → size of array
    // arr → input array
    // k → maximum allowed partition size
    // dp → memoization table (dp[i] stores the best answer starting at index i)
    int solve(int index, int n, vector<int>& arr, int k, vector<int>& dp)
    {
        // Base case: if index reaches or goes beyond array, no more sum
        if(index >= n)
        {
            return 0;
        }

        // If already computed, return from dp
        if(dp[index] != -1)
        {
            return dp[index];
        }
        
        int currentMax = 0;  // stores max element in current partition
        int maxSum = 0;      // stores best answer from this index

        // Try all partition sizes starting at 'index'
        // j goes from index → index+k-1 (but not beyond array length n)
        for(int j = index; j < min(index + k, n); j++)
        {
            // Update max element in this partition
            currentMax = max(currentMax, arr[j]);

            // Length of current partition = j - index + 1
            int length = j - index + 1;

            // Total sum = best for this partition + best from remaining part
            int total = (currentMax * length) + solve(j + 1, n, arr, k, dp);

            // Update the best possible sum
            maxSum = max(maxSum, total);
        }

        // Store result in dp and return
        return dp[index] = maxSum;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        // dp[i] = maximum sum possible starting from index i
        // Initialize with -1 (not computed yet)
        vector<int> dp(n + 1, -1);

        // Start solving from index 0
        return solve(0, n, arr, k, dp);
    }
};


*********************************************APPROACH 3rd(USING TABULATION)*************************************

