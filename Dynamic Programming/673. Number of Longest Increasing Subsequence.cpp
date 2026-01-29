
class Solution {// TC ---> O(n²)                           SC ---> O(n)
public:
    int findNumberOfLIS(vector<int>& nums) {

        int n = nums.size();

        // dp[i] = length of the Longest Increasing Subsequence (LIS) ending at index i
        vector<int> dp(n, 1);

        // count[i] = number of LIS of length dp[i] ending at index i
        vector<int> count(n, 1);

        // Try to extend LIS ending at every previous index j to current index i
        for(int i = 0; i < n; i++) 
        {
            for(int j = 0; j < i; j++) 
            {
                // We can extend only if nums[j] < nums[i]
                if(nums[j] < nums[i]) 
                {
                    // Case 1:
                    // If extending LIS from j gives the SAME length as current dp[i]
                    // then we ADD number of ways from j
                    if(dp[j] + 1 == dp[i]) 
                    {
                        count[i] += count[j];
                    }

                    // Case 2:
                    // If extending LIS from j gives a LONGER subsequence
                    // update dp[i] and reset count[i]
                    else if(dp[j] + 1 > dp[i]) 
                    {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }
                }
            }
        }

        // Find the maximum length of LIS in the array
        int maxLIS = *max_element(dp.begin(), dp.end());

        // Sum counts of all indices whose LIS length equals maxLIS
        int ans = 0;
        for(int i = 0; i < n; i++) 
        {
            if(dp[i] == maxLIS) 
            {
                ans += count[i];
            }
        }

        return ans;
    }
};
