
class Solution {// TC--->O(NLogN)                         SC--->O(N)
public:
    // Modulo value to avoid integer overflow
    int M = 1e9 + 7;

    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();

        // Sort the array to use two pointers effectively
        sort(nums.begin(), nums.end());

        // Precompute powers of 2 up to n-1 using modulo
        vector<int> power(n);
        power[0] = 1;

        // power[i] = 2^i % M
        for (int i = 1; i < n; i++) 
        {
            power[i] = (power[i - 1] * 2) % M;
        }

        // Initialize two pointers for the two-pointer technique
        int l = 0;
        int r = n - 1;
        int ans = 0;

        // Traverse the array using two pointers
        while (l <= r) 
        {
            // If the sum of the smallest and largest element in current window is <= target
            if (nums[l] + nums[r] <= target) 
            {
                int diff = r - l;

                // All subsequences formed by fixing nums[l] and choosing any subset of elements between l+1 and r
                // There are 2^(r - l) such subsequences
                ans = (ans + power[diff]) % M;

                // Move the left pointer to the right
                l++;
            } 
            else 
            {
                // If sum is too big, try smaller numbers by moving right pointer to the left
                r--;
            }
        }

        return ans;
    }
};
