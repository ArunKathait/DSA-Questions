
class Solution {// TC ---> O(N)                                   SC ---> O(1)
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;   // total sum of all elements
        int F = 0;     // initial rotation function F(0)

        // Step 1: Calculate total sum and F(0)
        // F(0) = 0*nums[0] + 1*nums[1] + ... + (n-1)*nums[n-1]
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            F += (i * nums[i]);
        }
        
        int ans = F;   // store max value, initialize with F(0)

        // Step 2: Use relation to compute next rotations efficiently
        // Formula:
        // F(k) = F(k-1) + sum - n * nums[n - k]
        // Instead of recalculating from scratch

        for(int k = 1; k < n; k++)
        {
            // compute next rotation value
            int newF = F + sum - n * nums[n - k];

            // update answer
            ans = max(ans, newF);

            // move forward
            F = newF;
        }

        return ans;
    }
};
