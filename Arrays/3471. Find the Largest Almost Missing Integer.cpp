
class Solution {// Time  : O(n × k)                          Space : O(1)
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        // count[x] = number of subarrays of size k
        // in which x appears
        vector<int> count(51, 0);

        // Generate every possible subarray of size k
        //
        // Example:
        // nums = [1, 2, 3, 4], k = 2
        //
        // i = 0 -> [1, 2]
        // i = 1 -> [2, 3]
        // i = 2 -> [3, 4]
        for(int i = 0; i <= n - k; i++)
        {
            // seen[x] tells whether x is present
            // in the current subarray
            //
            // We use this because if x appears multiple
            // times in the same subarray, we should count
            // that subarray only ONCE.
            vector<bool> seen(51, false);

            // Traverse the current subarray
            // from index i to i + k - 1
            for(int j = i; j < i + k; j++)
            {
                // Mark nums[j] as present in this subarray
                seen[nums[j]] = true;
            }

            // Check which numbers are present
            // in the current subarray
            for(int x = 0; x < 51; x++)
            {
                if(seen[x])
                {
                    // x is present in this subarray,
                    // so count this subarray for x
                    count[x]++;
                }
            }
        }

        // Check from largest number to smallest number
        // so that the first valid number is the largest
        for(int x = 50; x >= 0; x--)
        {
            // x is "almost missing" if it appears
            // in exactly ONE subarray of size k
            if(count[x] == 1)
            {
                return x;
            }
        }

        // No number appears in exactly one subarray
        return -1;
    }
};
