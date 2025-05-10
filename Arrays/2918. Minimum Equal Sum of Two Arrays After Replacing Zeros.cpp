
class Solution {// TC--->O(N + M)                          SC--->O(1)
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0;
        long long sum2 = 0;

        // Count of zeros in nums1 and nums2
        long long zero1 = 0;
        long long zero2 = 0;

        // Traverse nums1 to calculate sum and count zeros
        for(auto x : nums1) 
        {
            // Add the value to sum1
            sum1 += x;           
            if(x == 0) 
            {
                // Count zero
                zero1++;

                // Assume replacing 0 with 1, so add 1 more to sum         
                sum1 += 1;       
            }
        }

        // Traverse nums2 to calculate sum and count zeros
        for(auto x : nums2)
         {
            // Add the value to sum2
            sum2 += x;           
            if(x == 0) 
            {
                // Count zero
                zero2++;

                // Assume replacing 0 with 1, so add 1 more to sum         
                sum2 += 1;       
            }
        }

        // Now both sums assume all 0s are replaced with 1 (minimum allowed value)

        // If sum1 is still less than sum2, and we have no zero in nums1 to increase further
        if(sum1 < sum2 && zero1 == 0) 
        {
            // We can't increase sum1 anymore to match sum2
            return -1; 
        }

        // If sum2 is less than sum1, and we have no zero in nums2 to increase further
        if(sum1 > sum2 && zero2 == 0) 
        {
            // We can't increase sum2 anymore to match sum1
            return -1; 
        }

        // If it's possible to make both sums equal, return the maximum of both
        return max(sum1, sum2);
    }
};
