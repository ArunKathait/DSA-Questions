
class Solution {// TC--->O(N)                      SC--->O(1)
public:
    bool isArraySpecial(vector<int>& nums) {
        // Get the size of the input vector
        int n = nums.size();

        // Loop through the array starting from the second element (index 1)
        for(int i=1;i<n;i++)
        {
            // Compute the remainder when dividing the (i-1)th element by 2
            // This helps in checking if the number is even or odd
            int rem1 = nums[i-1]%2;

            // Compute the remainder when dividing the ith element by 2
            int rem2 = nums[i]%2;

            // If the remainder is the same for both elements, it means they are
            // either both even or both odd, which violates the "special" condition
            if(rem1 == rem2)
            {
                // Return false if two consecutive numbers have the same parity
                return false;
            }
        }
        // If no consecutive elements have the same parity, return true

        return true;
    }
};
