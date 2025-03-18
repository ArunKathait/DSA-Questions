***************************************************************APPROACH 1st(BRUTE FORCE)******************************************************************

class Solution {// TC--->O(N^2)                              SC--->O(1)
public:
    int longestNiceSubarray(vector<int>& nums) {
         // Get the size of the input array
        int n = nums.size();

         // Variable to store the maximum length of the nice subarray
        int ans = 0;
 
        // Outer loop: iterates over each starting index of the subarray
        for(int i=0;i<n;i++)
        {
            // This will keep track of the bitwise OR of the current subarray
            int mask = 0;

            // Inner loop: expands the subarray from index 'i' to 'j'
            for(int j=i;j<n;j++)
            {
                // If there is a common set bit between mask and nums[j], break
                if((mask & nums[j]) != 0)
                {
                    // Since the subarray is no longer "nice"
                    break;
                }
                
                // Update the maximum length of the nice subarray found so far
                ans = max(ans,j-i+1);

                // Include nums[j] in the current subarray by updating the mask
                mask = (mask | nums[j]);
            }
        }

        // Return the longest "nice" subarray found
        return ans;

    }
};


********************************************************APPROACH 2nd(SLIDING WINDOW + BIT MANIPULATION)*******************************************************

class Solution {// TC--->O(N)(Each element is processed at most twice)                      SC--->O(1)
public:
    int longestNiceSubarray(vector<int>& nums) {
        // Get the size of the input array
        int n = nums.size();

        // Variable to store the maximum length of the nice subarray
        int ans = 1;
        
        // Left pointer of the sliding window
        int i = 0;

        // Right pointer of the sliding window
        int j = 0;

        // Bitwise mask to track OR of elements in the current window
        int mask = 0;

        // Iterate over the array using the right pointer 'j'
        while(j < n)
        {
            // If the current number 'nums[j]' has a common set bit with 'mask',
            // then shrink the window from the left (increment 'i')
            while((mask & nums[j]) != 0)
            {
                // Remove nums[i] from the mask
                mask = (mask ^ nums[i]);

                // Move the left pointer forward
                i++;
            }
            
            // Update the maximum length of the nice subarray
            ans = max(ans,j - i + 1);

            // Include nums[j] in the current subarray by updating the mask
            mask = (mask | nums[j]);

            // Move the right pointer forward
            j++;
        }

        // Return the longest nice subarray found
        return ans;
    }
};
