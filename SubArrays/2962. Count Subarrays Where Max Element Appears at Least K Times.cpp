
class Solution {// TC--->O(N)                                SC--->O(1)
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Step 1: Find the maximum number in the array
        int maxNumber = *max_element(nums.begin(),nums.end());

        // To store the final count of valid subarrays
        long long ans = 0;

        // Left pointer of sliding window
        int i = 0;

         // Right pointer of sliding window
        int j = 0;
        
         // Count of maxNumber in the current window [i..j]
        int count = 0;

        // Step 2: Expand the window using right pointer 'j'
        while(j < n)
        {
            // If current element is maxNumber, increase the count
            if(nums[j] == maxNumber)
            {
                count++;
            }

            // Step 3: When count of maxNumber >= k in window [i..j],
            // we found valid subarrays starting from i to j
            while(count >= k)
            {
                // For every such i, all subarrays [i..j], [i..j+1], ..., [i..n-1] are valid
                // Add all those valid subarrays to answer
                ans += (n - j);

                // Shrink the window from the left (move i forward)
                // and update count if needed
                if(nums[i] == maxNumber)
                {
                    count--;
                }
                i++;
            }

            // Move right pointer to expand the window
            j++;
        }

        // Return the total number of valid subarrays
        return ans;
    }
};
