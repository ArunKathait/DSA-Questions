
class Solution {// TC--->O(NLogN)                 SC--->O(1)
public:
    int partitionArray(vector<int>& nums, int k) {
        // Get the size of the input array
        int n = nums.size();  
        
        // Step 1: Sort the array in ascending order
        sort(nums.begin(), nums.end());  
        
        // Initialize minVal with the first element (smallest after sorting)
        int minVal = nums[0];  

        // Start with 1 group since we must have at least one
        int ans = 1;           

        // Step 2: Traverse the rest of the sorted array
        for(int i = 1; i < n; i++) 
        {
            // If the current number is more than 'k' units apart from the current group’s minVal
            if(nums[i] - minVal > k) 
            {
                // Start a new group
                ans++; 

                // Update minVal to the current number for the new group              
                minVal = nums[i];    
            }
        }
        // Return the total number of groups formed
        return ans;  
    }
};
