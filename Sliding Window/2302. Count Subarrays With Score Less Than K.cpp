
class Solution {// TC--->O(N)                            SC--->O(1)
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        // Length of input array
        int n = nums.size();
        
        // Final answer: total number of valid subarrays
        long long ans = 0;

        // Sum of the current window (subarray)
        long long sum = 0;

        // Start index of the window
        int i = 0;

        // End index of the window
        int j = 0;

        // Traverse the array with the end pointer `j`
        while(j < n)
        {
            // Add the current element to the window's sum
            sum += nums[j];

             // If current window's sum * window size is NOT valid (>= k), shrink window
            while(i <= j && sum * (j - i + 1) >= k)
            {
                // Remove nums[i] from sum
                sum -= nums[i];

                // Move the start pointer forward
                i++;
            }

            // Now, all subarrays ending at `j` and starting from i to j are valid
            // Number of such subarrays = (j - i + 1)
            ans += (j - i + 1);

            // Move end pointer to the next element
            j++;
        }

        // After traversing entire array, return total valid subarrays count
        return ans;
    }
};
