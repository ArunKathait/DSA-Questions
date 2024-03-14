// NOTE: It will give time limit exceed.

class Solution {//TC--->O(N^2)           SC--->O(1)
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            int sum = 0;
            for(int j=i;j<nums.size();j++)
            {
                sum += nums[j];
                if(sum == goal)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};

*******************************************************************APPROACH 2nd**************************************************
// UNORDERED MAP + PREFIX SUM
class Solution {// TC--->O(N)         SC--->O(N)
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // Define an unordered_map to store prefix sums and their frequencies
        unordered_map<int,int>ump;
        
        // Initialize the unordered_map with prefix sum 0 having frequency 1
        ump[0] = 1;
        
        // Initialize the prefix sum variable
        int prefix_sum = 0;
        
        // Initialize the variable to store the answer
        int ans = 0;
        
        // Iterate through the array
        for(int i=0;i<nums.size();i++)
        {
            // Update prefix sum by adding the current element
            prefix_sum += nums[i];
            
            // Check if there exists a prefix sum such that (prefix_sum - goal)
            // If yes, then there exists a subarray with sum equal to goal ending at the current index
            if(ump.find(prefix_sum - goal)!=ump.end())
            {
                // Increment the answer by the frequency of the prefix sum (prefix_sum - goal)
                ans += ump[prefix_sum - goal];
            }
            
            // Increment the frequency of the current prefix sum in the unordered_map
            ump[prefix_sum]++;
        }
        
        // Return the total count of subarrays with sum equal to goal
        return ans;
    }
};

***********************************************************3rd APPROACH******************************************************************
// 2 POINTERS + SLIDING WINDOW
class Solution {// TC--->O(N)           SC--->O(1)
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // Length of the input array
        int n = nums.size();
        
        // Left pointer for the sliding window
        int i = 0;
        
        // Right pointer for the sliding window
        int j = 0;
        
        // Variable to store the result
        int ans = 0;
        
        // Sum of elements in the current window
        int window_sum = 0;
        
        // Number of zeroes before the current window
        int prefix_zeroes = 0;
        
        // Loop through the array with the sliding window
        while(j<n)
        {
            // Add the element at j to the window_sum
            window_sum += nums[j];
            
            // Shrink the window until the window_sum is less than or equal to the goal
            // or until nums[i] becomes 1 (to maintain the minimum length of subarray)
            while(i < j && (window_sum > goal || nums[i] == 0))
            {
                // If nums[i] is 1, reset prefix_zeroes count to 0
                if(nums[i] == 1)
                {
                    prefix_zeroes = 0;
                }
                else
                {
                    // If nums[i] is 0, increment prefix_zeroes count
                    prefix_zeroes++;
                }
                
                // Subtract nums[i] from the window_sum and move the left pointer
                window_sum -= nums[i];
                i++;
            }
            
            // If the window_sum equals the goal, update the answer
            // Number of subarrays with sum equal to goal is (1 + prefix_zeroes)
            if(window_sum == goal)
            {
                ans += 1 + prefix_zeroes;
            }
            
            // Move the right pointer to expand the window
            j++;
        }
        
        // Return the final answer
        return ans;
    }
};
