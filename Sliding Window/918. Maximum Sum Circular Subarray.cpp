****************************************************APPROACH 1st*********************************************************

class Solution {// TC ---> O(N)                                           SC ---> O(1)
public:

    // ---------- Standard Kadane's Algorithm ----------
    // Finds the maximum subarray sum in a NORMAL (non-circular) array
    int maxKadaneAlgo(vector<int>& nums, int n)
    {
        // Initialize current sum and max sum with first element
        int sum = nums[0];
        int maxSum = nums[0];

        // Traverse remaining elements
        for(int i = 1; i < n; i++)
        {
            // Either extend the previous subarray OR start a new subarray
            sum = max(sum + nums[i], nums[i]);

            // Update the maximum subarray sum found so far
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }

    // ---------- Modified Kadane's Algorithm ----------
    // Finds the minimum subarray sum in the array
    // Used to calculate circular subarray sum
    int minKadaneAlgo(vector<int>& nums, int n)
    {
        // Initialize current sum and min sum with first element
        int sum = nums[0];
        int minSum = nums[0];

        // Traverse remaining elements
        for(int i = 1; i < n; i++)
        {
            // Either extend the previous subarray OR start a new subarray
            sum = min(sum + nums[i], nums[i]);

            // Update the minimum subarray sum found so far
            minSum = min(minSum, sum);
        }

        return minSum;
    }

    // ---------- Main Function ----------
    int maxSubarraySumCircular(vector<int>& nums) {

        int n = nums.size();

        // Step 1: Find total sum of the array
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // Step 2: Find minimum subarray sum (for circular case)
        int minSum = minKadaneAlgo(nums, n);

        // Step 3: Find maximum subarray sum (normal Kadane)
        int maxSum = maxKadaneAlgo(nums, n);

        // Step 4: Calculate circular subarray sum
        // Circular max sum = total sum - minimum subarray sum
        int circularSum = totalSum - minSum;

        // Step 5: Handle all-negative case
        // If all elements are negative, circularSum becomes 0 (invalid)
        if (maxSum > 0)
        {
            // Return maximum of normal max sum and circular max sum
            return max(maxSum, circularSum);
        }

        // If all elements are negative, return the maximum element
        return maxSum;
    }
};


**************************************************APPROACH 2nd(SAME LOGIC BUT DIFFERENT KADANE STYLE)*********************

class Solution {// TC ---> O(N)                              SC ---> O(1)
public:

    // -------- Kadane's Algorithm (Maximum Subarray Sum) --------
    int maxKadaneAlgo(vector<int>& nums, int n)
    {
        int sum = 0;          // Stores running sum of current subarray
        int ans = INT_MIN;    // Stores maximum subarray sum found so far

        for(int i = 0; i < n; i++)
        {
            // Add current element to running sum
            sum += nums[i];

            // Update answer with the maximum sum so far
            ans = max(ans, sum);

            // If running sum becomes negative,
            // discard this subarray and start fresh
            if(sum < 0)
            {
                sum = 0;
            }
        }

        return ans;
    }

    // -------- Modified Kadane's Algorithm (Minimum Subarray Sum) --------
    int minKadaneAlgo(vector<int>& nums, int n)
    {
        int sum = 0;          // Stores running sum of current subarray
        int ans = INT_MAX;    // Stores minimum subarray sum found so far

        for(int i = 0; i < n; i++)
        {
            // Add current element to running sum
            sum += nums[i];

            // Update answer with the minimum sum so far
            ans = min(ans, sum);

            // If running sum becomes positive,
            // discard this subarray and start fresh
            if(sum > 0)
            {
                sum = 0;
            }
        }

        return ans;
    }

    // -------- Main Function: Maximum Circular Subarray Sum --------
    int maxSubarraySumCircular(vector<int>& nums) {

        int n = nums.size();

        // Step 1: Calculate total sum of array
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // Step 2: Find minimum subarray sum (for circular case)
        int minSum = minKadaneAlgo(nums, n);

        // Step 3: Find maximum subarray sum (normal Kadane)
        int maxSum = maxKadaneAlgo(nums, n);

        // Step 4: Circular subarray sum
        // Circular max = total sum - minimum subarray sum
        int circularSum = totalSum - minSum;

        // Step 5: Handle all-negative case
        // If all elements are negative, circularSum becomes invalid
        if(maxSum > 0)
        {
            return max(maxSum, circularSum);
        }

        // If all elements are negative, return max element
        return maxSum;
    }
};
