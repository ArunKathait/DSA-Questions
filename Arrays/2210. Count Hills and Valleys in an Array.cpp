
class Solution {// TC--->O(N)                            SC--->O(1)
public:
    int countHillValley(vector<int>& nums) {
        // Get the number of elements in the array
        int n = nums.size();

        // 'i' is the left pointer (previous element)  
        int i = 0; 

        // 'j' is the current element being checked           
        int j = 1;            
        
        // Variable to store the count of hills and valleys
        int ans = 0;          
        
        // Loop while 'j' is inside the array
        while (j+1 < n)         
        {
            // Check if current element nums[j] is a hill or a valley
            // Hill: nums[i] < nums[j] > nums[j+1]
            // Valley: nums[i] > nums[j] < nums[j+1]
            if ((nums[i] < nums[j] && nums[j] > nums[j+1]) || 
                (nums[i] > nums[j] && nums[j] < nums[j+1]))  
            {
                // Increment count if it's a hill or valley
                ans++;

                // Move the left pointer to current position       
                i = j;       
            }
            // Move to the next element
            j++;            
        }
        // Return the total number of hills and valleys
        return ans;          
    }
};
