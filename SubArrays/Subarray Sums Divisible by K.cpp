*************************************************APPROACH 1st*********************************************************

class Solution {//TC--->O(N^3)               SC--->O(1)
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // Get the size of the input vector
        int n = nums.size();
        
        // Initialize the count of subarrays whose sum is divisible by k
        int count = 0;
        
        // Loop over each starting index of subarrays
        for(int i=0;i<n;i++)
        {
            // Loop over each ending index of subarrays starting from the current starting index
            for(int j=i;j<n;j++)
            {
                // Initialize the sum of the current subarray
                int sum = 0;
                
                // Calculate the sum of the subarray from index i to j
                for(int k=i;k<=j;k++)
                {
                    sum += nums[k];
                }
                
                // Check if the sum of the current subarray is divisible by k
                if(sum%k == 0)
                {
                    // Increment the count if the condition is met
                    count++;
                }
            }
        }
        
        // Return the final count of subarrays whose sum is divisible by k
        return count;
    }
};

**********************************************APPROACH 2nd*******************************************************

class Solution {// TC--->O(N^2)                 SC--->O(1)
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // Get the size of the input vector
        int n = nums.size();
        
        // Initialize the count of subarrays whose sum is divisible by k
        int count = 0;
        
        // Loop over each starting index of subarrays
        for(int i=0;i<n;i++)
        {
            // Initialize the sum of the current subarray starting from index i
            int sum = 0;
            
            // Loop over each ending index of subarrays starting from the current starting index
            for(int j=i;j<n;j++)
            {
                // Add the current element to the sum of the subarray
                sum += nums[j];
                
                // Check if the sum of the current subarray is divisible by k
                if(sum%k == 0)
                {
                    // Increment the count if the condition is met
                    count++;
                }
            }
        }
        // Return the final count of subarrays whose sum is divisible by k
        return count;
    }
};

******************************************APPROACH 3rd(BETTER APPROACH)********************************************

