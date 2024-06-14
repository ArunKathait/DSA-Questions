*******************************************APPROACH 1st(USING SORTING)***********************************************

class Solution {// TC--->O(NlogN)                SC--->O(1)
public:
    int minIncrementForUnique(vector<int>& nums) {
        // Get the size of the input vector
        int n = nums.size();
        
        // Sort the vector in non-decreasing order
        sort(nums.begin(),nums.end());
        
        // Initialize the moves counter to 0
        int moves = 0;
        
        // Traverse the sorted array from the second element to the end
        for(int i=1;i<n;i++)
        {
            // If the current element is less than or equal to the previous element
            if(nums[i] <= nums[i-1])
            {
                // Calculate the number of increments needed to make nums[i] unique
                moves += (nums[i-1] - nums[i]) + 1;
                
                // Update nums[i] to be one more than the previous element to ensure uniqueness
                nums[i] = nums[i-1] + 1;
            }
        }
        // Return the total number of moves required
        return moves;
    }
};


************************************************APPROACH 2nd(USING ARRAY FREQUENCY)************************************

class Solution {// TC--->(maxElement + N)            SC--->O(maxElement + N)
public:
    int minIncrementForUnique(vector<int>& nums) {
        // Get the size of the input vector
        int n = nums.size();
        
        // Find the maximum element in the input vector
        int maxElement = *max_element(nums.begin(),nums.end());
        
        // Create a count array to keep track of the frequency of each element
        // The size of the count array is (maxElement + n) to handle possible increments
        vector<int>count(maxElement + n);
        
        // Populate the count array with the frequency of each element in nums
        for(auto x:nums)
        {
            count[x]++;
        }
        
        // Initialize the moves counter to 0
        int moves = 0;
        
        // Traverse the count array
        for(int i=0;i<n + maxElement;i++)
        {
            // If the count of the current element is less than or equal to 1, continue to the next element
            if(count[i] <= 1)
            {
                continue;
            }
            
            // If the count is greater than 1, calculate the number of extra occurrences
            int extra = count[i] - 1;
            
            // Set the count of the current element to 1
            count[i] = 1;
            
            // Add the extra occurrences to the next element
            count[i+1] += extra;
            
            // Increment the moves counter by the number of extra occurrences
            moves += extra;
        }
        // Return the total number of moves required
        return moves;
    }
};
