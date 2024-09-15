***************************************************APPROACH 1st(BRUTE FORCE)********************************************

class Solution {// TC--->O(N^3)                         SC--->O(1)
public:
    int subarraySum(vector<int>& nums, int k) {
        // Get the size of the input array 'nums'
        int n = nums.size();
        
        // Initialize the answer (number of subarrays with sum equal to 'k') to 0
        int ans = 0;
        
        // Outer loop: 'i' is the starting index of the subarray
        for(int i=0;i<n;i++)
        {
            // Middle loop: 'j' is the ending index of the subarray
            for(int j=i;j<n;j++)
            {
                // Initialize the sum of the current subarray to 0
                int sum = 0;
                
                // Inner loop: 'k' iterates from 'i' to 'j' to calculate the sum of the subarray nums[i..j]
                for(int k=i;k<=j;k++)
                {
                    // Add each element from the subarray nums[i..j] to 'sum'
                    sum += nums[k];
                }
                
                // After calculating the sum of the subarray nums[i..j], check if it equals 'k'
                if(sum == k)
                {
                    // If the sum equals 'k', increment the answer (found one valid subarray)
                    ans++;
                }
            }
        }
        
        // Return the total number of subarrays that have a sum equal to 'k'
        return ans;
    }
};

**************************************************APPROACH 2nd(BETTER APPROACH)******************************************

class Solution {// TC--->O(N^2)                                           SC--->O(1)
public:
    int subarraySum(vector<int>& nums, int k) {
        // Get the size of the input array 'nums'
        int n = nums.size();
        
        // Initialize 'ans' to store the count of subarrays with sum equal to 'k'
        int ans = 0;
        
        // Outer loop: 'i' is the starting index of the subarray
        for(int i=0;i<n;i++)
        {
            // Initialize the sum of the subarray starting from index 'i' to 0
            int sum = 0;
            
            // Inner loop: 'j' is the ending index of the subarray starting from 'i'
            for(int j=i;j<n;j++)
            {
                // Add the current element 'nums[j]' to the running sum
                sum += nums[j];
                
                // Check if the sum of the subarray nums[i..j] equals 'k'
                if(sum == k)
                {
                    // If the sum is equal to 'k', increment the answer count
                    ans++;
                }
            }
        }
        // Return the total number of subarrays whose sum equals 'k'
        return ans;
    }
};

***********************************************APPROACH 3rd(OPTIMAL APPROACH)*****************************************

class Solution {// TC--->O(N)                          SC--->O(N)
public:
    int subarraySum(vector<int>& nums, int k) {
        // Get the size of the input array 'nums'
        int n = nums.size();
        
        // Initialize the prefix sum to 0
        int prefixSum = 0;
        
         // Initialize the count of subarrays with sum equal to 'k'
        int count = 0;
        
        // HashMap to store the frequency of prefix sums
        unordered_map<int,int>ump;
        
        // Initialize the map with {0: 1} to handle cases where a subarray starting from index 0 has sum 'k'
        ump[0] = 1;
        
        // Iterate over each element of the array
        for(int i=0;i<n;i++)
        {
            // Update the prefix sum by adding the current element
            prefixSum += nums[i];
            
            // Calculate the value we need to find in the map: prefixSum - k
            int remove = prefixSum - k;
            
            // If 'remove' is found in the map, it means there exists a subarray that sums to 'k'
            if(ump.find(remove) != ump.end())
            {
                // Add the frequency of 'remove' to 'count'
                count += ump[remove];
            }
            
            // Update the frequency of the current prefix sum in the map
            ump[prefixSum]++;
        }
        
        // Return the total number of subarrays whose sum equals 'k'
        return count;
    }
};
