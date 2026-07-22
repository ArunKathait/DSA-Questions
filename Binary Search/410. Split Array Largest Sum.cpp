class Solution {// TC ---> O(n × log(sum(nums)))                            SC ---> O(1)
public:

    // This function returns how many subarrays are required
    // if the maximum allowed sum of any subarray is 'mid'.
    int isPossible(vector<int>& nums, int mid)
    {
        // Current sum of the current subarray
        int sum = 0;

        // At least one subarray will always exist
        int count = 1;

        // Traverse every element
        for(int i = 0; i < nums.size(); i++)
        {
            // If adding current element does not exceed 'mid',
            // keep adding it to the current subarray.
            if(sum + nums[i] <= mid)
            {
                sum += nums[i];
            }
            else
            {
                // Current subarray cannot hold this element
                // because its sum would become greater than 'mid'.

                // Start a new subarray.
                count++;

                // Current element becomes the first element
                // of the new subarray.
                sum = nums[i];
            }
        }

        // Return total number of subarrays formed.
        return count;
    }

    int splitArray(vector<int>& nums, int k)
    {
        int n = nums.size();

        // Minimum possible answer:
        // Largest element because every element must belong
        // to some subarray.
        int low = *max_element(nums.begin(), nums.end());

        // Maximum possible answer:
        // Entire array as one subarray.
        int high = accumulate(nums.begin(), nums.end(), 0);

        int ans = -1;

        // Binary Search on the answer
        while(low <= high)
        {
            // Candidate maximum subarray sum
            int mid = low + (high - low) / 2;

            // Find how many subarrays are needed
            // if no subarray sum exceeds 'mid'.
            int requiredSubarrays = isPossible(nums, mid);

            // If required subarrays <= k,
            // it means 'mid' is a valid answer.
            if(requiredSubarrays <= k)
            {
                // Store current answer
                ans = mid;

                // Try to minimize the maximum sum.
                high = mid - 1;
            }
            else
            {
                // More than k subarrays are required,
                // which means 'mid' is too small.

                // Increase the allowed maximum sum.
                low = mid + 1;
            }
        }

        // Smallest possible maximum subarray sum.
        return ans;
    }
};
