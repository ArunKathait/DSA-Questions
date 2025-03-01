
class Solution {// TC---> O(N) + O(N) + O(N) ~ O(N)                SC--->O(1)
public:
    vector<int> applyOperations(vector<int>& nums) {
        // Get the size of the input array
        int n = nums.size();

        // Merge adjacent equal numbers
        // Start from index 1 and compare with the previous element
        for(int i=1;i<nums.size();i++)
        {
            // If two adjacent numbers are equal
            if(nums[i] == nums[i-1])
            {
                  // Double the previous number
                  nums[i-1] = nums[i-1] * 2;

                  // Set the current number to zero
                  nums[i] = 0;
            }
        }

        // Shift all non-zero elements to the front
        int index = 0;

        // Pointer to track the position to insert non-zero elements
        for(int i=0;i<nums.size();i++)
        {
            // If the element is non-zero
            if(nums[i] != 0)
            {
                // Move it to the front
                nums[index++] = nums[i];

            }
        }
        
        // Fill the remaining elements with zero
        while(index < n)
        {
            // Fill remaining positions with zero
            nums[index++] = 0;
        }
    
        // Return the modified array
        return nums;
    }
};
